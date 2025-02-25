/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 10:04:59 by nafarid           #+#    #+#             */
/*   Updated: 2024/10/25 21:20:10 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*ptr;
	char		*dst;

	ptr = src;
	dst = dest;
	if (dst > ptr)
	{
		while (n--)
		{
			dst[n] = ptr[n];
		}
	}
	else
		ft_memcpy(dst, ptr, n);
	return (dst);
}
// int main()
// {
//     char p[] = "hello";
//     char d[] = "for this";
//     printf("%s\n", ft_memmove(d, p, 4));
//      char k[] = "hello";
//     char j[] = "for this";
//     printf("%s\n", memmove(j, k, 5));
// }