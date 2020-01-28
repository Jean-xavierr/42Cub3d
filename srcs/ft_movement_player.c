/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:00:10 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/28 16:00:17 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_player_mini_map(t_storage *storage)
{
	storage->player->x = (int)(storage->player->posX * ((storage->info->rx / 2) / storage->info->len_x));
	storage->player->y = (int)(storage->player->posY * ((storage->info->ry / 2) / storage->info->len_y)) * storage->mlx->size_line / 4;
	if (storage->move->foward == 1)
		storage->player->posY -= 0.05;
	if (storage->move->retreat == 1)
		storage->player->posY += 0.05;
	if (storage->move->left == 1)
		storage->player->posX -= 0.08;
	if (storage->move->right == 1)
		storage->player->posX += 0.08;
	*(int *)(&storage->mlx->data_img[(int)(storage->player->x + storage->player->y + 1) * 4]) = 255;
	*(int *)(&storage->mlx->data_img[(int)(storage->player->x + storage->player->y - 1) * 4]) = 255;
	*(int *)(&storage->mlx->data_img[(int)(storage->player->x + storage->player->y + (storage->mlx->size_line / 4)) * 4]) = 255;
	*(int *)(&storage->mlx->data_img[(int)(storage->player->x + storage->player->y - (storage->mlx->size_line / 4)) * 4]) = 255;
}

void	ft_player_pos_cam(t_storage *storage)
{
	double	oldDirX;
	double	oldPlaneX;

	if (storage->move->foward == 1)
	{
		if (storage->info->map[(int)(storage->player->posY)][(int)(storage->player->posX + storage->player->dirX * storage->player->move_speed)] != '1')
			storage->player->posX += storage->player->dirX * storage->player->move_speed;
		if (storage->info->map[(int)(storage->player->posY - storage->player->dirY * storage->player->move_speed)][(int)(storage->player->posX)] != '1')
			storage->player->posY += storage->player->dirY * storage->player->move_speed;
	}
	if (storage->move->retreat == 1)
	{
		if (storage->info->map[(int)(storage->player->posY)][(int)(storage->player->posX - storage->player->dirX * storage->player->move_speed)] != '1')
			storage->player->posX -= storage->player->dirX * storage->player->move_speed;
		if (storage->info->map[(int)(storage->player->posY - storage->player->dirY * storage->player->move_speed)][(int)(storage->player->posX)] != '1')
			storage->player->posY -= storage->player->dirY * storage->player->move_speed;
	}
	if (storage->move->turn_left == 1)
	{
	  	oldDirX = storage->player->dirX;
		storage->player->dirX = storage->player->dirX * cos(-storage->player->rot_speed) - storage->player->dirY * sin(-storage->player->rot_speed);
		storage->player->dirY = oldDirX * sin(-storage->player->rot_speed) + storage->player->dirY * cos(-storage->player->rot_speed);
		oldPlaneX = storage->ray->planeY;
		storage->ray->planeY = storage->ray->planeY * cos(-storage->player->rot_speed) - storage->ray->planeX * sin(-storage->player->rot_speed);
		storage->ray->planeX = oldPlaneX * sin(-storage->player->rot_speed) + storage->ray->planeX * cos(-storage->player->rot_speed);		
	}
	if (storage->move->turn_right == 1)
	{
		oldDirX = storage->player->dirX;
		storage->player->dirX = storage->player->dirX * cos(storage->player->rot_speed) - storage->player->dirY * sin(storage->player->rot_speed);
		storage->player->dirY = oldDirX * sin(storage->player->rot_speed) + storage->player->dirY * cos(storage->player->rot_speed);
		oldPlaneX = storage->ray->planeY;
		storage->ray->planeY = storage->ray->planeY * cos(storage->player->rot_speed) - storage->ray->planeX * sin(storage->player->rot_speed);
		storage->ray->planeX = oldPlaneX * sin(storage->player->rot_speed) + storage->ray->planeX * cos(storage->player->rot_speed);		
	}
}	
