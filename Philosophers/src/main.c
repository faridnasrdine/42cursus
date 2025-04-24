/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:59:38 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/20 12:09:42 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
void clean(t_data *philo)
{
    int i;

    if (philo->thread_id)
        free(philo->thread_id);
    if (philo->forks)
    {
        for (i = 0; i < philo->num_philo; i++)
        {
            pthread_mutex_destroy(&philo->forks[i]);
        }
        free(philo->forks);
    }
    if (philo->philos)
    {
        for (i = 0; i < philo->num_philo; i++)
        {
            pthread_mutex_destroy(&philo->philos[i].lock);
        }
        free(philo->philos);
    }
    pthread_mutex_destroy(&philo->lock);
    pthread_mutex_destroy(&philo->print);
    pthread_mutex_destroy(&philo->print);
}
int oen_philo(t_data *philo)
{

    philo->start_time = get_time();
    if(pthread_create(&philo->thread_id[0], NULL, &routine, &philo->philos[0]))
        return 1;
    pthread_detach(philo->thread_id[0]);
    while(philo->dead == 0)
    {
        ft_usleep(0);
    }
    clean(philo);
    return (0);
}
int main(int ac, char **av)
{
    t_data philo;

    if (ac != 5 && ac != 6)
    {
        printf("Usage: ./philo num_philo time_to_die time_to_eat time_to_sleep [num_must_eat]\n");
        return (1);
    }
    if (!is_philo_valide(ac, av))
    {
        printf("Invalid arguments\n");
        return (1);
    }
    if (!init(&philo, ac, av))
    {
        printf("Initialization failed\n");
        return (1);
    }
    if(philo.num_philo == 1)
    {
        return (oen_philo(&philo));
    }
    if (philo_thread(&philo))
    {
        printf("Thread creation failed\n");
        return (1);
    }
    clean(&philo);
    return (0);
}
