/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:20:45 by nafarid           #+#    #+#             */
/*   Updated: 2025/05/26 20:30:34 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	lock_forks(t_philo *philo)
{
	if (philo->fork_l < philo->fork_r)
	{
		pthread_mutex_lock(philo->fork_l);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->fork_r);
		print_message(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->fork_r);
		print_message(philo, "has taken a fork");
		pthread_mutex_lock(philo->fork_l);
		print_message(philo, "has taken a fork");
	}
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

void	eating(t_philo *philo)
{
	lock_forks(philo);
	print_message(philo, "is eating");
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->meal_lock);
	ft_usleep(philo->data->time_to_eat);
	unlock_forks(philo);
}

int	time_to_think(t_data *data)
{
	unsigned long long	think_time;

	think_time = 0;
	if (data->num_philo % 2 != 0)
	{
		think_time = (data->time_to_eat * 2) - data->time_to_sleep;
		if (think_time > 600)
		{
			think_time = 200;
			return (think_time);
		}
	}
	else
		think_time = 200;
	return (think_time);
}
