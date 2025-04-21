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

void *routine(void *data)
{
    t_philo *philo = data;

    if (philo->id % 2 == 0)
        usleep(100);
    while (!philo->data->dead)
    {
        pthread_mutex_lock(philo->fork_l);
        pthread_mutex_lock(&philo->data->print);
        printf("%lld %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
        pthread_mutex_unlock(&philo->data->print);
        pthread_mutex_lock(philo->fork_r);
        pthread_mutex_lock(&philo->data->print);
        printf("%lld %d has taken a fork\n", get_time() - philo->data->start_time, philo->id);
        pthread_mutex_unlock(&philo->data->print);
        pthread_mutex_lock(&philo->data->print);
        philo->last_meal = get_time();
        printf("%lld %d is eating\n", philo->last_meal - philo->data->start_time, philo->id);
        pthread_mutex_unlock(&philo->data->print);
        usleep(philo->data->time_to_eat * 1000);
        pthread_mutex_unlock(philo->fork_r);
        pthread_mutex_unlock(philo->fork_l);
        pthread_mutex_lock(&philo->data->print);
        printf("%lld %d is sleeping\n", get_time() - philo->data->start_time, philo->id);
        pthread_mutex_unlock(&philo->data->print);
        usleep(philo->data->time_to_sleep * 1000);
        pthread_mutex_lock(&philo->data->print);
        printf("%lld %d is thinking\n", get_time() - philo->data->start_time, philo->id);
        pthread_mutex_unlock(&philo->data->print);
    }
    return NULL;
}


void *check_all_dead(void *data)
{
    t_data *philo = (t_data *)data;
    while (!philo->dead)
    {
        for (int i = 0; i < philo->num_philo; i++)
        {
            if ((get_time() - philo->philos[i].last_meal) > philo->time_to_die)
            {
                pthread_mutex_lock(&philo->print);
                printf("%llu %d died\n", get_time() - philo->start_time, philo->philos[i].id);
                pthread_mutex_unlock(&philo->print);
                philo->dead = 1;
                return NULL;
            }
        }
        usleep(1000);
    }
    return NULL;
}

int philo_thread(t_data *philo)
{
    int i = 0;
    philo->start_time = get_time();
    while (i < philo->num_philo)
    {
        if (pthread_create(&philo->thread_id[i], NULL, &routine, &philo->philos[i]) != 0)
            return 1;
        pthread_detach(philo->thread_id[i]);
        i++;
    }

    pthread_t monitor;
    pthread_create(&monitor, NULL, &check_all_dead, philo);
    pthread_join(monitor, NULL);
    return 0;
}
