#include "so_long.h"

void print_text(t_map **map)
{
    char *num;
    char *text;
    int     w;
    int     h;
    num = ft_itoa((*map)->movement++);
    text = ft_strjoin("Move: ", num);

    (*map)->img = mlx_xpm_file_to_image((*map)->mlx, "wall.xpm", &w, &h);
    mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img, 0, 0);
    mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img, 64, 0);
    mlx_put_image_to_window((*map)->mlx, (*map)->mlx_win, (*map)->img, 64 * 2, 0);
    mlx_string_put((*map)->mlx, (*map)->mlx_win, 10, 15, 0xffff, text);
    printf("%s\n", num);
    free(num);
    free(text);


}