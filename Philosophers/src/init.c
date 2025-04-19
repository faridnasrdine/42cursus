#include "philosophers.h"


int allocation(t_data *philo)
{
    philo->thread_id = malloc(sizeof(pthread_t) * philo->num_philo);
    if (!philo->thread_id)
        return (1);
    philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_philo);
    if (!philo->forks)
        return (1);
    philo->philos = malloc(sizeof(t_philo) * philo->num_philo);
    if (!philo->philos)
        return (1);
    return (0);
}

int init_forks(t_data *philo)
{
    int i;

    i = 0;
    while (i < philo->num_philo)
    {
        pthread_mutex_init(&philo->forks[i], NULL);
        i++;
    }
    philo->philos[0].fork_l = &philo->forks[0];
    philo->philos[0].fork_r = &philo->forks[philo->num_philo - 1];
    i = 1;
    while (i < philo->num_philo)
    {
        philo->philos[i].fork_l = &philo->forks[i];
        philo->philos[i].fork_r = &philo->forks[i - 1];
        i++;
    }
    return (0);
}

int init_data(t_data *philo, int ac, char **av)
{
    philo->num_philo = ft_atoi(av[1]);
    philo->time_to_die = ft_atoi(av[2]);
    philo->time_to_eat = ft_atoi(av[3]);
    philo->time_to_sleep = ft_atoi(av[4]);
    if (ac == 6)
    {
        philo->num_must_eat = ft_atoi(av[5]);
    }
    else
        philo->num_must_eat = -1;
    philo->dead = 0;
    return(0);
    
}

void init_philos(t_data *philo)
{
    int i;

    i = 0;
    while (i < philo->num_philo)
    {
       philo->philos[i].id = i + 1;
       philo->philos->fork_l = &philo->forks[i];
       philo->philos->fork_r = &philo->forks[i + 1];
       philo->philos[i].eat_count = 0;
       philo->philos[i].last_meal = 0;
       philo->philos[i].start_time = philo->time_to_die;
        i++;
    }
}

int init(t_data *philo, int ac, char **av)
{
    if(init_data(philo, ac, av) != 0)
        return (0);
    if(allocation(philo) != 0)
        return (0);
    if(init_forks(philo) != 0)
        return (0);
   init_philos(philo);
    return (1);
}   