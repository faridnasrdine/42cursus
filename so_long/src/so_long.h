/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:08:56 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/09 02:22:37 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
    void    *mlx;
    void    *mlx_win;
    void    *img;
    char    **map;
    int     width;
    int     height;
    int     player_x;
    int     player_y;
    int     collect;
    int     movement;
    int     Exit;
} 			t_map;

typedef struct s_var
{
	int		x;
	int		y;
	int		p;
	int		e;
	int		c;
}			t_var;

void move_to_left(t_map **map);
void move_up(t_map **map);
void move_down(t_map **map);
void exit_end_free(t_map **map);
void		check_map_is_valid(t_map *map);
void		ft_error(char *str);
void   put_image(char c, int x, int y, t_map *map);
int			ft_linelen(char **str);
void		check_is_rectangular(t_map *map);
void		check_is_closed(t_map *map);
void		check_elements(t_map *map);
void	check_file_is_valide(char *file);
char	**get_map(char *map);
void ft_free(char **str);
void  map_is_valid(t_map *map);
void game_loop(t_map *map);
void move_to_right(t_map **map);
void print_text(t_map **map);
void ft_image(t_map *map, int x, int y, char *image);
#endif