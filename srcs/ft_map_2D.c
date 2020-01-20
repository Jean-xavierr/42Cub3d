/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:56:46 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/20 15:53:25 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_mini_map(t_storage *storage, int x, int y, int color)
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
	t_x = (storage->info->rx / 2) / storage->info->len_y;
	t_y = (storage->info->ry / 2) / storage->info->len_x;
	size_line = storage->mlx->size_line / 4;
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
			*(int *)(&storage->mlx->data_img[(line + n3) * storage->mlx->bpixel]) = color;
			n3++;
		}
		line = line + size_line;
		n2++;
	}
}

void	ft_draw_mini_map(t_storage *storage)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (storage->info->map[x])
	{
		y = 0;
		while (storage->info->map[x][y])
		{
			if (storage->info->map[x][y] == '1')
				ft_mini_map(storage, x, y, 000000);
			y++;
		}
		x++;
	}
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
	int		i;

	i = 0;
	storage->mlx->img = mlx_new_image(storage->mlx->ptr, storage->info->rx, storage->info->ry);
	storage->mlx->data_img = mlx_get_data_addr(storage->mlx->img, &storage->mlx->bpixel, &storage->mlx->size_line, &storage->mlx->endian);
	storage->mlx->bpixel = storage->mlx->bpixel / 8;
	while (i < ((storage->mlx->size_line / storage->mlx->bpixel) * storage->info->ry))
	{
		*(int *)&storage->mlx->data_img[i * storage->mlx->bpixel] = 16777215;
		i++;
	}
	ft_draw_mini_map(storage);
	if (storage->move->foward == 1)
		storage->player->posX -= 2560;
	if (storage->move->retreat == 1)
		storage->player->posX += 2560;
	if (storage->move->left == 1)
		storage->player->posY-= 5;
	if (storage->move->right == 1)
		storage->player->posY += 5;
	*(int *)(&storage->mlx->data_img[storage->player->posX + storage->player->posY]) = 93211680;
	*(int *)(&storage->mlx->data_img[storage->player->posX + 2560 + storage->player->posY]) = 93211680;
	*(int *)(&storage->mlx->data_img[storage->player->posX + storage->player->posY + 1]) = 93211680;
	*(int *)(&storage->mlx->data_img[storage->player->posX + 2560 + storage->player->posY + 1]) = 93211680;
	mlx_put_image_to_window(storage->mlx->ptr, storage->mlx->win, storage->mlx->img, 0 , 0);
	return (0);
}

int		ft_map_2D(t_info *info_map, t_mlx *mlx)
{
	t_move		move;
	t_player	player;
	t_storage	storage;

	player.posX = 2560 * 15; //(posX)
	player.posY = 17 * 200; //(posY)
	move.foward = 0;
	storage.info = info_map;
	storage.mlx = mlx;
	storage.player = &player;
	storage.move = &move;
	if ((mlx->ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if ((mlx->win = mlx_new_window(mlx->ptr, info_map->rx, info_map->ry, "Cub3d")) == NULL)
		return (printf("windows fail"));
	mlx_hook(mlx->win, KEYPRESS_EVENT, KEYPRESS_MASK, ft_keypress, &move);
	mlx_hook(mlx->win, KEYRELEASE_EVENT, KEYRELEASE_MASK, ft_keyrelease, &move);
 	mlx_loop_hook(mlx->ptr, ft_expose, &storage);
	mlx_loop(mlx->ptr);
	return (0);
}
