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
	// Always lock lower numbered fork first to prevent deadlock
	if (philo->fork_l < philo->fork_r)
	{
		pthread_mutex_lock(philo->fork_l);
		if (print_message(philo, "has taken a fork"))
		{
			pthread_mutex_unlock(philo->fork_l);
			return;
		}
		pthread_mutex_lock(philo->fork_r);
		if (print_message(philo, "has taken a fork"))
		{
			pthread_mutex_unlock(philo->fork_r);
			pthread_mutex_unlock(philo->fork_l);
			return;
		}
	}
	else
	{
		pthread_mutex_lock(philo->fork_r);
		if (print_message(philo, "has taken a fork"))
		{
			pthread_mutex_unlock(philo->fork_r);
			return;
		}
		pthread_mutex_lock(philo->fork_l);
		if (print_message(philo, "has taken a fork"))
		{
			pthread_mutex_unlock(philo->fork_l);
			pthread_mutex_unlock(philo->fork_r);
			return;
		}
	}
}

void	unlock_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->fork_l);
	pthread_mutex_unlock(philo->fork_r);
}

// Updated print_message function that returns 1 if simulation should stop


