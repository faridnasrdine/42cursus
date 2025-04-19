#include "philosophers.h"
void *chek_if_dead(void *data)
{
    t_philo *philo = data;
    while(philo->data->dead == 0)
    {
        if(get_time() - philo->time_to_die >= philo->data->time_to_die)
        {
            printf("Philosopher %d is dead\n", philo->id + 1);
            philo->data->dead = 1;
            return (NULL);
        }
    }
    return (NULL);
}
    
void *routine(void *data)
{
    t_philo *philo = data;
    philo-> = philo->data->time_to_die + get_time();
    if(pthread_create(&philo->thread, NULL, &chek_if_dead, philo))
    {
        printf("Error: Failed to create thread\n");
        return (NULL);
    }
    while(philo->data->dead == 0)
    {
        pthread_mutex_lock(philo->fork_l);
        printf("Philosopher %d has taken left fork\n", philo->id + 1);
        pthread_mutex_lock(philo->fork_r);
        printf("Philosopher %d has taken right fork\n", philo->id + 1);
        printf("Philosopher %d is eating\n", philo->id + 1);
        usleep(philo->data->time_to_eat * 1000);
        pthread_mutex_unlock(philo->fork_l);
        pthread_mutex_unlock(philo->fork_r);
        printf("Philosopher %d is sleeping\n", philo->id + 1);
        usleep(philo->data->time_to_sleep * 1000);
        printf("Philosopher %d is thinking\n", philo->id + 1);
    }
}

int philo_thread(t_data *philo)
{
    int i;

    philo->start_time = get_time();
    i = 0;
    while(i < philo->num_philo)
    {
        if(pthread_create(&philo->thread_id[i], NULL, &routine, &philo->philos[i]))
        {
            printf("Error: Failed to create thread\n");
            return (1);
        }
        usleep(1);
        i++;
    }
}