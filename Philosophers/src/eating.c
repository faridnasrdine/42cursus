/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:20:45 by nafarid           #+#    #+#             */
/*   Updated: 2025/06/17 15:00:51 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void lock_forks(t_philo *philo)
{
    if (philo->fork_l < philo->fork_r)
    {
        pthread_mutex_lock(philo->fork_l);
        print_message(philo, TAKE_FORK);
        pthread_mutex_lock(philo->fork_r);
        print_message(philo, TAKE_FORK);
    }
    else
    {
        pthread_mutex_lock(philo->fork_r);
        print_message(philo, TAKE_FORK);
        pthread_mutex_lock(philo->fork_l);
        print_message(philo, TAKE_FORK);
    }
}

void unlock_forks(t_philo *philo)
{
    if (philo->fork_l == philo->fork_r)
        return;
    pthread_mutex_unlock(philo->fork_l);
    pthread_mutex_unlock(philo->fork_r);
}



int	philo_eat(t_philo *philo)
{
	lock_forks(philo);
	if (print_message(philo, "is eating"))
		return (unlock_forks(philo), 1);
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->meal_lock);
	if (ft_usleep(philo->data->time_to_eat, philo))
		return (unlock_forks(philo), 1);
	unlock_forks(philo);
	return (0);
}

int	philo_think(t_philo *philo)
{
	if (print_message(philo, "is thinking"))
		return (1);
	if (philo->data->num_philo % 2 != 0)
	{
		unsigned long long think_time = (philo->data->time_to_eat * 2) - philo->data->time_to_sleep;
		if (think_time > 600)
			think_time = 200;
		if (ft_usleep(think_time, philo))
			return (1);
	}
	
	return (0);
}
