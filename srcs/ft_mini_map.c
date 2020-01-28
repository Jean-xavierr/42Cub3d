/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 16:05:20 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/28 16:20:42 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_color_wall_mini_map(t_storage *storage, int y, int x, int color)
{
	int		iy;
	int		ix;
	int		ix_max;
	int		t_x;
	int		t_y;
	int 	line;
	int		size_line;

	iy = 0;
	ix_max = 0;
	line = 0;
	t_x = (storage->info->rx / 2) / storage->info->len_x;
	t_y = (storage->info->ry / 2) / storage->info->len_y;
	size_line = storage->mlx->size_line / 4;
	line = size_line * (y * t_y);
	ix_max = (x + 1) * t_x;
	while (iy < t_y)
	{
		ix = x * t_x;
		while (ix < ix_max)
		{
			*(int *)(&storage->mlx->data_img[(line + ix) * storage->mlx->bpixel]) = color;
			ix++;
		}
		line = line + size_line;
		iy++;
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
			else if (storage->info->map[y][x] == '0')
				ft_color_wall_mini_map(storage, y, x, 16777215);
			x++;
		}
		y++;
	}
}
