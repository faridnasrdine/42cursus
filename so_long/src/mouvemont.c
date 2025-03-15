#include "so_long.h"

void coll(t_map **map)
{
    int win_h;
    int win_w;
    (*map)->map[(*map)->player_y / 64][(*map)->player_x / 64] = '0';
    (*map)->img= mlx_xpm_file_to_image((*map)->mlx, "floor.xpm", &win_w, &win_h);
    mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img, (*map)->player_x, (*map)->player_y);
}
void move_to_right(t_map **map)
{
    int win_h;
    int win_w;
    (*map)->img= mlx_xpm_file_to_image((*map)->mlx, "floor.xpm", &win_w, &win_h);
    mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img, (*map)->player_x, (*map)->player_y);
    if((*map)->map[(*map)->player_y / 64][(*map)->player_x / 64] == 'C')
        coll(&(*map));
    (*map)->img= mlx_xpm_file_to_image((*map)->mlx, "player-_1_.xpm", &win_w, &win_h);
    mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img, (*map)->player_x, (*map)->player_y);
}