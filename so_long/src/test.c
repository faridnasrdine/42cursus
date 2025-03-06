#include "so_long.h"

int close_win(void *mlx)
{
    (void)mlx;
    exit(0);
    return 0;
}
int main()
{
    int x, y;
    void *mlx = mlx_init();
    void *mlx_win;
    void *img;
    img = mlx_xpm_file_to_image(mlx, "../player-_1_.xpm", &x, &y);
    mlx_win = mlx_new_window(mlx, 800, 400, "mlxw");
    mlx_put_image_to_window(mlx, mlx_win, img, 3 * x, 3 * y);
    mlx_hook(mlx_win, 17, 0, close_win, NULL);
    mlx_loop(mlx);
}