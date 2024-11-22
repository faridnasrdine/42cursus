/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unsigned_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 18:21:36 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/18 16:13:04 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbru(unsigned int n)
{
	if (n > 9)
	{
		ft_putnbru(n / 10);
		ft_putnbru(n % 10);
	}
	else
	{
		print_char(n + '0');
	}
}

int	print_unsigned_int(unsigned int n)
{
	int				i;
	unsigned int	np;

	i = 0;
	np = n;
	while (np > 0)
	{
		np /= 10;
		i++;
	}
	if (n == 0)
		i = 1;
	ft_putnbru(n);
	return (i);
}
