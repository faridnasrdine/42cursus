/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:09:31 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/06 01:44:30 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


void game_loop(t_map *map)
{
    int map_w;
    int map_h;
    int map_x;
    int map_y;
    int x;
    int y;
    
    y = 0;
    map_y = 0;
    map_h = map->height;
    map_w = map->width;
    while(map_y < map_h)
    {   
        x = 0;
        map_x = 0;
        while(map_x < map_w)
        {
            put_image(map->map[map_y][map_x], x, y, map);
            map_x++;
            x += 64;
        }
        map_y++;
        y += 64;
    }
}
void init_map(t_map *map)
{
    map->width = ft_strlen(map->map[0]);
    map->height = ft_linelen(map->map);
    map->Exit = 0;
}
int main(int ac, char **av)
{
    t_map map;
    if(ac != 2)
        ft_error("Error\nUsage: ./so_long <map_file>\n");
    check_file_is_valide(av[1]);
    map.map = get_map(av[1]);
    if(map.map != NULL)
    {
        init_map(&map);
        check_map_is_valid(&map);
        map.mlx = mlx_init();
        map.mlx_win = mlx_new_window(map.mlx, 64 * map.width, 64 * map.height, "so-long");
        game_loop(&map);
        mlx_loop(map.mlx);
        
    }
}
