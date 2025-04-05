/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:04:00 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/03 18:29:39 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_newline(char *all_line)
{
	int	i;

	i = 0;
	if (!all_line || all_line[0] == '\n' || all_line[0] == '\0')
		return (1);
	i++;
	while (all_line[i])
	{
		if (all_line[i] == '\n' && all_line[i - 1] == '\n')
			return (1);
		i++;
	}
	if (all_line[i - 1] == '\n')
		return (1);
	return (0);
}

char	**get_map(char *map)
{
	char *(line), **(fmap), *(all_line), *(tmp);
	int (fd) = open(map, O_RDONLY);
	if (fd < 0)
		ft_error("Error\nCould not open map file\n");
	all_line = ft_strdup("");
	line = get_next_line(fd);
	while (line)
	{
		tmp = ft_strjoin(all_line, line);
		free(all_line);
		all_line = tmp;
		free(line);
		line = get_next_line(fd);
	}
	if (check_newline(all_line))
	{
		free(all_line);
		ft_error("Error\nMap file is empty or empty line\n");
	}
	return ((fmap = ft_split(all_line, '\n')), free(all_line), fmap);
}
