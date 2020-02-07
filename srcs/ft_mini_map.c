/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:05:20 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/07 15:46:34 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_color_wall_mini_map(t_storage *storage, int y, int x, int color)
{
	t_mini_map	mini_map;

	mini_map.y = 0;
	mini_map.x_max = 0;
	mini_map.line = 0;
	mini_map.t_x = (storage->info->rx / 3) / storage->info->len_x;
	mini_map.t_y = (storage->info->ry / 3) / storage->info->len_y;
	mini_map.line = storage->info->rx * (y * mini_map.t_y);
	mini_map.x_max = (x + 1) * mini_map.t_x;
	while (mini_map.y < mini_map.t_y)
	{
		mini_map.x = x * mini_map.t_x;
		while (mini_map.x < mini_map.x_max)
		{
			*(int *)(&storage->mlx->data_img[(mini_map.line + mini_map.x)
			* storage->mlx->bpixel]) = color;
			mini_map.x++;
		}
		mini_map.line += storage->info->rx;
		mini_map.y++;
	}
}

void	ft_draw_mini_map(t_storage *storage)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (storage->info->map[y])
	{
		x = 0;
		while (storage->info->map[y][x])
		{
			if (storage->info->map[y][x] == '1')
				ft_color_wall_mini_map(storage, y, x, 000000);
			else if (storage->info->map[y][x] == '0' ||
			storage->info->map[y][x] == '2')
				ft_color_wall_mini_map(storage, y, x, 16777215);
			x++;
		}
		y++;
	}
	ft_move_player_mini_map(storage);
}
