/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:20:22 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/06 17:44:01 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*map1;
	unsigned int	len;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	len = ft_strlen(s);
	map1 = malloc(sizeof(char) * len + 1);
	if (map1 == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		map1[i] = f(i, s[i]);
		i++;
	}
	map1[i] = '\0';
	return (map1);
}
// char my_toupper(unsigned int i, char c)
// {
//     (void)i;
//     if (c >= 'a' && c <= 'z')
//         return c - 32;
// }
// #include <stdio.h>
// int main()
// {
//     char s[] = "hello";
//     char *result = ft_strmapi(s, my_toupper);
//     printf("%s\n", result);
// }