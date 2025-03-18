#include "so_long.h"

void ft_image(t_map *map, int x, int y, char *image)
{
    int img_w, img_h;
    map->img = mlx_xpm_file_to_image(map->mlx, image, &img_w, &img_h);
    if (!map->img)
        ft_error("Error: Failed to load image\n");
    mlx_put_image_to_window(map->mlx, map->mlx_win, map->img, x, y);
    mlx_destroy_image(map->mlx, map->img);
}

void put_image(char c, int x, int y, t_map *map)
{
    if (c == 'P')
    {
        map->player_x = x;
        map->player_y = y;
        ft_image(map, x, y, "player-_1_.xpm");
    }
    else if(c == '1')
        ft_image(map, x, y, "wall.xpm");
    else if(c == '0')
        ft_image(map, x, y, "floor.xpm");
    else if(c == 'C')
    {
        ft_image(map, x, y, "collectible.xpm");
        map->collect++;
    }
    else  if(c == 'E')
        ft_image(map, x, y, "door.xpm");
}