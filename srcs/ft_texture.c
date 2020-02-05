/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_texture.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 15:34:18 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/05 12:49:59 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	ft_draw_wall_texture(t_storage *storage, t_texture *texture, t_text_info *text_info, t_ray *ray, int x)
{
	if (ray->side == 1)
	{
		if (ray->raydirY >= 0)
		{
			while (text_info->drawstart < text_info->drawend)
			{
				text_info->y = abs((((text_info->drawstart * 256 - storage->info->ry * 128 + text_info->lineheight * 128) * 64) / text_info->lineheight) / 256);
				ft_memcpy(storage->mlx->data_img + 4 * storage->info->rx * text_info->drawstart + x * 4, 
				&texture[1].img[text_info->y % 64 * texture[1].size_line + text_info->x % 64 * texture[1].bpixel / 8], sizeof(int));
				text_info->drawstart++;
			}
		}
		else
		{
			while (text_info->drawstart < text_info->drawend)
			{	
				text_info->y = abs((((text_info->drawstart * 256 - storage->info->ry * 128 + text_info->lineheight * 128) * 64) / text_info->lineheight) / 256);
				ft_memcpy(storage->mlx->data_img + 4 * storage->info->rx * text_info->drawstart + x * 4, 
				&texture[0].img[text_info->y % 64 * texture[0].size_line + text_info->x % 64 * texture[0].bpixel / 8], sizeof(int));
				text_info->drawstart++;

			}
		}
	}
	else
	{
		if (ray->raydirX >= 0)
		{
			while (text_info->drawstart < text_info->drawend)
			{
				text_info->y = abs((((text_info->drawstart * 256 - storage->info->ry * 128 + text_info->lineheight * 128) * 64) / text_info->lineheight) / 256);
				ft_memcpy(storage->mlx->data_img + 4 * storage->info->rx * text_info->drawstart + x * 4, 
				&texture[3].img[text_info->y % 64 * texture[3].size_line + text_info->x % 64 * texture[3].bpixel / 8], sizeof(int));
				text_info->drawstart++;

			}
		}
		else
		{
			while (text_info->drawstart < text_info->drawend)
			{
				text_info->y = abs((((text_info->drawstart * 256 - storage->info->ry * 128 + text_info->lineheight * 128) * 64) / text_info->lineheight) / 256);
				ft_memcpy(storage->mlx->data_img + 4 * storage->info->rx * text_info->drawstart + x * 4, 
				&texture[2].img[text_info->y % 64 * texture[2].size_line + text_info->x % 64 * texture[2].bpixel / 8], sizeof(int));
				text_info->drawstart++;

			}
		}
	}

}

int		ft_init_texture(t_storage *storage, t_texture *texture, int w, int h)
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
	return (0);
}

void	ft_init_value(t_storage *storage, t_text_info *text_info, t_ray *ray)
{
	text_info->width = 64;
	text_info->height = 64;
	text_info->lineheight = (int)(storage->info->ry / ray->perpwalldist);
	text_info->drawstart = -text_info->lineheight / 2 + storage->info->ry / 2;
	if (text_info->drawstart < 0)
		text_info->drawstart = 0;
	text_info->drawend = text_info->lineheight / 2 + storage->info->ry / 2;
	if (text_info->drawend >= storage->info->ry)
		text_info->drawend = storage->info->ry - 1;	
	if (ray->side == 0)
		text_info->wallx = storage->player->posY + ray->perpwalldist * ray->raydirY;
	else
		text_info->wallx = storage->player->posX + ray->perpwalldist * ray->raydirX;
	text_info->wallx -= floor(text_info->wallx);
	text_info->x = (int)(text_info->wallx * (double)text_info->width);
	if (ray->side == 0 && ray->raydirX > 0)
		text_info->x = text_info->width - text_info->x - 1;
	if (ray->side == 1 && ray->raydirY < 0)
		text_info->x = text_info->width - text_info->x - 1;
}

void	ft_management_texture(t_storage *storage, t_ray *ray, int x)
{
	t_text_info		text_info;

	ft_init_value(storage, &text_info, ray);
	ft_draw_wall_texture(storage, storage->texture, &text_info, ray, x);
}
