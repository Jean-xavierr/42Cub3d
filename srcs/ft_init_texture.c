/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_texture.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 10:00:17 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/03 11:56:32 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
void	ft_draw_wall_texture(t_storage *storage, t_ray *ray, int x)
{
	if (ray->side == 1)
	{
		if (ray->raydirY >= 0)
		{
			while (drawstart < drawend)
			{

			}
		}
		else
		{
			while (drawstart < drawend)
			{
			}
		}
	}
	else
	{
		if (ray->raydirX >= 0)
		{
			while (drawstart < drawend)
			{
			}
		}
		else
		{
			while (drawstart < drawend)
			{
			}
		}
	}

}*/

void	ft_init_texture(t_storage *storage, t_texture *texture, int w, int h)
{
	if ((texture[0].ptr = mlx_xpm_file_to_image(storage->mlx->ptr, storage->info->north_t, &w, &h)) == NULL)
		return (ft_management_error(9, "Error : corruption texture north\n"));
	if ((texture[1].ptr = mlx_xpm_file_to_image(storage->mlx->ptr, storage->info->south_t, &w, &h)) == NULL)
		return (ft_management_error(9, "Error : corruption texture south\n"));
	if ((texture[2].ptr = mlx_xpm_file_to_image(storage->mlx->ptr, storage->info->west_t, &w, &h)) == NULL)
		return (ft_management_error(9, "Error : corruption texture west\n"));
	if ((texture[3].ptr = mlx_xpm_file_to_image(storage->mlx->ptr, storage->info->east_t, &w, &h)) == NULL)
		return (ft_management_error(9, "Error : corruption texture east\n"));
	texture[4].ptr = NULL;
	texture[0].img = mlx_get_data_addr(texture[0].ptr, &texture[0].bpixel, &texture[0].size_line, &texture[0].endian);
	if (texture[0].img == NULL)
		return (ft_management_error(9, "Error : corruption texture north\n"));
	texture[1].img = mlx_get_data_addr(texture[1].ptr, &texture[1].bpixel, &texture[1].size_line, &texture[1].endian);
	if (texture[1].img == NULL)
		return (ft_management_error(9, "Error : corruption texture south\n"));
	texture[2].img = mlx_get_data_addr(texture[2].ptr, &texture[2].bpixel, &texture[2].size_line, &texture[2].endian);
	if (texture[2].img == NULL)
		return (ft_management_error(9, "Error : corruption texture west\n"));	
	texture[3].img = mlx_get_data_addr(texture[3].ptr, &texture[3].bpixel, &texture[3].size_line, &texture[3].endian);
	if (texture[3].img == NULL)
		return (ft_management_error(9, "Error : corruption texture east\n"));
	storage->texture = texture;
}

void	ft_init_value(t_storage *storage, t_text_info *text_info, t_ray *ray)
{
	text_info->lineheight = (int)(storage->info->ry / storage->ray->perpwalldist);
	text_info->lineheight *= 1;
	text_info->drawstart = -text_info->lineheight / 2 + storage->info->ry / 2;
	if (text_info->drawstart < 0)
		text_info->drawstart = 0;
	text_info->drawend = text_info->lineheight / 2 + storage->info->ry / 2;
	if (text_info->drawend >= storage->info->ry)
		text_info->drawend = storage->info->ry - 1;	
	if (ray->side == 0)
		text_info->wallx = storage->player->posY + storage->ray->perpwalldist * storage->ray->raydirY;
	else
		text_info->wallx = storage->player->posX + storage->ray->perpwalldist * storage->ray->raydirX;
	text_info->wallx = floor(text_info->wallx);
	text_info->x = (int)(text_info->wallx * (double)text_info->width);
	if (storage->ray->side == 0 && storage->ray->raydirX > 0)
		text_info->x = text_info->width - text_info->x - 1;
	if (storage->ray->side == 1 && storage->ray->raydirY < 0)
		text_info->x = text_info->width - text_info->x - 1;
}

void	ft_management_texture(t_storage *storage, t_ray *ray, int x)
{
	t_text_info		text_info;

	x = 5;
	ft_init_value(storage, &text_info, ray);
//	ft_draw_wall_texture(storage, ray, x);
	//printf("OK NICE\n"); 
}
