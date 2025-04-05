/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:09:31 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/02 13:15:15 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	if (map->img.player)
		mlx_destroy_image(map->mlx, map->img.player);
	if (map->img.wall)
		mlx_destroy_image(map->mlx, map->img.wall);
	if (map->img.floor)
		mlx_destroy_image(map->mlx, map->img.floor);
	if (map->img.coin)
		mlx_destroy_image(map->mlx, map->img.coin);
	if (map->img.exit)
		mlx_destroy_image(map->mlx, map->img.exit);
	mlx_destroy_window(map->mlx, map->mlx_win);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	exit(0);
	return (0);
}

int	key_hook(int keycode, t_map *map)
{
	if (keycode == 100)
		move_to_right(&map);
	else if (keycode == 97)
		move_to_left(&map);
	else if (keycode == 119)
		move_up(&map);
	else if (keycode == 115)
		move_down(&map);
	else if (keycode == 65307)
	{
		ft_exit(map);
	}
	return (0);
}

void	game_loop(t_map *map)
{
	int	map_x;
	int	map_y;
	int	x;
	int	y;

	y = 0;
	map_y = 0;
	while (map_y < map->height)
	{
		x = 0;
		map_x = 0;
		while (map_x < map->width)
		{
			put_image(map->map[map_y][map_x], x, y, map);
			map_x++;
			x += 64;
		}
		map_y++;
		y += 64;
	}
}

void	init_map(t_map *map)
{
	map->width = ft_strlen(map->map[0]);
	map->height = ft_linelen(map->map);
	map->exit = 0;
	map->collect = 0;
	map->movement = 1;
}
