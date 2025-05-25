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
    pthread_mutex_lock(&philo->data->print_lock);
    if (!simulation_stopped(philo->data))
    {
        printf("%llu %d %s\n", get_time() - philo->data->start_time, philo->id, message);
    }
    pthread_mutex_unlock(&philo->data->print_lock);
}


void set_dead(t_data *data)
{
    pthread_mutex_lock(&data->dead_lock);
    data->dead = 1;
    data->simulation_stop = 1;
    pthread_mutex_unlock(&data->dead_lock);
}

int simulation_stopped(t_data *data)
{
    pthread_mutex_lock(&data->dead_lock);
    int stopped = data->simulation_stop;
    pthread_mutex_unlock(&data->dead_lock);
    return (stopped);
}

void stop_simulation(t_data *data)
{
    pthread_mutex_lock(&data->dead_lock);
    data->simulation_stop = 1;
    pthread_mutex_unlock(&data->dead_lock);
}

void *monitor_routine(void *data)
{
    t_data *d = (t_data *)data;
    int i;
    int finished_count;

    while (!simulation_stopped(d))
    {
        i = 0;
        finished_count = 0;
        
        while (i < d->num_philo && !simulation_stopped(d))
        {
            pthread_mutex_lock(&d->philos[i].meal_lock);
            
            if ((get_time() - d->philos[i].last_meal) > d->time_to_die)
            {
                pthread_mutex_unlock(&d->philos[i].meal_lock);
                pthread_mutex_lock(&d->print_lock);
                printf("%llu %d died\n", get_time() - d->start_time, d->philos[i].id);
                pthread_mutex_unlock(&d->print_lock);
                set_dead(d);
                return (NULL);
            }
            
            if (d->philos[i].finished)
                finished_count++;
                
            pthread_mutex_unlock(&d->philos[i].meal_lock);
            i++;
        }        
        if (d->num_must_eat > 0 && finished_count == d->num_philo)
        {
            stop_simulation(d);
            return (NULL);
        }
        usleep(500); 
    }
    return (NULL);
}

void *routine(void *data)
{
    t_philo *philo = (t_philo *)data;

    if (philo->id % 2 == 0)
        usleep(philo->data->time_to_eat * 500);

    while (!simulation_stopped(philo->data))
    {
        eating(philo);        
        if (philo->data->num_must_eat > 0 && philo->eat_count >= philo->data->num_must_eat)
        {
            pthread_mutex_lock(&philo->meal_lock);
            philo->finished = 1;
            pthread_mutex_unlock(&philo->meal_lock);
        }
        if (simulation_stopped(philo->data))
            break;
        print_message(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep);
        if (simulation_stopped(philo->data))
            break;
        print_message(philo, "is thinking");        
        unsigned long long think_time = 0;
        if (philo->data->num_philo % 2 != 0)
        {
            think_time = (philo->data->time_to_eat * 2) - philo->data->time_to_sleep;
            if (think_time > 600)
                think_time = 200;
            if (think_time > 0)
                ft_usleep(think_time);
        }
        else
            usleep(100);
    }
    return (NULL);
}

int philo_thread(t_data *philo)
{
    int i = 0;

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
        pthread_join(philo->thread_id[i], NULL);
        i++;
    }
    return (0);
}
