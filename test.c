#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "minilibx_opengl/mlx.h"

int		main(void)
{
	void	*mlx_ptr;
	void	*mlx_win;
	int		x;
	int		y;

	if ((mlx_ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if ((mlx_win = mlx_new_window(mlx_ptr, 640, 480, "Cub3d")) == NULL)
		return (printf("windows fail"));
	y = 190;
	while (y < 290)
	{
		x = 270;
		while (x < 370)
		{
			mlx_pixel_put(mlx_ptr, mlx_win, x, y, 0x336BFF);
			x++;
		}
		y++;
	}
	mlx_loop(mlx_ptr);
	return (0);
}
