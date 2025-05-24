#include "philosophers.h"

void lock_forks(t_philo *philo)
{
    if (philo->id % 2 == 1)
    {
        pthread_mutex_lock(philo->fork_l);
        print_message(philo, "has taken a fork");
        pthread_mutex_lock(philo->fork_r);
        print_message(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(philo->fork_r);
        print_message(philo, "has taken a fork");
        pthread_mutex_lock(philo->fork_l);
        print_message(philo, "has taken a fork");
    }
}

void unlock_forks(t_philo *philo)
{
    pthread_mutex_unlock(philo->fork_l);
    pthread_mutex_unlock(philo->fork_r);
}

void eating(t_philo *philo)
{
    lock_forks(philo);
    
    pthread_mutex_lock(&philo->meal_lock);
    philo->last_meal = get_time();
    philo->eat_count++;
    pthread_mutex_unlock(&philo->meal_lock);
    
    print_message(philo, "is eating");
    ft_usleep(philo->data->time_to_eat);
    
    unlock_forks(philo);
}

