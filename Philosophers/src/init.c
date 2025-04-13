#include "philosophers.h"


int allocation(t_philo *philo)
{
    philo->thread_id = malloc(sizeof(pthread_t) * philo->num_philo);
    if (!philo->thread_id)
        return (1);
    philo->forks = malloc(sizeof(pthread_mutex_t) * philo->num_philo);
    if (!philo->forks)
        return (1);
    philo->philosopher = malloc(sizeof(t_philo) * philo->num_philo);
    if (!philo->philosopher)
        return (1);
    return (0);
}

int init_forks(t_philo *philo)
{
    int i;

    i = 0;
    while(i < philo->num_philo)
    {
        pthread_mutex_init(&philo->forks[i], NULL);
        i++;
    }
}
int init_philo(t_philo *philo, int ac, char **av)
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
    return(0);
    
}

int init(t_philo *philo, int ac, char **av)
{
    if(init_philo(philo, ac, av) != 0)
        return (0);
    if(allocation(philo) != 0)
        return (0);
    if(init_forks(philo) != 0)
        return (0);
    return (1);
}