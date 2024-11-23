/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 14:52:17 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/23 14:25:35 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	check_format(va_list args, const char format)
{
	int	i;

	i = 0;
	if (format == 'c')
		i += print_char(va_arg(args, int));
	else if (format == 's')
		i += print_string(va_arg(args, char *));
	else if (format == 'd' || format == 'i')
		i += print_int(va_arg(args, int));
	else if (format == 'x' || format == 'X')
		i += print_hex(va_arg(args, unsigned int), format);
	else if (format == 'u')
		i += print_unsigned_int(va_arg(args, unsigned int));
	else if (format == 'p')
		i += print_addres(va_arg(args, void *));
	else if (format == '%')
		i += print_percent();
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;

	if (!format)
		return (-1);
	i = 0;
	len = 0;
	va_start(args, format);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			len += check_format(args, format[i + 1]);
			i++;
		}
		else
			len += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (len);
}
