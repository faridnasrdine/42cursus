/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 15:20:45 by nafarid           #+#    #+#             */
/*   Updated: 2025/05/25 15:51:22 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

unsigned long long get_time(void)
{
    struct timeval time;

    if(gettimeofday(&time, NULL) == -1)
        return (0);
    return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}
void print_message(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->data->print_lock);
    if (!simulation_stopped(philo->data))
    {
        printf("%llu %d %s\n", get_time() - philo->data->start_time, philo->id, message);
    }
    pthread_mutex_unlock(&philo->data->print_lock);
}


int ft_usleep(unsigned long long time)
{
    unsigned long long start;

    start = get_time();
    while ((get_time() - start) < time)
        usleep(time / 10);
    return 0;
}
