/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:10:39 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/07 16:17:13 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_south_north(t_storage *storage, int drawstart,
int drawend, int x)
{
	if (storage->ray->raydir_y >= 0)
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * storage->
			mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16724530;
			drawstart++;
		}
	}
	else
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * storage->
			mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16753920;
			drawstart++;
		}
	}
}

void	ft_draw_east_west(t_storage *storage, int drawstart,
int drawend, int x)
{
	if (storage->ray->raydir_x >= 0)
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * storage->
			mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 3333140;
			drawstart++;
		}
	}
	else
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * storage->
			mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 65535;
			drawstart++;
		}
	}
}

void	ft_draw_wall_color(t_storage *storage, t_ray *ray, int x)
{
	int		lineheight;
	int		drawstart;
	int		drawend;

	lineheight = (int)(storage->info->ry / ray->perpwalldist);
	lineheight *= 1;
	drawstart = -lineheight / 2 + storage->info->ry / 2;
	if (drawstart < 0)
		drawstart = 0;
	drawend = lineheight / 2 + storage->info->ry / 2;
	if (drawend >= storage->info->ry)
		drawend = storage->info->ry - 1;
	if (ray->side == 1)
		ft_draw_south_north(storage, drawstart, drawend, x);
	else
		ft_draw_east_west(storage, drawstart, drawend, x);
}
