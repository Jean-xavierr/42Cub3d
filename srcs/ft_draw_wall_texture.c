/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_wall_texture.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 16:57:46 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/07 17:00:42 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_draw_wall_texture_sn(t_storage *s, t_texture *texture,
t_text_info *text_i, int x)
{
	if (s->ray->raydir_y >= 0)
	{
		while (text_i->drawstart < text_i->drawend)
		{
			text_i->y = abs((((text_i->drawstart * 256 - s->info->ry * 128
			+ text_i->lineheight * 128) * 64) / text_i->lineheight) / 256);
			ft_memcpy(s->mlx->data_img + 4 * s->info->rx * text_i->drawstart
			+ x * 4, &texture[1].img[text_i->y % 64 * texture[1].size_line +
			text_i->x % 64 * texture[1].bpixel / 8], sizeof(int));
			text_i->drawstart++;
		}
	}
	else
	{
		while (text_i->drawstart < text_i->drawend)
		{
			text_i->y = abs((((text_i->drawstart * 256 - s->info->ry * 128 +
			text_i->lineheight * 128) * 64) / text_i->lineheight) / 256);
			ft_memcpy(s->mlx->data_img + 4 * s->info->rx * text_i->drawstart + x
			* 4, &texture[0].img[text_i->y % 64 * texture[0].size_line +
			text_i->x % 64 * texture[0].bpixel / 8], sizeof(int));
			text_i->drawstart++;
		}
	}
}

void	ft_draw_wall_texture_ew(t_storage *s, t_texture *texture,
t_text_info *text_i, int x)
{
	if (s->ray->raydir_x >= 0)
	{
		while (text_i->drawstart < text_i->drawend)
		{
			text_i->y = abs((((text_i->drawstart * 256 - s->info->ry * 128 +
			text_i->lineheight * 128) * 64) / text_i->lineheight) / 256);
			ft_memcpy(s->mlx->data_img + 4 * s->info->rx * text_i->drawstart
			+ x * 4, &texture[3].img[text_i->y % 64 * texture[3].size_line +
			text_i->x % 64 * texture[3].bpixel / 8], sizeof(int));
			text_i->drawstart++;
		}
	}
	else
	{
		while (text_i->drawstart < text_i->drawend)
		{
			text_i->y = abs((((text_i->drawstart * 256 - s->info->ry * 128 +
			text_i->lineheight * 128) * 64) / text_i->lineheight) / 256);
			ft_memcpy(s->mlx->data_img + 4 * s->info->rx * text_i->drawstart
			+ x * 4, &texture[2].img[text_i->y % 64 * texture[2].size_line +
			text_i->x % 64 * texture[2].bpixel / 8], sizeof(int));
			text_i->drawstart++;
		}
	}
}
