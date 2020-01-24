/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_player_mini_map.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:06:47 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/24 11:19:22 by jereligi         ###   ########.fr       */
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
