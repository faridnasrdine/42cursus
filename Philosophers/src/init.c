/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:08:39 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/20 12:08:39 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int allocation(t_data *philo)
{
    philo->thread_id = malloc(sizeof(pthread_t) * philo->num_philo);
    philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_philo);
    philo->philos = malloc(sizeof(t_philo) * philo->num_philo);
    if (!philo->thread_id || !philo->forks || !philo->philos)
        return (1);
    return (0);
}

int init_data(t_data *philo, int ac, char **av)
{
    philo->num_philo = ft_atoi(av[1]);
    philo->time_to_die = (unsigned long long)ft_atoi(av[2]);
    philo->time_to_eat = (unsigned long long)ft_atoi(av[3]);
    philo->time_to_sleep = (unsigned long long)ft_atoi(av[4]);
    if (ac == 6)
    {
        philo->num_must_eat = ft_atoi(av[5]);
    }
    else
        philo->num_must_eat = -1;
    philo->dead = 0;
    return(0);
    
}

int init_forks(t_data *philo)
{
    int i = 0;
    while (i < philo->num_philo)
        pthread_mutex_init(&philo->forks[i++], NULL);
    return 0;
}

void init_philos(t_data *philo)
{
    int i = 0;
    while (i < philo->num_philo)
    {
        philo->philos[i].id = i + 1;
        philo->philos[i].fork_l = &philo->forks[i];
        philo->philos[i].fork_r = &philo->forks[(i + 1) % philo->num_philo];
        philo->philos[i].last_meal = get_time();
        philo->philos[i].data = philo;
        i++;
    }
}

int init(t_data *philo, int ac, char **av)
{
    if (init_data(philo, ac, av) != 0)
        return (0);
    if (allocation(philo) != 0)
        return (0);
    if (init_forks(philo) != 0)
        return (0);
    pthread_mutex_init(&philo->print, NULL);
    init_philos(philo);
    return (1);
}
