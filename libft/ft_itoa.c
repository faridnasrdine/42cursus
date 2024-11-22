/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 14:15:05 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/02 11:48:34 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len_int(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	np;
	int		i;
	char	*result;

	np = n;
	i = ft_len_int(np);
	result = malloc(sizeof(char) * (i + 1));
	if (!result)
		return (NULL);
	result[i--] = '\0';
	if (np == 0)
		result[0] = '0';
	if (np < 0)
	{
		np = -np;
		result[0] = '-';
	}
	while (np > 0)
	{
		result[i] = (np % 10) + 48;
		np = np / 10;
		i--;
	}
	return (result);
}
// int main(void)
// {
// 	int n = 0;
// 	printf("%s\n", ft_itoa(n));
// }