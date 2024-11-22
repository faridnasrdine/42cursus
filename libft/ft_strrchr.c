/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 10:08:08 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/06 16:02:44 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	len;

	len = ft_strlen(s);
	while (len > 0)
	{
		if (s[len] == (char)c)
		{
			break ;
		}
		len--;
	}
	if (s[len] == (char)c)
	{
		return ((char *)s + len);
	}
	return (0);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	s[] = "helloooo";

// 	printf("%s\n", ft_strrchr(s, 'l'));
// }
