/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:08:56 by nafarid           #+#    #+#             */
/*   Updated: 2025/04/01 20:26:28 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_element
{
	void		*wall;
	void		*player;
	void		*coin;
	void		*exit;
	void		*floor;
}				t_elemnt;

typedef struct s_map
{
	void		*mlx;
	void		*mlx_win;
	t_elemnt	img;
	char		**map;
	int			width;
	int			height;
	int			player_x;
	int			player_y;
	int			collect;
	int			movement;
	int			exit;
}				t_map;

typedef struct s_var
{
	int			x;
	int			y;
	int			p;
	int			e;
	int			c;
}				t_var;

int				ft_exit(t_map *map);
void			use_img(t_map *game);
void			move_to_left(t_map **map);
void			move_up(t_map **map);
void			move_down(t_map **map);
void			move_to_right(t_map **map);
void			exit_end_free(t_map **map);
void			check_map_is_valid(t_map *map);
void			ft_error(char *str);
void			put_image(char c, int x, int y, t_map *map);
int				ft_linelen(char **str);
void			check_is_rectangular(t_map *map);
void			check_is_closed(t_map *map);
void			check_elements(t_map *map);
void			check_file_is_valide(char *file);
char			**get_map(char *map);
void			ft_free(char **str);
void			map_is_valid(t_map *map);
void			game_loop(t_map *map);
void			init_map(t_map *map);
void			coll(t_map **map);
int				key_hook(int keycode, t_map *map);
void			print_move(t_map **map);
#endif