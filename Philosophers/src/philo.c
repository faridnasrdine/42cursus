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

void print_message(t_philo *philo, char *message)
{
    pthread_mutex_lock(&philo->data->print);
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
        if(get_time() > philo->die_time && philo->last_meal == 0)
            print_message(philo, "died");
        if(philo->eat_count == philo->data->num_must_eat)
        {
            pthread_mutex_lock(&philo->data->lock);
            philo->data->finish++;
            philo->eat_count++;
            pthread_mutex_unlock(&philo->data->lock);
        }
        pthread_mutex_unlock(&philo->lock);
    }
    return NULL;
}
void *routine(void *data)
{
    t_philo *philo = (t_philo *) data;

    philo->die_time = philo->data->time_to_die + get_time();
    if (pthread_create(&(philo->th1), NULL, &function, (void *)philo))
        return (NULL);
    while (!philo->data->dead)
    {
        // eating(philo);
        print_message(philo, "is thinking");
    }
    if (pthread_join(philo->th1, NULL))
        return (NULL);
    return NULL;
}


void *check_all_dead(void *data)
{
    t_philo *philo = data;
    pthread_mutex_lock(&philo->data->print);
	printf("data val: %d", philo->data->dead);
	pthread_mutex_unlock(&philo->data->print);
    while (!philo->data->dead)
    {
        pthread_mutex_lock(&philo->lock);
        if (philo->data->finish == philo->data->num_philo)
            philo->data->dead = 1;
        pthread_mutex_unlock(&philo->lock);
    }
    return NULL;
}

int philo_thread(t_data *philo)
{
    int i = 0;
    philo->start_time = get_time();
    if(philo->num_must_eat > 0)
    {
        if(pthread_create(&philo->thread_id[0], NULL, &check_all_dead, philo) != 0)
            return 1;
    }
    while (i < philo->num_philo)
    {
        if (pthread_create(&philo->thread_id[i], NULL, &routine, &philo->philos[i]) != 0)
            return 1;
        ft_usleep(1);
        i++;
    }
    i = 0;
    while(i < philo->num_philo)
    {
        if(pthread_join(philo->thread_id[i], NULL) != 0)
            return 1;
    }
    return 0;
}
