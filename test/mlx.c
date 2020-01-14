/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/09 09:42:41 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/14 11:05:40 by jereligi         ###   ########.fr       */
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
}					t_mlx;

typedef struct			s_move
{
	int					esc;
	int					foward;
	int					retreat;
	int					left;
	int					right;
	int					turn_left;
	int					turn_right;
	int					sprint;
}						t_move;

typedef struct			s_player
{
	int					x;
	int					y;
}						t_player;

int					ft_key_management(t_mlx *mlx)
{
	return (0);
}

int					ft_keyrelease(int keycode, t_move *move)
{
	printf("\nkeycode |%d| : ", keycode);
	if (keycode == 53)
		move->esc = 0;
	else if (keycode == 13)
		move->foward = 0;
	else if (keycode == 1)
		move->retreat = 0;
	else if (keycode == 0)
		move->left = 0;
	else if (keycode == 2)
		move->right = 0;
	else if (keycode == 123)
		move->turn_left = 0;
	else if (keycode == 124)
		move->turn_right = 0;
	else if (keycode == 257)
		move->sprint = 1;
	printf("0");
	return (0);
}

int					ft_keypress(int keycode, t_move *move)
{
	printf("\nkeycode |%d| : ", keycode);
	if (keycode == 53)
	{
		move->esc = 1;
		printf("esc");
	}
	else if (keycode == 13)
	{
		move->foward = 1;
		printf("forward");
	}
	else if (keycode == 1)
	{
		move->retreat = 1;
		printf("retreat");
	}
	else if (keycode == 0)
	{
		move->left = 1;
		printf("left");
	}
	else if (keycode == 2)
	{
		move->right = 1;
		printf("right");
	}
	else if (keycode == 123)
	{
		move->turn_left = 1;
		printf("turn left");
	}
	else if (keycode == 124)
	{
		move->turn_right = 1;
		printf("turn right");
	}
	else if (keycode == 257)
	{
		move->sprint = 1;
		printf ("sprint");
	}
	return (0);
}

int					ft_expose(t_mlx *mlx)
{
	int		i;
	int		n;

	i = 0;
	n = 16777215;
	mlx->img = mlx_new_image(mlx->ptr, 640, 480);
	mlx->data_img = mlx_get_data_addr(mlx->img, &mlx->bpixel, &mlx->size_line, &mlx->endian);
	mlx->bpixel = mlx->bpixel / 8;
	while (i < ((mlx->size_line / mlx->bpixel) * 480))
	{
		*(int *)&mlx->data_img[i * 4] = n;
		//n += 1;
		i++;
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0 ,0);
	return (0);	
}

void				ft_init_struct_move(t_move *move)
{
	move->esc = 0;
	move->foward = 0;
	move->retreat = 0;
	move->left = 0;
	move->right = 0;
	move->turn_left = 0;
	move->turn_right = 0;
	move->sprint = 0;
}

int					main(void)
{
	t_mlx		mlx;
	t_move		move;	
	
	ft_init_struct_move(&move);
	if ((mlx.ptr = mlx_init()) == NULL)
		return (-1);
	if ((mlx.win = mlx_new_window(mlx.ptr, 640, 480, "Cub2D")) == NULL)
		return (-1);
	mlx_hook(mlx.win, 2, 1L << 0, ft_keypress, &move);
	mlx_hook(mlx.win, 3, 1L << 1, ft_keyrelease, &move);
	mlx_hook(mlx.win, 12, 1L << 15, ft_expose, &mlx);
	//mlx_hook(mlx.win, 17, 1L << 17, ft_destroy_window, &mlx);
	mlx_loop(mlx.ptr);
	return (0);
}

//https://code.woboq.org/qt5/include/X11/X.h.html
/*
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

