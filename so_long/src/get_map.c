/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:04:00 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/09 23:35:08 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
		if (line[0] == '\n')
		{
			free(line);
			break ;
		}
		tmp = ft_strjoin(all_line, line);
		free(all_line);
		all_line = tmp;
		free(line);
		line = get_next_line(fd);
	}
	if (all_line[0] == '\0' || all_line[ft_strlen(all_line) - 1] == '\n')
	{
		free(all_line);
		ft_error("Error\nMap file is empty or empty line\n");
	}
	return ((fmap = ft_split(all_line, '\n')), free(all_line), fmap);
}
