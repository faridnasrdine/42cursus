/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:08:56 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/02 16:33:33 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_map
{
	char	**map;
}			t_map;

typedef struct s_var
{
	int		x;
	int		y;
	int		p;
	int		e;
	int		c;
}			t_var;

void		check_map_is_valid(t_map *map);
void		ft_error(char *str);
int			ft_linelen(char **str);
void		check_is_rectangular(t_map *map);
void		check_is_closed(t_map *map);
void		check_elements(t_map *map);
void	check_file_is_valide(char *file);
char	**get_map(char *map);
void ft_free(char **str);
int  map_is_valid(char **map);
#endif