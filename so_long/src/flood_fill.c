/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:31:25 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/03 01:36:56 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char **copy_map(char **map)
{
    int j = 0;
    int i = 0;
    char **new_map;

    while (map[j])
        j++;
    new_map = malloc(sizeof(char *) * (j + 1));
    if (!new_map)
        ft_error("Error\n");
    while (i < j)
    {
        new_map[i] = ft_strdup(map[i]);
        i++;
    }
    new_map[i] = NULL;
    return (new_map);
}

void flood_fill(char **map, int x, int y, char target, char replacement)
{
    if (x < 0 || y < 0 || map[y] == NULL || map[y][x] == '\0' || target == replacement)
        return;
    if (map[y][x] != target)
        return;
    map[y][x] = replacement;
    flood_fill(map, x + 1, y, target, replacement);
    flood_fill(map, x - 1, y, target, replacement);
    flood_fill(map, x, y + 1, target, replacement);
    flood_fill(map, x, y - 1, target, replacement);
}

int map_is_valid(char **map)
{
    char **new_map;
    int y = 0;
    int x = 0;
    int i = 0;
    int j = 0;

    new_map = copy_map(map);
    while (new_map[y] != NULL)
    {
        x = 0;
        while (new_map[y][x] != '\0')
        {
            if (new_map[y][x] == 'P')
            {
                new_map[y][x] = '0';
                flood_fill(new_map, x, y, '0', 'F');
                i = 0;
                while(new_map[i] != NULL)
                {   j = 0;
                    while(new_map[i][j] != '\0')
                    {
                        if (new_map[i][j] == '1' || new_map[i][j] == 'F')
                        {
                            ft_free(new_map);
                            return (0);
                        }
                        j++;
                    }
                    i++;
                }
                ft_free(new_map);
                return (1);
            }
            x++;
        }
        y++;
    }
    ft_free(new_map);
    return (0);
}