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
#include <string.h>
void print_message(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->data->print);
    if (strcmp(message, "died") == 0 && philo->data->dead == 0)
    {
        printf("%llu %d %s\n", get_time() - philo->data->start_time, philo->id, message);
        philo->data->dead = 1;
    }
    if (!philo->data->dead)
    {
        printf("%llu %d %s\n", get_time() - philo->data->start_time, philo->id, message);
    }
    pthread_mutex_unlock(&philo->data->print);
}

void *function(void *data)
{
    t_philo *philo = (t_philo *)data;

    while (!philo->data->dead)
    {
        pthread_mutex_lock(&philo->lock);
        if (get_time() >= philo->die_time)
        {
            printf("[DEBUG] philo %d die_time=%llu now=%llu\n", philo->id, philo->die_time, get_time());
            print_message(philo, "died");
            pthread_mutex_unlock(&philo->lock);
            break;
        }
        pthread_mutex_unlock(&philo->lock);
        usleep(1000);
    }
    return NULL;
}

void *routine(void *data)
{
    t_philo *philo = (t_philo *) data;

    philo->die_time = get_time() + philo->data->time_to_die;
    if (pthread_create(&(philo->th1), NULL, &function, philo))
        return NULL;

    while (philo->data->dead == 0)
    {
        eating(philo);
        print_message(philo, "is thinking");
    }
    if(pthread_join(philo->th1, NULL))
        return NULL;
    return NULL;
}



void *check_all_dead(void *data)
{
    t_data *philo = (t_data *)data;

    while (!philo->dead)
    {
        pthread_mutex_lock(&philo->lock);
        if (philo->finish == philo->num_philo)
            philo->dead = 1;
        pthread_mutex_unlock(&philo->lock);
        usleep(1000);
    }
    return NULL;
}


int philo_thread(t_data *philo)
{
    int i = 0;

    philo->start_time = get_time();

    if (philo->num_must_eat > 0)
    {
        pthread_t monitor;
        if (pthread_create(&monitor, NULL, &check_all_dead, philo) != 0)
            return 1;
        pthread_detach(monitor);
    }

    while (i < philo->num_philo)
    {
        if (pthread_create(&philo->thread_id[i], NULL, &routine, &philo->philos[i]) != 0)
            return 1;
        ft_usleep(1);
        i++;
    }

    i = 0;
    while (i < philo->num_philo)
    {
        if (pthread_join(philo->thread_id[i], NULL) != 0)
            return 1;
        i++;
    }
    return 0;
}

