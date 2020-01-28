/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:40:18 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/28 17:27:26 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_struct_infomap(t_info *info_map)
{
	info_map->len_map = 0;
	info_map->rx = 0;
	info_map->ry = 0;
	info_map->north_t[0] = '\0';
	info_map->south_t[0] = '\0';
	info_map->west_t[0] = '\0';
	info_map->east_t[0] = '\0';
	info_map->sprite_t[0] = '\0';
	info_map->colorf = 0;
	info_map->colorc = 0;
}

void	ft_init_struct_move(t_move *move)
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

void	ft_init_struct_player(t_player *player)
{
	player->posX = 14;
	player->posY = 2;
	player->x = 0;
	player->y = 0;
	player->dirX = 0;
	player->dirY = -1;
	player->move_speed = 0.07;
	player->rot_speed = 0.05;
}
