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
    if (!is_dead(philo->data))
    {
        printf("%llu %d %s\n", get_time() - philo->data->start_time, philo->id, message);
    }
    pthread_mutex_unlock(&philo->data->print_lock);
}

int is_dead(t_data *data)
{
    pthread_mutex_lock(&data->dead_lock);
    int dead = data->dead;
    pthread_mutex_unlock(&data->dead_lock);
    return (dead);
}

void set_dead(t_data *data)
{
    pthread_mutex_lock(&data->dead_lock);
    data->dead = 1;
    pthread_mutex_unlock(&data->dead_lock);
}

void *monitor_routine(void *data)
{
    t_data *d = (t_data *)data;
    int i;
    int finished_count;

    while (!is_dead(d))
    {
        i = 0;
        finished_count = 0;
        
        while (i < d->num_philo && !is_dead(d))
        {
            pthread_mutex_lock(&d->philos[i].meal_lock);
            
            // Check death condition: time since last meal > time_to_die
            if ((get_time() - d->philos[i].last_meal) > d->time_to_die)
            {
                pthread_mutex_unlock(&d->philos[i].meal_lock);
                pthread_mutex_lock(&d->print_lock);
                printf("%llu %d died\n", get_time() - d->start_time, d->philos[i].id);
                pthread_mutex_unlock(&d->print_lock);
                set_dead(d);
                return (NULL);
            }
            
            // Check if philosopher finished eating required amount
            if (d->philos[i].finished)
                finished_count++;
                
            pthread_mutex_unlock(&d->philos[i].meal_lock);
            i++;
        }
        
        // If all philosophers finished required meals, stop simulation
        if (d->num_must_eat > 0 && finished_count == d->num_philo)
        {
            set_dead(d); // Use dead flag to stop simulation
            return (NULL);
        }
        
        usleep(500); // Check every 0.5ms for better precision but not too aggressive
    }
    return (NULL);
}

void *routine(void *data)
{
    t_philo *philo = (t_philo *)data;

    // Stagger philosophers to prevent all starting at once
    if (philo->id % 2 == 0)
        usleep(philo->data->time_to_eat * 500);

    while (!is_dead(philo->data))
    {
        // EAT
        eating(philo);
        
        // Check if philosopher has eaten enough
        if (philo->data->num_must_eat > 0 && philo->eat_count >= philo->data->num_must_eat)
        {
            pthread_mutex_lock(&philo->meal_lock);
            philo->finished = 1;
            pthread_mutex_unlock(&philo->meal_lock);
            break;
        }
        
        if (is_dead(philo->data))
            break;
            
        // SLEEP
        print_message(philo, "is sleeping");
        ft_usleep(philo->data->time_to_sleep);
        
        if (is_dead(philo->data))
            break;
            
        // THINK
        print_message(philo, "is thinking");
        
        // Calculate thinking time to prevent starvation
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
    
    // Initialize all last_meal times with start_time
    while (i < philo->num_philo)
    {
        pthread_mutex_lock(&philo->philos[i].meal_lock);
        philo->philos[i].last_meal = philo->start_time;
        pthread_mutex_unlock(&philo->philos[i].meal_lock);
        i++;
    }

    // Create monitor thread first
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