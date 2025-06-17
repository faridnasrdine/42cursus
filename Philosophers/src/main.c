/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:59:38 by nafarid           #+#    #+#             */
/*   Updated: 2025/06/17 11:46:16 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	ft_clean(t_data *philo)
{
	if (philo->thread_id)
		free(philo->thread_id);
	if (philo->forks)
		free(philo->forks);
	if (philo->philos)
		free(philo->philos);
}

void	ft_all_clean(t_data *philo)
{
	int	i;

	i = 0;
	while (i < philo->num_philo)
	{
		pthread_mutex_destroy(&philo->philos[i].meal_lock);
		pthread_mutex_destroy(&philo->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&philo->dead_lock);
	pthread_mutex_destroy(&philo->print_lock);
	pthread_mutex_destroy(&philo->finish_lock);
	ft_clean(philo);
}

int	one_philo(t_data *philo)
{
	philo->start_time = get_time();
	printf("0 1 has taken a fork\n");
	ft_usleep(philo->time_to_die, philo->philos);
	printf("%llu 1 died\n", philo->time_to_die);
	ft_all_clean(philo);
	return (0);
}

int	main(int ac, char **av)
{
	t_data	philo;

	if (ac != 5 && ac != 6)
	{
		print_error(NUM_ARG);
		return (1);
	}
	if (!is_philo_valide(ac, av))
		return (1);
	if (!init(&philo, ac, av))
	{
		printf("Initialization failed\n");
		return (1);
	}
	if (philo.num_philo == 1)
		return (one_philo(&philo));
	if (philo_thread(&philo) == 1)
	{
		printf("Thread creation failed\n");
		return (1);
	}
	ft_all_clean(&philo);
	return (0);
}
