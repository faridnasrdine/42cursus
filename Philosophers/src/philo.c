/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 12:10:24 by nafarid           #+#    #+#             */
/*   Updated: 2025/05/26 21:23:35 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// Improved usleep that checks death during sleep


// Makes philosopher eat - returns 1 if should stop, 0 if continue
int	philo_eat(t_philo *philo)
{
	lock_forks(philo);
	
	// Print eating status
	if (print_message(philo, "is eating"))
		return (unlock_forks(philo), 1);
	
	// Update last meal time and eat count
	pthread_mutex_lock(&philo->meal_lock);
	philo->last_meal = get_time();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->meal_lock);
	
	// Sleep for eating time
	if (ft_usleep(philo->data->time_to_eat, philo))
		return (unlock_forks(philo), 1);
	
	unlock_forks(philo);
	return (0); // Eating succeeded
}

// Makes philosopher sleep - returns 1 if should stop, 0 if continue
int	philo_sleep(t_philo *philo)
{
	if (print_message(philo, "is sleeping"))
		return (1); // Stop if simulation ended
	
	if (ft_usleep(philo->data->time_to_sleep, philo))
		return (1); // Stop if died during sleep
	
	return (0);
}

// Makes philosopher think - returns 1 if should stop, 0 if continue
int	philo_think(t_philo *philo)
{
	if (print_message(philo, "is thinking"))
		return (1); // Stop if simulation ended
	
	// Optional: add thinking time for odd number of philosophers
	if (philo->data->num_philo % 2 != 0)
	{
		unsigned long long think_time = (philo->data->time_to_eat * 2) - philo->data->time_to_sleep;
		if (think_time > 600)
			think_time = 200;
		if (ft_usleep(think_time, philo))
			return (1);
	}
	
	return (0);
}

void	*routine(void *data)
{
	t_philo	*philo;
	
	philo = (t_philo *)data;
	
	// Even philosophers start by thinking to prevent immediate deadlock
	if (philo->id % 2 == 0)
	{
		ft_usleep(philo->data->time_to_eat / 2, philo);
		if (simulation_stopped(philo->data))
   			return (NULL); // Stop if simulation ended
	}
	
	while (!simulation_stopped(philo->data))
	{
		// Try to eat
		if (philo_eat(philo))
			return (NULL); // Stop if dead or simulation ended
		
		// Check if philosopher has eaten enough meals
		pthread_mutex_lock(&philo->meal_lock);
		if (philo->data->num_must_eat > 0 && philo->eat_count >= philo->data->num_must_eat)
		{
			philo->finished = 1;
			pthread_mutex_unlock(&philo->meal_lock);
			return (NULL); // This philosopher is done
		}
		pthread_mutex_unlock(&philo->meal_lock);
		
		// Sleep
		if (philo_sleep(philo))
			return (NULL);
		
		// Think
		if (philo_think(philo))
			return (NULL);
	}
	
	return (NULL);
}

// Monitor routine to check for death and completion
void	*monitor_routine(void *data)
{
	t_data	*philo_data;
	int		i;
	int		finish_count;
	
	philo_data = (t_data *)data;
	
	while (!simulation_stopped(philo_data))
	{
		i = 0;
		finish_count = 0;
		
		while (i < philo_data->num_philo && !simulation_stopped(philo_data))
		{
			pthread_mutex_lock(&philo_data->philos[i].meal_lock);
			
			// Check if philosopher died
			if ((get_time() - philo_data->philos[i].last_meal) >= philo_data->time_to_die)
			{
				pthread_mutex_unlock(&philo_data->philos[i].meal_lock);
				
				// Print death message
				pthread_mutex_lock(&philo_data->print_lock);
				if (!simulation_stopped(philo_data)) // Double check to prevent duplicate death messages
				{
					printf("%llu %d died\n", get_time() - philo_data->start_time, philo_data->philos[i].id);
				}
				pthread_mutex_unlock(&philo_data->print_lock);
				
				// Stop simulation
				stop_simulation(philo_data);
				return (NULL);
			}
			
			// Count finished philosophers
			if (philo_data->philos[i].finished)
				finish_count++;
			
			pthread_mutex_unlock(&philo_data->philos[i].meal_lock);
			i++;
		}
		
		// Check if all philosophers have eaten enough
		if (philo_data->num_must_eat > 0 && finish_count == philo_data->num_philo)
		{
			stop_simulation(philo_data);
			return (NULL);
		}
		
		usleep(1000); // Check every millisecond
	}
	
	return (NULL);
}

int	create_thread(t_data *philo)
{
	int	i;
	
	i = 0;
	while (i < philo->num_philo)
	{
		if (pthread_create(&philo->thread_id[i], NULL, &routine, &philo->philos[i]) != 0)
			return (1);
		i++;
	}
	
	// Wait for monitor thread to finish
	pthread_join(philo->monitor_thread, NULL);
	
	// Wait for all philosopher threads to finish
	i = 0;
	while (i < philo->num_philo)
	{
		if (pthread_join(philo->thread_id[i], NULL) != 0)
			return (1);
		i++;
	}
	
	return (0);
}

int	philo_thread(t_data *philo)
{
	int	i;
	
	// Set start time
	philo->start_time = get_time();
	
	// Initialize last meal time for all philosophers
	i = 0;
	while (i < philo->num_philo)
	{
		pthread_mutex_lock(&philo->philos[i].meal_lock);
		philo->philos[i].last_meal = philo->start_time;
		pthread_mutex_unlock(&philo->philos[i].meal_lock);
		i++;
	}
	
	// Create monitor thread
	if (pthread_create(&philo->monitor_thread, NULL, &monitor_routine, philo) != 0)
		return (1);
	
	// Create philosopher threads
	if (create_thread(philo) == 1)
		return (1);
	
	return (0);
}