/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:20:45 by nafarid           #+#    #+#             */
/*   Updated: 2025/06/18 09:31:59 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long	get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (0);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

int	print_message(t_philo *philo, char *message)
{
	pthread_mutex_lock(&philo->data->print_lock);
	if (simulation_stopped(philo->data))
	{
		pthread_mutex_unlock(&philo->data->print_lock);
		return (1);
	}
	printf("%llu %d %s\n", get_time() - philo->data->start_time, philo->id,
		message);
	pthread_mutex_unlock(&philo->data->print_lock);
	return (0);
}

void	print_error(char *str, char *av)
{
	if (!str)
		return ;
	printf("\033[31m%s%s\033[0m\n", str, av);
	return ;
}

int	ft_usleep(unsigned long long time, t_philo *philo)
{
	unsigned long long	start;

	start = get_time();
	while (get_time() - start < time)
	{
		if (simulation_stopped(philo->data))
			return (1);
		pthread_mutex_lock(&philo->meal_lock);
		if (get_time() - philo->last_meal >= philo->data->time_to_die)
		{
			pthread_mutex_unlock(&philo->meal_lock);
			return (1);
		}
		pthread_mutex_unlock(&philo->meal_lock);
		usleep(500);
	}
	return (0);
}
