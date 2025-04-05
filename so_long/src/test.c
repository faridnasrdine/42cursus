#include "so_long.h"


int main()
{
    int x, y;
    void *mlx;
    mlx = mlx_init();

    void *img = mlx_xpm_file_to_image(mlx, "textures/collectible.xpm", &x, &y);
    void *win = mlx_new_window(mlx, x, y, "test");
    mlx_put_image_to_window(mlx, win, img, 0, 0);
    mlx_loop(mlx);
}