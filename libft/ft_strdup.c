/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 17:11:14 by nafarid           #+#    #+#             */
/*   Updated: 2024/10/25 21:14:26 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len_s;
	char	*result;
	int		i;

	i = 0;
	len_s = ft_strlen(s);
	result = malloc(sizeof(char) * len_s + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	while (s[i])
	{
		result[i] = s[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
// int	main(void)
// {
// 	char	*str;
// 	char	*result;

// 	str = "Helloworld";
// 	result = ft_strdup(str);
// 	printf("%s\n", result);
// 	return (0);
// }
