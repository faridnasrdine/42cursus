/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/26 18:22:29 by nafarid           #+#    #+#             */
/*   Updated: 2025/05/26 20:55:58 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	stop_simulation(t_data *data)
{
	pthread_mutex_lock(&data->dead_lock);
	data->simulation_stop = 1;
	pthread_mutex_unlock(&data->dead_lock);
}

int	simulation_stopped(t_data *data)
{
	int	stop;

	stop = 0;
	pthread_mutex_lock(&data->dead_lock);
	stop = data->simulation_stop;
	pthread_mutex_unlock(&data->dead_lock);
	return (stop);
}
