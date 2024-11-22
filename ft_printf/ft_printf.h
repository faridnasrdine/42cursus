/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 18:58:58 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/20 19:57:52 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int	ft_printf(const char *format, ...);
int	print_hex(unsigned int hex, char format);
int	print_addres(void *ptr);
int	print_char(char c);
int	print_string(char *str);
int	print_int(int n);
int	print_percent(void);
int	print_unsigned_int(unsigned int n);
#endif
