/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:52:29 by nafarid           #+#    #+#             */
/*   Updated: 2024/11/09 18:03:30 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char const *s, char c)
{
	size_t	i;
	size_t	count;
	size_t	word;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			word = 0;
		else if (word == 0)
		{
			word = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static char	*word_copy(char const *str, int start, int finish)
{
	size_t	i;
	char	*word;

	i = 0;
	word = malloc(sizeof(char) * (finish - start + 1));
	if (!word)
		return (NULL);
	while (start < finish)
	{
		word[i++] = str[start++];
	}
	word[i] = '\0';
	return (word);
}

static char	**free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	start;
	char	**result;

	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] && s[i] != c)
			i++;
		if (start < i)
			result[j++] = word_copy(s, start, i);
		if (result[j - 1] == NULL)
			return (free_split(result));
	}
	return (result[j] = NULL, result);
}
// #include <stdio.h>
// int	main(void)
// {                  
// 	char s[] = ",,,,,,,hello, my, l,, world";
// 	char c = ',';
// 	char **result = ft_split(s, c);
// 	int i = 0;
// 	if (result == NULL)
// 	{
// 		printf("Error");
// 		return 0;
// 	}
// 	while (result[i] != NULL)
// 	{
// 		printf("Word %d: %s\n", i, result[i]);
// 		i++;
// 	}
// 	return (0);
// }
