/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 18:59:38 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/10 12:15:44 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int main(int ac, char **av)
{
    if (ac < 5 || ac > 6)
    {
        printf("Error: Invalid number of arguments. Expected 4 or 5 arguments.\n");
        return (1);
    }
    if (!is_philo_valide(ac, av))
    {
        printf("Error: Invalid arguments provided.\n");
        return (1);
    }

}