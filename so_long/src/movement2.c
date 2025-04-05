/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 03:21:15 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/29 17:54:14 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_down(t_map **map)
{
	char	next_tile;

	int (old_x), old_y;
	old_x = (*map)->player_x;
	old_y = (*map)->player_y;
	if ((old_y / 64) + 1 >= (*map)->height)
		return ;
	if ((*map)->map[old_y / 64][old_x / 64] == 'E')
		mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img.exit,
			old_x, old_y);
	else
		mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img.floor,
			old_x, old_y);
	next_tile = (*map)->map[(old_y / 64) + 1][old_x / 64];
	if (next_tile == 'E' && (*map)->collect == 0)
		exit_end_free(map);
	else if (next_tile != '1')
	{
		(*map)->player_y += 64;
		print_move(map);
		if ((*map)->map[(*map)->player_y / 64][(*map)->player_x / 64] == 'C')
			coll(map);
	}
	mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img.player,
		(*map)->player_x, (*map)->player_y);
}

void	move_up(t_map **map)
{
	char	next_tile;

	int (old_x), old_y;
	old_x = (*map)->player_x;
	old_y = (*map)->player_y;
	if ((old_y / 64) - 1 < 0)
		return ;
	if ((*map)->map[old_y / 64][old_x / 64] == 'E')
		mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img.exit,
			old_x, old_y);
	else
		mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img.floor,
			old_x, old_y);
	next_tile = (*map)->map[(old_y / 64) - 1][old_x / 64];
	if (next_tile == 'E' && (*map)->collect == 0)
		exit_end_free(map);
	else if (next_tile != '1')
	{
		(*map)->player_y -= 64;
		print_move(map);
		if ((*map)->map[(*map)->player_y / 64][(*map)->player_x / 64] == 'C')
			coll(map);
	}
	mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img.player,
		(*map)->player_x, (*map)->player_y);
}
