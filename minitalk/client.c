/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:13:43 by nafarid           #+#    #+#             */
/*   Updated: 2025/01/24 18:20:41 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static int	ft_atoi(char *np)
{
	int	i;
	int	sing;
	int	result;

	i = 0;
	while ((np[i] >= 9 && np[i] <= 13) || np[i] == ' ')
		i++;
	sing = 1;
	if (np[i] == '+' || np[i] == '-')
	{
		if (np[i] == '-')
			sing = -1;
		i++;
	}
	result = 0;
	while (np[i] >= '0' && np[i] <= '9')
	{
		result = (result * 10) + (np[i] - 48);
		i++;
	}
	return (sing * result);
}

void	handler(int c)
{
	(void)c;
	ft_printf("");
}

static void	ft_binary(int pid, char c)
{
	int	bit;
	bit = 0;
	while (bit < 8)
	{
		if (c >> (7 - bit) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(500);
		bit++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	signal(SIGINT, handler);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			ft_binary(pid, argv[2][i]);
			i++;
		}
	}
}
