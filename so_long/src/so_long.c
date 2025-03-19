/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nafarid <nafarid@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 18:09:31 by nafarid           #+#    #+#             */
/*   Updated: 2025/03/10 00:01:58 by nafarid          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int key_hook(int keycode, t_map *map)
{
    int i;
    if (keycode == 100) 
        move_to_right(&map);
    else if (keycode == 97) 
        move_to_left(&map);
    else if (keycode == 119)
        move_up(&map);
    else if (keycode == 122)
        move_down(&map);
    else if (keycode == 65307)
    {
        i = 0;
        while(map->map[i])
        {
            free(map->map[i]);
            i++;
        }
        free(map->map);
        mlx_destroy_window(map->mlx, map->mlx_win);
        exit(1);
    }
    return (0);
}

int ft_exit(t_map *map)
{
    int i;

    i = 0;
    while(map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    mlx_destroy_window(map->mlx, map->mlx_win);
    exit(1);
    return 0;
}
void game_loop(t_map *map)
{
    int map_x;
    int map_y;
    int x;
    int y;
    
    y = 0;
    map_y = 0;
    while(map_y < map->height)
    {   
        x = 0;
        map_x = 0;
        while(map_x < map->width)
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
    map->collect = 0;
    map->movement = 1;
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
        mlx_hook(map.mlx_win, 2, (1L << 0), key_hook, &map);
        mlx_hook(map.mlx_win, 17, (1L << 0), ft_exit, &map);
        mlx_string_put(map.mlx, map.mlx_win, 10, 15, 0xffff, "Move : 0");
        mlx_loop(map.mlx);
    }
}