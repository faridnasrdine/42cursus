/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:33:07 by nafarid           #+#    #+#             */
/*   Updated: 2025/05/26 20:28:22 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_only_digits(char *num)
{
	int	i;

	i = 0;
	while (num[i] != '\0')
	{
		if (num[i] < '0' || num[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result);
}

int	is_philo_valide(int ac, char **av)
{
	int	i;
	int	num;

	i = 1;
	while (i < ac)
	{
		if (!is_only_digits(av[i]))
		{
			printf("Invalid argument: %s\n", av[i]);
			return (0);
		}
		num = ft_atoi(av[i]);
		if (i == 1 && (num <= 0 || num > MAX_PHILO))
		{
			printf("Invalid number philosophers: %d\n", num);
			return (0);
		}
		i++;
	}
	return (1);
}
