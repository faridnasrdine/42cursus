/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 13:05:03 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/10 14:51:15 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check(const char *st, char c)
{
	int	i;

	i = 0;
	while (st[i])
	{
		if (st[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	first;
	size_t	last;

	if (s1 == NULL || set == NULL)
		return (NULL);
	first = 0;
	last = ft_strlen(s1) - 1;
	while (check(set, s1[first]) == 1)
		first++;
	if (!s1[first])
		return (ft_strdup(""));
	while (check(set, s1[last]) == 1)
		last--;
	return (ft_substr(s1, first, last - first + 1));
}
// #include <stdio.h>
// int	main(void)
// {
// 	char s1[] = ",,,,,,,,,,,,jhklhjg,,,,,,,,,,,,,";
// 	char set[] = ",,,,,,,,";
// 	printf("%s\n", ft_strtrim(s1, set));
// }