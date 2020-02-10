/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_storage.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 10:51:34 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/10 11:01:53 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_storage(t_info *info_map, t_mlx *mlx, t_player *player,
t_storage *storage)
{
	storage->save = 0;
	storage->info = info_map;
	storage->mlx = mlx;
	storage->player = player;
	player->pos_x = storage->info->player_x + 0.5;
	player->pos_y = storage->info->player_y + 0.5;
}

void	ft_fill_storage(t_move *move, t_ray *ray, t_storage *storage)
{
	storage->move = move;
	storage->ray = ray;
}
