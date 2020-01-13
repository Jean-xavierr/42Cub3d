/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:42:41 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/09 15:59:37 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <mlx.h>

typedef	struct		s_mlx
{
	void			*ptr;
	void			*win;
	void			*img;
	char			*data_img;
	int				bpixel;
	int				size_line;
	int				endian;
	int				x;
	int				y;
}					t_mlx;

dd
typedef struct			s_keyinfo
{
	int					foward;
	int					retreat;
	int					left;
	int					right;
	int					turn_left;
	int					turn_right;
}						t_keyinfo

int					ft_key_management(t_mlx)
{

}

int					ft_keyrelease(int key, t_mlx *mlx)
{

}

int					ft_keypress(int key, t_mlx *mlx)
{
	if (key == 53)
		printf("esc");
	else if (key == 13)
		printf("forward");
	else if (key == 1)
		printf("retreat");
	else if (key == 0)
		printf("left");
	else if (key == 2)
		printf("right");
	else if (key == 123)
		printf("turn left");
	else if (key == 124)
		printf("turn  right");
}

int					main(void)
{
	t_mlx	mlx;
	int		i;
	
	mlx.x = 320;
	mlx.y = 420;
	i = 0;
	if ((mlx.ptr = mlx_init()) == NULL)
		return (-1);
	if ((mlx.win = mlx_new_window(mlx.ptr, 640, 480, "Cub2D")) == NULL)
		return (-1);
	mlx_hook(mlx.win, 2, 1L << 0, ft_keypress, &mlx);
	mlx_hook(mlx.win, 3, 1L << 1, ft_keyrelease, &mlx);
	//mlx_hook(mlx.win, 17, 1L << 17, ft_destroy_window, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}

//https://code.woboq.org/qt5/include/X11/X.h.html

/*	key_press (2, 0)
	key_release (3 , 0)
	mlx_hook
	mlx.img = mlx_new_image(mlx.ptr, 640, 480);		
	mlx.img = mlx_new_image(mlx.ptr, 640, 480);		
	mlx.data_img = mlx_get_data_addr(mlx.img, &mlx.bpixel, &mlx.size_line, &mlx.endian);

	printf("bpixel %d\n", mlx.bpixel);
	printf("size_line %d\n", mlx.size_line);
	mlx.bpixel = mlx.bpixel / 8;
	while (i < ((mlx.size_line / mlx.bpixel) * 480))
	{
		*(int *)&mlx.data_img[i * mlx.bpixel] = 13158655;
		i++;
	}
	mlx_put_image_to_window(mlx.ptr, mlx.win, mlx.img, 0, 0);
	mlx_destroy_image(mlx.ptr, mlx.img);*/
//	mlx_clear_window(mlx.ptr, mlx.win);

