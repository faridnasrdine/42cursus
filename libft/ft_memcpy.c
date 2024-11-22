/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 09:45:00 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/04 21:52:27 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*dst;
	const char	*ptr;

	if (!src && !dest)
		return (NULL);
	i = 0;
	ptr = (const char *)src;
	dst = (char *)dest;
	while (i < n)
	{
		dst[i] = ptr[i];
		i++;
	}
	return (dest);
}
// #include <stdio.h>
// int main()
// {
// 	char p[] = "hello ";
// 	char d[10];
// 	printf("%s\n", ft_memcpy(d, p, 4));
// }
