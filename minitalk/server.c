/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 15:13:47 by nafarid           #+#    #+#             */
/*   Updated: 2025/01/26 11:53:09 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

static void	ft_bit(int p)
{
	static int				bit;
	static unsigned char	i;

	if (p == SIGUSR1)
		i = i | (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		write(1, &i, 1);
		bit = 0;
		i = 0;
	}
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;

	(void)argv;
	ft_printf("/* *******************************************************/\n");
	ft_printf("/*                                   :::      ::::::::   */\n");
	ft_printf("/*   Welcome To Pasquale's Server! :+:      :+:    :+:   */\n");
	ft_printf("/*                               +:+ +:+         +:+     */\n");
	ft_printf("/*   By:   farid               +#+  +:+       +#+        */\n");
	ft_printf("/*                           +#+#+#+#+#+   +#+           */\n");
	ft_printf("/*                                #+#    #+#             */\n");
	ft_printf("/*                               ###   ########          */\n");
	ft_printf("      My Server PID is %d                        \n", getpid());
	ft_printf("/* ***************************************************** */\n");
	if (argc == 1)
	{
		sa.sa_handler = ft_bit;
		sa.sa_flags = 0;
		sigaction(SIGUSR1, &sa, 0);
		sigaction(SIGUSR2, &sa, 0);
		while (1)
		{
			pause();	
		}
	}
	return (0);
}
