#include "philosophers.h"

void lock_forks(t_philo *philo)
{
  
        pthread_mutex_lock(philo->fork_r);
        print_message(philo, "has taken a fork");
        pthread_mutex_lock(philo->fork_l);
        print_message(philo, "has taken a fork");

}

void unlock_forks(t_philo *philo)
{
  pthread_mutex_unlock(philo->fork_l);
  pthread_mutex_unlock(philo->fork_r);
  print_message(philo, "is sleeping");
  ft_usleep(philo->data->time_to_sleep);
}
void eating(t_philo *philo)
{
    lock_forks(philo);
    pthread_mutex_lock(&philo->lock);
    philo->last_meal = 1;
    philo->die_time = get_time() + philo->data->time_to_die;
    print_message(philo, "is eating");
    philo->eat_count++;
    ft_usleep(philo->data->time_to_eat);
    philo->last_meal = 0;
    pthread_mutex_unlock(&philo->lock);
    unlock_forks(philo);
}

