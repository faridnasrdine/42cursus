/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utlis.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:24:48 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/01 17:22:04 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(1);
}

int	ft_linelen(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

// void filed_elements(t_map *map)
// {
//     // int x = 0;

//     // while (map->map[x] != NULL)
//     // {
//     //     free(map->map[x]);
//     //     x++;
//     // }
//     // free(map->map);
//     ft_error("Error\nInvalid elements in map\n");
// }


