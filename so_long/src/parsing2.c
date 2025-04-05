/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:41:16 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/27 03:11:39 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elements_in_line(char *line, t_var *var, t_map *map)
{
	int	x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] == 'E')
			var->e++;
		else if (line[x] == 'P')
			var->p++;
		else if (line[x] == 'C')
			var->c++;
		else if (line[x] != '1' && line[x] != '0')
		{
			ft_free(map->map);
			ft_error("Error\nInvalid elements in map\n");
		}
		x++;
	}
}

void	check_elements(t_map *map)
{
	t_var	var;
	int		y;

	var.c = 0;
	var.y = 0;
	var.x = 0;
	var.e = 0;
	var.p = 0;
	y = ft_linelen(map->map) - 1;
	while (y >= 0)
	{
		count_elements_in_line(map->map[y], &var, map);
		y--;
	}
	if (var.p != 1 || var.c == 0 || var.e != 1)
	{
		ft_free(map->map);
		ft_error("Error\nInvalid elements in map\n");
	}
}
