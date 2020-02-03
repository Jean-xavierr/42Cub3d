/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:36:58 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/03 11:20:02 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	/*printf("\n\n");
	printf("ray->perwall %f\n", ray->perpwalldist);
	printf("storage->ry %d\n", storage->info->ry);
	printf("lineheight = %d\n", lineheight);
	printf("drawstart %d\n", drawstart);
	printf("drawend %d\n", drawend);
	printf("raydirY %f\n", ray->raydirY);
	printf("raydirX %f\n", ray->raydirX);
	printf("size_line %d\n", storage->mlx->size_line);
	printf("bpixel %d\n", storage->mlx->bpixel);
	printf("calcul pixel %d\n", (((drawstart * storage->mlx->size_line / 4) + x) * storage->mlx->bpixel));
	printf("\n\n");*/
	if (ray->side == 1)
	{
		if (ray->raydirY >= 0)
		{
			while (drawstart < drawend)
			{
				*(int *)(&storage->mlx->data_img[((drawstart * storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16724530; // Red rgg : 255,50,50 | sud
				drawstart++;
			}
		}
		else
		{
			while (drawstart < drawend)
			{
				*(int *)(&storage->mlx->data_img[((drawstart * storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 16753920; // Yellow rgb : 255,165,0 | north
				drawstart++;
			}
		}
	}
	else
	{
		if (ray->raydirX >= 0)
		{
			while (drawstart < drawend)
			{
				*(int *)(&storage->mlx->data_img[((drawstart * storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 3333140; // Green rgb : 50,220,20 | right
				drawstart++;
			}
		}
		else
		{
			while (drawstart < drawend)
			{
				*(int *)(&storage->mlx->data_img[((drawstart * storage->mlx->size_line / 4) + x) * storage->mlx->bpixel]) = 65535; // Blue // left
				drawstart++;
			}
		}
	}
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
	/*	printf("infodirY %f\n", storage->player->dirY);
		printf("plneY %f\n", ray->planeY);
		printf("cam X = %f\n", ray->camX);
		printf("raydirX = %f\n", ray->raydirX);
		printf("raydirY = %f\n", ray->raydirY);
		printf("mapX = %d\n", ray->mapX);
		printf("mapY = %d\n", ray->mapY);
		printf("deltaX = %f\n", ray->deltadistX);
		printf("deltaY = %f\n", ray->deltadistY);*/
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
	/*	printf("\n\n");
		printf("px %f\n", storage->player->posX);
		printf("py %f\n", storage->player->posY);
		printf("sidedistX %f\n", ray->sidedistX);
		printf("sidedistY %f\n", ray->sidedistY);
		printf("stepY %d\n", ray->stepY);*/
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
			//	printf("OKI\n");
			}
		//	printf("x | y %d | %d\n", ray->mapX, ray->mapY);
		//	printf("map = = = %c\n", storage->info->map[2][14]);
			if (storage->info->map[ray->mapY][ray->mapX] == '1')
				ray->hit = 1;
		}
	//	printf("ray->mapy b %d\n", ray->mapY);
		if (ray->side == 0)
			ray->perpwalldist = (ray->mapX - storage->player->posX + (1 - ray->stepX) / 2) / ray->raydirX;
		else
		{
		/*	printf("|||||\n");
			printf("ray->mapy %d\n", ray->mapY);
			printf("py %f\n", storage->player->posY);
			printf("ray->stepY %d\n", ray->stepY);
			printf("ray->raydiry %f\n", ray->raydirY);*/
			ray->perpwalldist = (ray->mapY - storage->player->posY + (1 - ray->stepY) / 2) / ray->raydirY;
		}
		ft_draw_wall_color(storage, ray, x);
		ft_management_texture(storage, ray, x);
		ray->hit = 0;
		x++;
	}
}
