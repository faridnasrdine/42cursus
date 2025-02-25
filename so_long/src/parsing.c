/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 13:22:50 by nafarid           #+#    #+#             */
/*   Updated: 2025/02/25 18:20:37 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void check_map_is_valid(t_map *map)
{
    check_is_rec(map);
    check_is_closed(map);
    check_elements(map);
}

void check_is_rec(t_map *map)
{
    int x;
    int y;
    int height;
    int tole;

    x = 0;
    y = 0;
    height = ft_linelen(map->map);
    tole = 0;
    while (y != height)
    {
        while (map->map[y][x] != '\0')
            x++;
        y++;
        if (tole != 0)
        {
            if (tole != x)
                ft_error("Error\nMap is not rectangular\n");
        }
        else
            tole = x;
    }
}

static int check_line(char *line)
{
    int i;

    i = 0;
    while (line[i] != '\0')
    {
        if (line[i] != '1')
            return (0);
        i++;
    }
    return (1);
}

void check_is_closed(t_map *map)
{
    int i;

    i = ft_linelen(map->map) - 1;
    if (check_line(map->map[0]) == 0 || check_line(map->map[i]) == 0)
        ft_error("Error\nMap is not closed\n");
    while (i)
    {
        if (map->map[i][0] != '1' || map->map[i][ft_strlen(map->map[i]) - 1] != '1')
            ft_error("Error\nMap is not closed\n");
        i--;
    }
}

void check_elements(t_map *map)
{
    t_var var = {0, 0, 0, 0, 0};

    var.y = ft_linelen(map->map) - 1;
    while (var.y >= 0)
    {
        var.x = 0;
        while (map->map[var.y][var.x] != '\0')
        {
            if (map->map[var.y][var.x] == 'E')
                var.e++;
            else if (map->map[var.y][var.x] == 'P')
                var.p++;
            else if (map->map[var.y][var.x] == 'C')
                var.c++;
            else if (map->map[var.y][var.x] != '1' && map->map[var.y][var.x] != '0')
                ft_error("Error\nInvalid elements in map\n");
            var.x++;
        }
        var.y--;
    }
    if (var.p != 1 || var.c == 0 || var.e != 1)
        ft_error("Error\nInvalid elements in map\n");
}
