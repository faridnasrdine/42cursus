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
    if (philo_thread(&philo))
    {
        printf("Thread creation failed\n");
        return (1);
    }
    return (0);
}
