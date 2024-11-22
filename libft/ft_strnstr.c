/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 16:37:35 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/06 19:59:56 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (big == NULL && len == 0)
		return (0);
	if (*little == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while ((i + j) < len && big[i + j] == little[j]
			&& little[j] && big[i + j])
		{
			j++;
		}
		if (ft_strlen(little) == j)
			return ((char *)(big + i));
		i++;
	}
	return (0);
}
// #include <stdio.h>
// int	main(void)
// {
// 	const char	*big = "Hello, welcome to the world";
// 	const char	*little = "w";
// 	size_t		len;
// 	char		*result;

// 	len = 10;
// 	result = ft_strnstr(big, little, len);
// 	printf("%s \n", result);
// }
