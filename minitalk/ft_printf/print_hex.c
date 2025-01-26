/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 10:32:17 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/22 17:09:04 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	len_hex(unsigned int hex)
{
	int	len;

	len = 0;
	while (hex != 0)
	{
		hex = hex / 16;
		len++;
	}
	return (len);
}

static void	put_hex(unsigned int hex, char format)
{
	if (hex >= 16)
	{
		put_hex(hex / 16, format);
		put_hex(hex % 16, format);
	}
	else
	{
		if (hex <= 9)
			print_char(hex + 48);
		else
		{
			if (format == 'x')
				print_char(hex - 10 + 97);
			if (format == 'X')
				print_char(hex - 10 + 65);
		}
	}
}

int	print_hex(unsigned int hex, char format)
{
	if (hex == 0)
		return (write(1, "0", 1));
	else
		put_hex(hex, format);
	return (len_hex(hex));
}
