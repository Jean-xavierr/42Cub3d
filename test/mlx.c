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

int					ft_key_mouve(t_mlx *mlx)
{
	write(1, "a", 1);		
	return (0);
}

int					ft_get_key(t_mlx *mlx)
{
	write(1, "b", 1);
	mlx->x++;
	mlx->y++;
	return (1);
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
	mlx_expose_hook(mlx.win, &ft_key_mouve, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}

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

