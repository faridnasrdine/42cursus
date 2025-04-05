/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 15:37:47 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/02 13:13:59 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_and_put(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i])
	{
		free(map->map[i]);
		i++;
	}
	free(map->map);
	free(map->mlx);
	ft_error("Error\nMLX initialization failed\n");
}

int	main(int ac, char **av)
{
	t_map	map;

	if (ac != 2)
		ft_error("Error\nUsage: ./so_long <map_file>\n");
	check_file_is_valide(av[1]);
	map.map = get_map(av[1]);
	if (map.map != NULL)
	{
		init_map(&map);
		check_map_is_valid(&map);
		map.mlx = mlx_init();
		if (!map.mlx)
			free_and_put(&map);
		use_img(&map);
		map.mlx_win = mlx_new_window(map.mlx, 64 * map.width, 64 * map.height,
				"so-long");
		game_loop(&map);
		mlx_hook(map.mlx_win, 2, 1L, key_hook, &map);
		mlx_hook(map.mlx_win, 17, 0, ft_exit, &map);
		mlx_loop(map.mlx);
	}
}
