/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:00:10 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/30 17:21:52 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_player_mini_map(t_storage *storage)
{
	storage->player->x = (int)(storage->player->posX * ((storage->info->rx / 3) / storage->info->len_x));
	storage->player->y = (int)(storage->player->posY * ((storage->info->ry / 3) / storage->info->len_y)) * storage->mlx->size_line / 4;
	*(int *)(&storage->mlx->data_img[(int)(storage->player->x + storage->player->y + 1) * 4]) = 255;
	//*(int *)(&storage->mlx->data_img[(int)(storage->player->x + storage->player->y) * 4]) = 255;
	*(int *)(&storage->mlx->data_img[(int)(storage->player->x + storage->player->y - 1) * 4]) = 255;
	*(int *)(&storage->mlx->data_img[(int)(storage->player->x + storage->player->y + (storage->mlx->size_line / 4)) * 4]) = 255;
	*(int *)(&storage->mlx->data_img[(int)(storage->player->x + storage->player->y - (storage->mlx->size_line / 4)) * 4]) = 255;
}

void	ft_player_pos_cam(t_storage *storage, t_player *player)
{
	double	oldDirX;
	double	oldPlaneX;

	if (storage->move->foward == 1)
	{
		if (storage->info->map[(int)(player->posY)][(int)(player->posX + player->dirX * player->move_speed)] != '1')
			player->posX += player->dirX * player->move_speed;
		if (storage->info->map[(int)(player->posY + player->dirY * player->move_speed)][(int)(player->posX)] != '1')
			player->posY += player->dirY * player->move_speed;
	}
	if (storage->move->retreat == 1)
	{
		if (storage->info->map[(int)(player->posY)][(int)(player->posX - player->dirX * player->move_speed)] != '1')
			player->posX -= player->dirX * player->move_speed;
		if (storage->info->map[(int)(player->posY - player->dirY * player->move_speed)][(int)(player->posX)] != '1')
			player->posY -= player->dirY * player->move_speed;
	}
	if (storage->move->left == 1)
	{
		if (storage->info->map[(int)(player->posY)][(int)(player->posX - storage->ray->planeX * player->move_speed)] != '1')
			player->posX = player->posX - storage->ray->planeX * player->move_speed;
		if (storage->info->map[(int)(player->posY - storage->ray->planeY * player->move_speed)][(int)(player->posX)] != '1')
			player->posY = player->posY - storage->ray->planeY * player->move_speed;
	}
	if (storage->move->right == 1)
	{
		if (storage->info->map[(int)(player->posY)][(int)(player->posX + storage->ray->planeX * player->move_speed)] != '1')
			player->posX = player->posX + storage->ray->planeX * player->move_speed;
		if (storage->info->map[(int)(player->posY + storage->ray->planeY * player->move_speed)][(int)(player->posX)] != '1')
			player->posY = player->posY + storage->ray->planeY * player->move_speed;
	}
	if (storage->move->turn_left == 1)
	{	
		oldDirX = player->dirX;
		player->dirX = player->dirX * cos(-player->rot_speed) - player->dirY * sin(-player->rot_speed);
		player->dirY = oldDirX * sin(-player->rot_speed) + player->dirY * cos(-player->rot_speed);
		oldPlaneX = storage->ray->planeY;
		storage->ray->planeY = storage->ray->planeY * cos(player->rot_speed) - storage->ray->planeX * sin(player->rot_speed);
		storage->ray->planeX = oldPlaneX * sin(player->rot_speed) + storage->ray->planeX * cos(player->rot_speed);	
	}
	if (storage->move->turn_right == 1)
	{	
		oldDirX = player->dirX;
		player->dirX = player->dirX * cos(player->rot_speed) - player->dirY * sin(player->rot_speed);
		player->dirY = oldDirX * sin(player->rot_speed) + player->dirY * cos(player->rot_speed);
		oldPlaneX = storage->ray->planeY;
		storage->ray->planeY = storage->ray->planeY * cos(-player->rot_speed) - storage->ray->planeX * sin(-player->rot_speed);
		storage->ray->planeX = oldPlaneX * sin(-player->rot_speed) + storage->ray->planeX * cos(-player->rot_speed);
	}
}	
