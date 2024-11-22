/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 18:00:30 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/05 12:57:02 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*result;
	size_t	substr_len;

	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start >= len_s)
		return (ft_strdup(""));
	substr_len = len;
	if (len_s - start < len)
		substr_len = len_s - start;
	result = malloc(sizeof(char) * substr_len + 1);
	if (result == NULL)
	{
		return (NULL);
	}
	ft_strlcpy(result, s + start, len + 1);
	return (result);
}
// int main()
// {
// 	char s1[] = "helloll";
// 	char *r = ft_substr(s1, 4, 9);
// 	printf("%s\n", r);
// }