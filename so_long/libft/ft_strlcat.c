/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:04:38 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/06 11:13:48 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len_dst;
	size_t	len_src;

	i = 0;
	len_src = ft_strlen(src);
	if (!dst && size == 0)
		return (len_src);
	len_dst = ft_strlen(dst);
	if (len_dst >= size)
	{
		return (len_src + size);
	}
	while (src[i] && (len_dst + i < size - 1))
	{
		dst[len_dst + i] = src[i];
		i++;
	}
	dst[len_dst + i] = '\0';
	return (len_src + len_dst);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char p[20] = "world";
// 	char d[] = "hello ";
// 	char j = ft_strlcat(d, p, 9);
// 	printf("%d\n", j);
// 	printf("%s\n", d);
// }