/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:41:56 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/25 17:56:46 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	t_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	t_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s && s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

char	*t_strjoin(char *buffer, char *line)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	j = 0;
	if (!buffer)
	{
		buffer = malloc(1);
		buffer[0] = '\0';
	}
	if (!buffer || !line)
		return (NULL);
	str = malloc(t_strlen(buffer) + t_strlen(line) + 1);
	if (str == NULL)
		return (NULL);
	while (buffer[i])
	{
		str[i] = buffer[i];
		i++;
	}
	while (line[j])
		str[i++] = line[j++];
	str[i] = '\0';
	return (free(buffer), str);
}
