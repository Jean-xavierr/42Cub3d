/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:36:58 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/06 12:00:43 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_south_north(t_storage *storage, t_ray *ray, int drawstart, int drawend, int x)
{
	if (ray->raydir_y >= 0)
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * 
			storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16724530; // Red rgg : 255,50,50 | sud
			drawstart++;
		}
	}
	else
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * 
			storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16753920; // Yellow rgb : 255,165,0 | north
			drawstart++;
		}
	}
}

void	ft_draw_west_east(t_storage *storage, t_ray *ray, int drawstart, int drawend, int x)
{
	if (ray->raydir_x >= 0)
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * 
			storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 3333140; // Green rgb : 50,220,20 | right
			drawstart++;
		}
	}
	else
	{
		while (drawstart < drawend)
		{
			*(int *)(&storage->mlx->data_img[((drawstart * 
			storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 65535; // Blue // left
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
		ft_draw_south_north(storage, ray, drawstart, drawend, x);
	else
		ft_draw_west_east(storage, ray, drawstart, drawend, x);
}

void	ft_raycaster(t_storage *storage, t_ray *ray)
{
	int		x;
	
	x = 0;
	storage->zbuffer = malloc(sizeof(double) * storage->info->rx);
	while (x < storage->info->rx)
	{
		ray->cam_x = 2 * x / (double)storage->info->rx - 1;
		ray->raydir_x = storage->player->dir_x + ray->plane_x * ray->cam_x;
		ray->raydir_y = storage->player->dir_y + ray->plane_y * ray->cam_x;
		ray->map_x = (int)storage->player->pos_x;
		ray->map_y = (int)storage->player->pos_y;
		ray->deltadist_x = fabs(1 / ray->raydir_x);
		ray->deltadist_y= fabs(1 / ray->raydir_y);
		if (ray->raydir_x < 0)
		{
			ray->step_x = -1;
			ray->sidedist_x = (storage->player->pos_x - ray->map_x) * ray->deltadist_x;
		}
		else
		{
			ray->step_x = 1;
			ray->sidedist_x = (ray->map_x + 1.0 - storage->player->pos_x) * ray->deltadist_x;
		}
		if (ray->raydir_y < 0)
		{
			ray->step_y = -1;
			ray->sidedist_y = (storage->player->pos_y - ray->map_y) * ray->deltadist_y;
		}
		else
		{
			ray->step_y = 1;
			ray->sidedist_y = (ray->map_y + 1.0 - storage->player->pos_y) * ray->deltadist_y;
		}
		while (ray->hit == 0)
		{
			if (ray->sidedist_x < ray->sidedist_y)
			{
				ray->sidedist_x += ray->deltadist_x;
				ray->map_x += ray->step_x;
				ray->side = 0;
			}
			else
			{
				ray->sidedist_y += ray->deltadist_y;
				ray->map_y += ray->step_y;
				ray->side = 1;
			}
			if (storage->info->map[ray->map_y][ray->map_x] == '1')
				ray->hit = 1;
		}
		if (ray->side == 0)
			ray->perpwalldist = (ray->map_x - storage->player->pos_x + (1 - ray->step_x) / 2) / ray->raydir_x;
		else
		{
			ray->perpwalldist = (ray->map_y - storage->player->pos_y + (1 - ray->step_y) / 2) / ray->raydir_y;
		}
		storage->zbuffer[x] = ray->perpwalldist;
		if (storage->move->texture == 0)
			ft_draw_wall_color(storage, ray, x);
		else
			ft_management_texture(storage, ray, x);
		ray->hit = 0;
		x++;
	}
}
