/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:47:58 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/17 18:07:57 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	white_space(const char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v');
}

static size_t	count_word(char const *s)
{
	size_t	i;
	size_t	count;
	size_t	word;

	i = 0;
	word = 0;
	count = 0;
	while (s[i])
	{
		if (white_space(s[i]))
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

char	**free_split(char **split)
{
	int	i;

	if (!split)
		return (NULL);
	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

char	**ft_split(char const *s)
{
	char **(result);
	int (i), j, start;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (count_word(s) + 1));
	if (!result)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (white_space(s[i]))
			i++;
		start = i;
		while (s[i] && !white_space(s[i]))
			i++;
		if (start < i)
		{
			result[j] = word_copy(s, start, i);
			if (result[j] == NULL)
				return (free_split(result), NULL);
			j++;
		}
	}
	return (result[j] = NULL, result);
}
