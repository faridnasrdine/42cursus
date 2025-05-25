/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:10:24 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/20 12:10:24 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	simulation_stopped(t_data *data)
{
	int stop;

	stop = 0;
	pthread_mutex_lock(&data->dead_lock);
	stop = data->simulation_stop;
	pthread_mutex_unlock(&data->dead_lock);
	return (stop);
}
void *routine(void *data)
{
	t_philo *philo;

	philo = data;
	if (philo->id % 2 == 0)
		usleep(philo->data->time_to_eat * 500);
	while(!simulation_stopped(philo->data))
	{
		eating(philo);
		if(philo->data->num_must_eat > 0 && philo->eat_count >= philo->data->num_must_eat)
		{
			pthread_mutex_lock(&philo->meal_lock);
			philo->finished = 1;
			pthread_mutex_unlock(&philo->meal_lock);
		}
		// if(simulation_stopped(philo->data))
		// 	break;
		print_message(philo, SLEEP);
		ft_usleep(philo->data->time_to_sleep);
		// if(simulation_stopped(philo->data))
		// 	break;
		print_message(philo, THINK);
		ft_usleep(time_to_think(philo->data));
	}
	return (NULL);
}
void set_died(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	data->dead = 1;
	data->simulation_stop = 1;
	pthread_mutex_unlock(&data->dead_lock);
}
void stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	data->simulation_stop = 1;
	pthread_mutex_unlock(&data->dead_lock);
}
void *monitor_routine(void *data)
{
	t_data *philo;

	philo = (t_data *)data;
	int i;
	int finish_count;
	while(!simulation_stopped(philo))
	{
		i = 0;
		finish_count = 0;
		while(i < philo->num_philo && !simulation_stopped(philo))
		{
			pthread_mutex_lock(&philo->philos[i].meal_lock);
			if((get_time() - philo->philos[i].last_meal) > (philo->time_to_die))
			{
				pthread_mutex_unlock(&philo->philos[i].meal_lock);
				pthread_mutex_lock(&philo->print_lock);
				printf("%llu %d died\n", get_time() - philo->start_time, philo->philos[i].id);
				pthread_mutex_unlock(&philo->print_lock);
				set_died(philo);
			}
			if (philo->philos[i].finished)
				finish_count++;
			pthread_mutex_unlock(&philo->philos[i].meal_lock);
			i++;
		}
		if(philo->num_must_eat > 0 && finish_count == philo->num_philo)
		{
			stop_simulation(philo);
			return NULL;
		}
		usleep(500); // 0.5ms
	}
	return NULL;
}

int philo_thread(t_data *philo)
{
	int i;

	i = 0;
	philo->start_time = get_time();
	while (i < philo->num_philo)
	{
		pthread_mutex_lock(&philo->philos[i].meal_lock);
		philo->philos[i].last_meal = philo->start_time;
		pthread_mutex_unlock(&philo->philos[i].meal_lock);
		i++;
	}
	if (pthread_create(&philo->monitor_thread, NULL, &monitor_routine, philo) != 0)
		return (1);
	i = 0;
	while (i < philo->num_philo)
	{
		if (pthread_create(&philo->thread_id[i], NULL, &routine, &philo->philos[i]) != 0)
			return (1);
		i++;
	}
	pthread_join(philo->monitor_thread, NULL);
	i = 0;
	while (i < philo->num_philo)
	{
		if (pthread_join(philo->thread_id[i], NULL) != 0)
			return 1;
		i++;
	}
	return 0;
}
