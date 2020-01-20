/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:56:46 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/20 13:11:02 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_mini_map(t_info *info_map, t_mlx *mlx, int x, int y, int color)
{
	int		n2;
	int		n3;
	int		n4;
	int		t_x;
	int		t_y;
	int 	line;
	int		size_line;

	n2 = 0;
	n4 = 0;
	line = 0;
	t_x = (info_map->rx / 2) / info_map->len_y;
	t_y = (info_map->ry / 2) / info_map->len_x;
	size_line = mlx->size_line / 4;
	while (n2 < (x * t_x))
	{
		line = line + size_line;
		n2++;
	}
	n2 = 0;
	n4 = (y + 1) * t_y;
	while (n2 < t_x)
	{
		n3 = y * t_y;
		while (n3 < n4)
		{
			*(int *)(&mlx->data_img[(line + n3) * mlx->bpixel]) = color;
			n3++;
		}
		line = line + size_line;
		n2++;
	}
	
}

void	ft_draw_mini_map(t_info *info_map, t_mlx *mlx, t_player *player)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx->endian = 0;
	while (info_map->map[x])
	{
		y = 0;
		while (info_map->map[x][y])
		{
			if (info_map->map[x][y] == '1')
				ft_mini_map(info_map, mlx, x, y, 000000);
			y++;
		}
		x++;
	}
	player->dirX = 0;
/*	*(int *)(&mlx->data_img[player->posX + player->posY]) = 93211680;
	*(int *)(&mlx->data_img[player->posX + 2560 + player->posY]) = 93211680;
	*(int *)(&mlx->data_img[player->posX + player->posY + 1]) = 93211680;
	*(int *)(&mlx->data_img[player->posX + 2560 + player->posY + 1]) = 93211680;*/
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

int					ft_expose(t_storage	*storage)
{	
	*(int *)(&storage->mlx->data_img[storage->player->posX + storage->player->posY]) = 000000;
	*(int *)(&storage->mlx->data_img[storage->player->posX + 2560 + storage->player->posY]) = 000000;
	*(int *)(&storage->mlx->data_img[storage->player->posX + storage->player->posY + 1]) = 000000;
	*(int *)(&storage->mlx->data_img[storage->player->posX + 2560 + storage->player->posY + 1]) = 000000;
	printf("move player : ");
	if (storage->move->foward == 1)
	{
		printf("move foward\n");
		storage->player->posX -= 2560;
	}
	if (storage->move->retreat == 1)
	{	
		printf("move retreat\n");
		storage->player->posX += 2560;
	}
	if (storage->move->left == 1)
	{
		printf("move left\n");
		storage->player->posY-= 5;
	}
	if (storage->move->right == 1)
	{
		printf("move right\n");
		storage->player->posY += 5;
	}
	*(int *)(&storage->mlx->data_img[storage->player->posX + storage->player->posY]) = 93211680;
	*(int *)(&storage->mlx->data_img[storage->player->posX + 2560 + storage->player->posY]) = 93211680;
	*(int *)(&storage->mlx->data_img[storage->player->posX + storage->player->posY + 1]) = 93211680;
	*(int *)(&storage->mlx->data_img[storage->player->posX + 2560 + storage->player->posY + 1]) = 93211680;
	mlx_put_image_to_window(storage->mlx->ptr, storage->mlx->win, storage->mlx->img, 0 , 0);
	return (0);
}

int		ft_map_2D(t_info *info_map, t_mlx *mlx)
{
	int			i;
	t_move		move;
	t_player	player;
	t_storage	storage;

	i = 0;	
	player.posX = 2560 * 15;
	player.posY = 17 * 200;
	move.foward = 0;
	storage.info = info_map;
	storage.mlx = mlx;
	storage.player = &player;
	storage.move = &move;
	if ((mlx->ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if ((mlx->win = mlx_new_window(mlx->ptr, info_map->rx, info_map->ry, "Cub3d")) == NULL)
		return (printf("windows fail"));
	mlx->img = mlx_new_image(mlx->ptr, info_map->rx, info_map->ry);
	mlx->data_img = mlx_get_data_addr(mlx->img, &mlx->bpixel, &mlx->size_line, &mlx->endian);
	mlx->bpixel = mlx->bpixel / 8;
	printf("\nstorage test %d\n", storage.move->foward);
	printf("storage player %d\n", storage.player->posX);
	printf("size_line %d", mlx->size_line);
	while (i < ((mlx->size_line / mlx->bpixel) * info_map->ry))
	{
		*(int *)&mlx->data_img[i * mlx->bpixel] = 16777215;
		i++;
	}
	ft_draw_mini_map(info_map, mlx, &player);
	mlx_hook(mlx->win, 2, 1L << 0, ft_keypress, &move);
	mlx_hook(mlx->win, 3, 1L << 1, ft_keyrelease, &move);
 	mlx_loop_hook(mlx->ptr, ft_expose, &storage);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0 , 0);
	mlx_loop(mlx->ptr);
	return (0);
}
