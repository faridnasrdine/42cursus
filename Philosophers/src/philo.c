/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:10:24 by nafarid           #+#    #+#             */
/*   Updated: 2025/06/17 17:06:37 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	philo_sleep(t_philo *philo)
{
	if (print_message(philo, "is sleeping"))
		return (1);
	
	if (ft_usleep(philo->data->time_to_sleep, philo))
		return (1);
	
	return (0);
}

void	*routine(void *data)
{
	t_philo	*philo;
	
	philo = (t_philo *)data;
	if (philo->id % 2 == 0)
	{
		ft_usleep(philo->data->time_to_eat / 2, philo);
		if (simulation_stopped(philo->data))
   			return (NULL);
	}
	while (!simulation_stopped(philo->data))
	{
		if (philo_eat(philo))
			return (NULL);
		pthread_mutex_lock(&philo->meal_lock);
		if (philo->data->num_must_eat > 0 && philo->eat_count >= philo->data->num_must_eat)
		{
			philo->finished = 1;
			pthread_mutex_unlock(&philo->meal_lock);
			return (NULL);
		}
		pthread_mutex_unlock(&philo->meal_lock);
		if (philo_sleep(philo))
			return (NULL);
		if (philo_think(philo))
			return (NULL);
	}
	
	return (NULL);
}

int check_is_died(t_data *data, int finish_count, int *i)
{
	pthread_mutex_lock(&data->philos[*i].meal_lock);
	if ((get_time() - data->philos[*i].last_meal) >= data->time_to_die)
	{
		pthread_mutex_unlock(&data->philos[*i].meal_lock);
		pthread_mutex_lock(&data->print_lock);
		if (!simulation_stopped(data))
		{
			printf("%llu %d died\n", get_time() - data->start_time, data->philos[*i].id);
		}
		pthread_mutex_unlock(&data->print_lock);
		stop_simulation(data);
		return (1);
	}
	if (data->philos[*i].finished)
		finish_count++;
	pthread_mutex_unlock(&data->philos[*i].meal_lock);
	return finish_count;
}

void	*monitor_routine(void *data)
{
	t_data	*philo_data;
	int		i;
	int		finish_count;
	
	philo_data = (t_data *)data;
	
	while (!simulation_stopped(philo_data))
	{
		i = 0;
		finish_count = 0;
		
		while (i < philo_data->num_philo && !simulation_stopped(philo_data))
		{
			if(check_is_died(philo_data, finish_count, &i) == 1)
				return NULL;
			i++;
		}
		if (philo_data->num_must_eat > 0 && finish_count == philo_data->num_philo)
		{
			stop_simulation(philo_data);
			return (NULL);
		}
		usleep(100);
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
