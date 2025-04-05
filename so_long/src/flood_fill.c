/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:31:25 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/03 10:53:42 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(char **map)
{
	char	**new_map;

	int (i), j;
	i = 0;
	j = 0;
	while (map[j])
		j++;
	new_map = malloc(sizeof(char *) * (j + 1));
	if (!new_map)
		ft_error("Error\nMemory allocation failed\n");
	while (i < j)
	{
		new_map[i] = ft_strdup(map[i]);
		if (!new_map[i])
		{
			new_map[i] = NULL;
			ft_free(new_map);
			ft_error("Error\nMemory allocation failed\n");
		}
		i++;
	}
	new_map[i] = NULL;
	return (new_map);
}

static void	flood_fill(char **new_map, int x, int y, t_map *map)
{
	if (x < 0 || y < 0 || x >= map->width || y >= map->height)
		return ;
	if (new_map[y][x] == '1' || new_map[y][x] == 'S')
		return ;
	if (new_map[y][x] == 'E')
		map->exit++;
	new_map[y][x] = 'S';
	flood_fill(new_map, x + 1, y, map);
	flood_fill(new_map, x - 1, y, map);
	flood_fill(new_map, x, y + 1, map);
	flood_fill(new_map, x, y - 1, map);
}

static int	check_all_col(char **new_map, t_map *map)
{
	int	x;
	int	y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (new_map[y][x] == 'C')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}

void	find_start_position(t_map *map, int *start_x, int *start_y)
{
	int (found), x, y;
	found = 0;
	*start_x = 0;
	*start_y = 0;
	y = 1;
	while (y < map->height - 1 && !found)
	{
		x = 1;
		while (x < map->width - 1)
		{
			if (map->map[y][x] == 'P')
			{
				found = 1;
				*start_x = x;
				*start_y = y;
				break ;
			}
			x++;
		}
		if (!found)
			y++;
	}
	if (!found)
		ft_error("Error\nInvalid map! No starting position 'P' found\n");
}

void	map_is_valid(t_map *map)
{
	int		start_x;
	int		start_y;
	char	**new_map;

	find_start_position(map, &start_x, &start_y);
	new_map = copy_map(map->map);
	flood_fill(new_map, start_x, start_y, map);
	if (check_all_col(new_map, map))
	{
		ft_free(new_map);
		ft_free(map->map);
		ft_error("Error\nInvalid map! Collectibles are not accessible!\n");
	}
	ft_free(new_map);
	if (map->exit != 1)
	{
		ft_free(map->map);
		ft_error("Error\nInvalid map! No exit or multiple exits\n");
	}
}
