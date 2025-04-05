/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_image.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/26 21:40:08 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/01 20:23:27 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_image(t_map *map, int x, int y, void *img)
{
	mlx_put_image_to_window(map->mlx, map->mlx_win, img, x, y);
}

void	put_image(char c, int x, int y, t_map *map)
{
	if (c == 'P')
	{
		map->player_x = x;
		map->player_y = y;
		ft_image(map, x, y, map->img.player);
	}
	else if (c == '1')
		ft_image(map, x, y, map->img.wall);
	else if (c == '0')
		ft_image(map, x, y, map->img.floor);
	else if (c == 'C')
	{
		ft_image(map, x, y, map->img.coin);
		map->collect++;
	}
	else if (c == 'E')
		ft_image(map, x, y, map->img.exit);
}

static void	free_xpm(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	if (map->img.coin)
		mlx_destroy_image(map->mlx, map->img.coin);
	if (map->img.wall)
		mlx_destroy_image(map->mlx, map->img.wall);
	if (map->img.floor)
		mlx_destroy_image(map->mlx, map->img.floor);
	if (map->img.player)
		mlx_destroy_image(map->mlx, map->img.player);
	if (map->img.exit)
		mlx_destroy_image(map->mlx, map->img.exit);
	mlx_destroy_display(map->mlx);
	free(map->mlx);
	ft_error("Error\nUnable to load textures or resources.\n");
}

void	use_img(t_map *game)
{
	int	w;
	int	h;

	game->img.coin = mlx_xpm_file_to_image(game->mlx,
			"textures/collectible.xpm", &w, &h);
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", &w,
			&h);
	game->img.floor = mlx_xpm_file_to_image(game->mlx, "textures/floor.xpm", &w,
			&h);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			&w, &h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "textures/door.xpm", &w,
			&h);
	if (!game->img.player || !game->img.exit || !game->img.coin
		|| !game->img.floor || !game->img.wall)
	{
		free_xpm(game);
	}
}
