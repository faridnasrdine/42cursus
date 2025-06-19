/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/06 20:33:07 by nafarid           #+#    #+#             */
/*   Updated: 2025/06/19 14:26:47 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	is_only_digits(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-' || num[0] == '+')
		i++;
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
	int		i;
	long	result;

	i = 0;
	result = 0;
	while (str[i])
	{
		result = (result * 10) + (str[i] - '0');
		if (result > INT_MAX)
		{
			print_error("Integer overflow: ", str);
			return (-1);
		}
		i++;
	}
	return ((int)result);
}

int	is_arg_valid(int index, int num, char *av)
{
	if (index == 1 && (num <= 0))
	{
		print_error(NUM_P, av);
		return (1);
	}
	else if (index == 5 && (num < 0 || num > INT_MAX))
	{
		print_error(MUST_E, av);
		return (1);
	}
	else if (index != 1 && index != 5 && (num < 1 || num > INT_MAX))
	{
		print_error(NUM_T, av);
		return (1);
	}
	return (0);
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
			print_error("Invalid argument: ", av[i]);
			return (1);
		}
		num = ft_atoi(av[i]);
		if (num == -1)
			return (1);
		if (is_arg_valid(i, num, av[i]) == 1)
			return (1);
		i++;
	}
	return (0);
}
