/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:27:07 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/10 10:29:28 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sprite_texture(t_storage *s, t_sprite_info *s_i)
{
	int	stripe;
	int	y;

	stripe = s_i->drawstart_x;
	while (stripe < s_i->drawend_x)
	{
		s_i->texx = (int)((256 * (stripe - (-s_i->width / 2 + s_i->screen_x))
		* s_i->texwidth / s_i->width) / 256);
		y = s_i->drawstart_y;
		while (y < s_i->drawend_y && s_i->transformy > 0 && s_i->transformy
		< s->zbuffer[stripe])
		{
			s_i->d = y * 256 - s->info->ry * 128 + s_i->height * 128;
			s_i->texy = ((s_i->d * s_i->texheight) / s_i->height) / 256;
			if (s->texture[4].img[s_i->texy % 64 * s->texture[4].size_line
			+ s_i->texx % 64 * s->texture[4].bpixel / 8] != 0)
			{
				ft_memcpy(s->mlx->data_img + 4 * s->info->rx * y + stripe * 4,
				&s->texture[4].img[s_i->texy % 64 * s->texture[4].size_line +
				s_i->texx % 64 * s->texture[4].bpixel / 8], sizeof(int));
			}
			y++;
		}
		stripe++;
	}
}

void	ft_draw_sprite(t_sprite_info *s_i, t_sprite *sprite, int *sprite_order,
t_storage *s)
{
	s_i->x = sprite[sprite_order[s_i->i]].x - s->player->pos_x;
	s_i->y = sprite[sprite_order[s_i->i]].y - s->player->pos_y;
	s_i->inv_det = 1.0 / (s->ray->plane_x * s->player->dir_y -
	s->player->dir_x * s->ray->plane_y);
	s_i->transformx = s_i->inv_det * (s->player->dir_y * s_i->x -
	s->player->dir_x * s_i->y);
	s_i->transformy = s_i->inv_det * (-s->ray->plane_y * s_i->x +
	s->ray->plane_x * s_i->y);
	s_i->screen_x = (int)((s->info->rx / 2) * (1 + s_i->transformx /
	s_i->transformy));
	s_i->height = abs((int)(s->info->ry / (s_i->transformy)));
	s_i->drawstart_y = -s_i->height / 2 + s->info->ry / 2;
	if (s_i->drawstart_y < 0)
		s_i->drawstart_y = 0;
	s_i->drawend_y = s_i->height / 2 + s->info->ry / 2;
	if (s_i->drawend_y >= s->info->ry)
		s_i->drawend_y = s->info->ry - 1;
	s_i->width = abs((int)(s->info->ry / (s_i->transformy)));
	s_i->drawstart_x = -s_i->width / 2 + s_i->screen_x;
	if (s_i->drawstart_x < 0)
		s_i->drawstart_x = 0;
	s_i->drawend_x = s_i->width / 2 + s_i->screen_x;
	if (s_i->drawend_x >= s->info->rx)
		s_i->drawend_x = s->info->rx - 1;
}

void	ft_sort_sprites(int *sprite_order, double *sprite_distance,
int sprite_nb)
{
	int		i;
	int		tmp_order;
	double	tmp_dist;

	i = 0;
	while (i < sprite_nb - 1)
	{
		if (sprite_distance[i] > sprite_distance[i + 1])
		{
			tmp_dist = sprite_distance[i];
			sprite_distance[i] = sprite_distance[i + 1];
			sprite_distance[i + 1] = tmp_dist;
			tmp_order = sprite_order[i];
			sprite_order[i] = sprite_order[i + 1];
			sprite_order[i + 1] = tmp_order;
			i = -1;
		}
		i++;
	}
}

void	ft_init_sprite(t_storage *s, t_sprite *sprite, int *sprite_order,
double *sprite_distance)
{
	int		i;

	i = 0;
	while (i < s->info->sprite_nb)
	{
		sprite_distance[i] = ((s->player->pos_x - sprite[i].x) *
		(s->player->pos_x - sprite[i].x) + (s->player->pos_y - sprite[i].y)
		* (s->player->pos_y - sprite[i].y));
		sprite_order[i] = i;
		i++;
	}
	ft_sort_sprites(sprite_order, sprite_distance, s->info->sprite_nb);
}

void	ft_management_sprite(t_storage *s, t_sprite *sprite, int sprite_nb)
{
	int					sprite_order[sprite_nb];
	double				sprite_distance[sprite_nb];
	t_sprite_info		s_i;

	ft_init_sprite(s, sprite, sprite_order, sprite_distance);
	s_i.texwidth = 64;
	s_i.texheight = 64;
	s_i.i = sprite_nb - 1;
	while (s_i.i >= 0)
	{
		ft_draw_sprite(&s_i, sprite, sprite_order, s);
		ft_sprite_texture(s, &s_i);
		s_i.i--;
	}
}
