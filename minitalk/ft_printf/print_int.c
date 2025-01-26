/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:19:18 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/18 14:54:03 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		print_char('-');
		print_char('2');
		ft_putnbr(147483648);
	}
	else if (n < 0)
	{
		print_char('-');
		ft_putnbr(-n);
	}
	else if (n > 9)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
	{
		print_char(n + '0');
	}
}

int	print_int(int n)
{
	int	i;
	int	np;

	i = 0;
	np = n;
	if (n == -2147483648)
	{
		ft_putnbr(n);
		return (11);
	}
	if (n < 0)
	{
		np = -n;
		i++;
	}
	while (np > 0)
	{
		np /= 10;
		i++;
	}
	if (n == 0)
		i = 1;
	ft_putnbr(n);
	return (i);
}
