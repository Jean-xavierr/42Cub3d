/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:36:58 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/03 15:46:07 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_south_north(t_storage *storage, t_ray *ray, int drawstart, int drawend, int x)
{
	if (ray->raydirY >= 0)
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
	if (ray->raydirX >= 0)
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
	while (x < storage->info->rx)
	{
		ray->camX = 2 * x / (double)storage->info->rx - 1;
		ray->raydirX = storage->player->dirX + ray->planeX * ray->camX;
		ray->raydirY = storage->player->dirY + ray->planeY * ray->camX;
		ray->mapX = (int)storage->player->posX;
		ray->mapY = (int)storage->player->posY;
		ray->deltadistX = fabs(1 / ray->raydirX);
		ray->deltadistY= fabs(1 / ray->raydirY);
		if (ray->raydirX < 0)
		{
			ray->stepX = -1;
			ray->sidedistX = (storage->player->posX - ray->mapX) * ray->deltadistX;
		}
		else
		{
			ray->stepX = 1;
			ray->sidedistX = (ray->mapX + 1.0 - storage->player->posX) * ray->deltadistX;
		}
		if (ray->raydirY < 0)
		{
			ray->stepY = -1;
			ray->sidedistY = (storage->player->posY - ray->mapY) * ray->deltadistY;
		}
		else
		{
			ray->stepY = 1;
			ray->sidedistY = (ray->mapY + 1.0 - storage->player->posY) * ray->deltadistY;
		}
		while (ray->hit == 0)
		{
			if (ray->sidedistX < ray->sidedistY)
			{
				ray->sidedistX += ray->deltadistX;
				ray->mapX += ray->stepX;
				ray->side = 0;
			}
			else
			{
				ray->sidedistY += ray->deltadistY;
				ray->mapY += ray->stepY;
				ray->side = 1;
			}
			if (storage->info->map[ray->mapY][ray->mapX] == '1')
				ray->hit = 1;
		}
		if (ray->side == 0)
			ray->perpwalldist = (ray->mapX - storage->player->posX + (1 - ray->stepX) / 2) / ray->raydirX;
		else
		{
			ray->perpwalldist = (ray->mapY - storage->player->posY + (1 - ray->stepY) / 2) / ray->raydirY;
		}
		if (storage->move->texture == 0)
			ft_draw_wall_color(storage, ray, x);
		else
			ft_management_texture(storage, ray, x);
		ray->hit = 0;
		x++;
	}
}
