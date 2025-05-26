/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:10:24 by nafarid           #+#    #+#             */
/*   Updated: 2025/05/26 21:23:35 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*routine(void *data)
{
	t_philo	*philo;

	philo = data;
	if (philo->id % 2 == 0)
		print_message(philo, THINK);
	while (!simulation_stopped(philo->data))
	{
		eating(philo);
		if (philo->data->num_must_eat > 0
			&& philo->eat_count >= philo->data->num_must_eat)
		{
			pthread_mutex_lock(&philo->meal_lock);
			philo->finished = 1;
			pthread_mutex_unlock(&philo->meal_lock);
		}
		if (simulation_stopped(philo->data))
			break ;
		print_message(philo, SLEEP);
		ft_usleep(philo->data->time_to_sleep);
		if (simulation_stopped(philo->data))
			break ;
		print_message(philo, THINK);
	}
	return (NULL);
}

void	check_if_died(t_data *philo, int i)
{
	if ((get_time()
			- philo->philos[i].last_meal) > (philo->time_to_die))
	{
		pthread_mutex_unlock(&philo->philos[i].meal_lock);
		pthread_mutex_lock(&philo->print_lock);
		printf("%llu %d died\n", get_time() - philo->start_time,
			philo->philos[i].id);
		pthread_mutex_unlock(&philo->print_lock);
		pthread_mutex_lock(&philo->dead_lock);
		philo->dead = 1;
		philo->simulation_stop = 1;
		pthread_mutex_unlock(&philo->dead_lock);
	}
}

void	*monitor_routine(void *data)
{
	t_data	*philo;

	int (finish_count), i;
	philo = (t_data *)data;
	while (!simulation_stopped(philo))
	{
		i = 0;
		finish_count = 0;
		while (i < philo->num_philo && !simulation_stopped(philo))
		{
			pthread_mutex_lock(&philo->philos[i].meal_lock);
			check_if_died(philo, i);
			if (philo->philos[i].finished)
				finish_count++;
			pthread_mutex_unlock(&philo->philos[i].meal_lock);
			i++;
		}
		if (philo->num_must_eat > 0 && finish_count == philo->num_philo)
		{
			stop_simulation(philo);
			return (NULL);
		}
		usleep(500);
	}
	return (NULL);
}

int	create_thread(t_data *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_philo)
	{
		if (pthread_create(&philo->thread_id[i], NULL, &routine,
				&philo->philos[i]) != 0)
			return (1);
		i++;
	}
	pthread_join(philo->monitor_thread, NULL);
	i = 0;
	while (i < philo->num_philo)
	{
		if (pthread_join(philo->thread_id[i], NULL) != 0)
			return (1);
		i++;
	}
	return (0);
}

int	philo_thread(t_data *philo)
{
	int	i;

	i = 0;
	philo->start_time = get_time();
	while (i < philo->num_philo)
	{
		pthread_mutex_lock(&philo->philos[i].meal_lock);
		philo->philos[i].last_meal = philo->start_time;
		pthread_mutex_unlock(&philo->philos[i].meal_lock);
		i++;
	}
	if (pthread_create(&philo->monitor_thread, NULL, &monitor_routine,
			philo) != 0)
		return (1);
	if (create_thread(philo) == 1)
		return (1);
	return (0);
}
