/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:22:50 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/01 20:26:24 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map_is_valid(t_map *map)
{
	check_is_rectangular(map);
	check_is_closed(map);
	check_elements(map);
	map_is_valid(map);
}

void	check_is_rectangular(t_map *map)
{
	int (x), y, tole, height;
	x = 0;
	y = 0;
	height = ft_linelen(map->map);
	tole = -1;
	while (y < height)
	{
		x = 0;
		while (map->map[y][x] != '\0')
			x++;
		if (tole != -1)
		{
			if (tole != x)
			{
				ft_free(map->map);
				ft_error("Error\nMap is not rectangular\n");
				return ;
			}
		}
		else
			tole = x;
		y++;
	}
}

static int	check_line(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

void	check_is_closed(t_map *map)
{
	int	i;

	i = ft_linelen(map->map) - 1;
	if (check_line(map->map[0]) == 0 || check_line(map->map[i]) == 0)
	{
		ft_free(map->map);
		ft_error("Error\nMap is not closed\n");
	}
	while (i)
	{
		if (map->map[i][0] != '1' || map->map[i][ft_strlen(map->map[i])
			- 1] != '1')
		{
			ft_free(map->map);
			ft_error("Error\nMap is not closed\n");
		}
		i--;
	}
}
