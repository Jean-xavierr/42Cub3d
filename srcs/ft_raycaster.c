/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:36:58 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/24 16:02:23 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_ray(t_ray *ray)
{
	ray->planeX = 0;
	ray->planeY = 0.66;
	ray->hit = 0;
}

void	ft_raycaster(t_storage *storage)
{
	int		x;
	t_ray	ray;

	ft_init_ray(&ray);	
	x = 0;
	while (x < storage->info->rx)
	{
		ray.camX = 2 * x / (double)storage->info->rx - 1;
		ray.raydirX = storage->player->dirX + ray.planeX * ray.camX;
		ray.raydirY = storage->player->dirY + ray.planeY * ray.camX;
		ray.mapX = (int)storage->player->posX;
		ray.mapY = (int)storage->player->posY;
		ray.deltadistX = fabs(1 / ray.raydirX);
		ray.deltadistY= fabs(1 / ray.raydirY);
		if (ray.raydirX < 0)
		{
			ray.stepX = -1;
			ray.sidedistX = (storage->player->posX - ray.mapX) * ray.deltadistX;
		}
		else
		{
			ray.stepX = 1;
			ray.sidedistX = (ray.mapX + 1.0 - storage->player->posX) * ray.deltadistX;
		}
		
		if (ray.raydirY < 0)
		{
			ray.stepY = -1;
			ray.sidedistY = (storage->player->posY- ray.mapY) * ray.deltadistY;
		}
		else
		{		
			ray.stepY = 1;
			ray.sidedistY = (ray.mapY + 1.0 - storage->player->posY) * ray.deltadistY;
		}
		while (ray.hit == 0)
		{
			if (ray.sidedistX < ray.sidedistY)
			{
				ray.sidedistX += ray.deltadistX;
				ray.mapX += ray.stepX;
				ray.side = 0;
			}
			else
			{
				ray.sidedistY += ray.deltadistY;
				ray.mapY += ray.stepX;
				ray.side = 1;
			}
		//	printf("x | y %d | %d\n", ray.mapX, ray.mapY);
		//	printf("map = = = %c\n", storage->info->map[2][14]);
			if (storage->info->map[ray.mapY][ray.mapX] != '0')
				ray.hit = 1;
		}
		if (ray.side == 0)
			ray.perpwalldist = (ray.mapX - storage->player->posX + (1 - ray.stepX) / 2) / ray.raydirX;
		else
			ray.perpwalldist = (ray.mapY - storage->player->posY + (1 - ray.stepY) / 2) / ray.raydirY;
		
		int		lineheight;
		int		drawstart;
		int		drawend;

		lineheight = (int)(storage->info->ry / ray.perpwalldist);
		drawstart = -lineheight / 2 + storage->info->ry / 2;
		if (drawstart < 0)
			drawstart = 0;
		drawend = lineheight / 2 + storage->info->ry / 2;
		if (drawend >= storage->info->rx)
			drawend = storage->info->ry - 1;
		if (ray.side == 1)
		{
			if (ray.raydirY >= 0)
			{
				while (drawstart < drawend)
				{
					*(int *)(&storage->mlx->data_img[((drawstart * storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16711680;
					drawstart++;
				}
			}
			else
			{
				while (drawstart < drawend)
				{
					*(int *)(&storage->mlx->data_img[((drawstart * storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16753920;
					drawstart++;
				}
			}
		}
		else
		{
			if (ray.raydirX >= 0)
			{
				while (drawstart < drawend)
				{
					*(int *)(&storage->mlx->data_img[((drawstart * storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 65280;
					drawstart++;
				}
			}
			else
			{
				while (drawstart < drawend)
				{
					*(int *)(&storage->mlx->data_img[((drawstart * storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 65535;
					drawstart++;
				}
			}
		}
		x++;
	}
	storage->ray = &ray;
}
