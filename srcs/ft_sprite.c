/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:27:07 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/06 16:05:02 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_sprite_texture(t_storage *s, t_sprite_info *s_i)
{
	int	stripe;
	int	y;
	int	d;

	stripe = s_i->drawstart_x;
	while (stripe < s_i->drawend_x)
	{
		s_i->texx = (int)((256 * (stripe - (s_i->width / 2 + s_i->screen_x)) * s_i->texwidth / s_i->width) / 256);
		printf("transformy %g\n", s_i->transformy);
		printf("stripe %d\n", stripe);
		printf("zbuffer %g\n", s->zbuffer[stripe]);
		y = s_i->drawstart_y;
		//while (1)
		//	;
		while (y < s_i->drawend_y && s_i->transformy > 0 && s_i->transformy < s->zbuffer[stripe])
		{
				d =  y * 256 - s->info->ry * 128 + s_i->height * 128;
				s_i->texy = ((d * s_i->texheight) / s_i->height) / 256;
				if (s->texture[4].img[s_i->texy % 64 * s->texture[4].size_line + s_i->texx % 64 * s->texture[4].bpixel / 8] != 0)
					ft_memcpy(s->mlx->data_img + 4 * s->info->rx * s_i->drawstart_y + s_i->drawstart_x * 4, &s->texture[4].img[s_i->texy % 64 * s->texture[4].size_line + s_i->texx % 64 * s->texture[4].bpixel / 8], sizeof (int));
				y++;
		}
		stripe++;
	}
}

void	ft_draw_sprite(t_sprite *sprite, int *sprite_order, t_storage *s, int i)
{
	t_sprite_info	s_i;

	s_i.texwidth = 64;
	s_i.texheight = 64;
	s_i.x = sprite[sprite_order[i]].x - (int)s->player->posX;
	s_i.y = sprite[sprite_order[i]].y - (int)s->player->posY;
	s_i.inv_det = 1.0 / (s->ray->planeX * s->player->dirY - s->player->dirX * s->ray->planeY);
	/*	printf("posX %f\n", s->player->posX);
		printf("1X %f\n", sprite[sprite_order[i]].x);
		printf("1Y %f\n", sprite[sprite_order[i]].y);
		printf("invdet %g\n", s_i.inv_det);
		printf("x %g\n", s_i.x);
		printf("y %g\n", s_i.y);
		printf("order %d\n", sprite_order[i]);
		printf("sprorder %f\n", sprite[1].x);
		while (1)
			;*/
	s_i.transformx = s_i.inv_det * (s->player->dirY * s_i.x - s->player->dirX * s_i.y);
	s_i.transformy = s_i.inv_det * (-s->ray->planeY * s_i.x + s->ray->planeX * s_i.y);
	s_i.screen_x = (int)((s->info->rx / 2) * (1 + s_i.transformx / s_i.transformy));
	s_i.height = abs((int)(s->info->ry / (s_i.transformy)));
	s_i.drawstart_y = -s_i.height / 2 + s->info->ry / 2;
	if (s_i.drawstart_y < 0)
		s_i.drawstart_y = 0;
	s_i.drawend_y = s_i.height / 2 + s->info->ry / 2;
	if (s_i.drawend_y >= s->info->ry)
		s_i.drawend_y = s->info->ry - 1;
	s_i.width = abs((int)(s->info->ry / (s_i.transformy)));
	s_i.drawstart_x = -s_i.width / 2 + s_i.screen_x;
	if (s_i.drawstart_x < 0)
		s_i.drawstart_x = 0;
	s_i.drawend_x = s_i.width / 2 + s_i.screen_x;
	if (s_i.drawend_x >= s->info->rx)
		s_i.drawend_x = s->info->rx - 1;
	printf("transformy %g\n", s_i.transformy);	
	printf("drawendx %d\n", s_i.drawend_x);
	printf("screen %d\n", s_i.screen_x);
	//	while (1)
	//		;
	ft_sprite_texture(s, &s_i);
}

void	ft_sort_sprites(int	*sprite_order, double *sprite_distance, int sprite_nb)
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

void	ft_test_sprite(t_storage *s, t_sprite *sprite, int sprite_nb, int *sprite_order, double *sprite_distance)
{	
	int		i;
	
	i = 0;
	while (i < sprite_nb)
	{
		sprite_distance[i] = ((s->player->posX - sprite[i].x) * (s->player->posX - sprite[i].x) + (s->player->posY - sprite[i].y) * (s->player->posY - sprite[i].y));
		sprite_order[i] = i;
		printf("order %d\n", sprite_order[i]);	
		printf("distance  %f\n", sprite_distance[i]);
		i++;
	}
	ft_sort_sprites(sprite_order, sprite_distance, sprite_nb);
}


void	ft_management_sprite(t_storage *s, t_sprite *sprite, int sprite_nb)
{
	int		i;
	int		sprite_order[sprite_nb];
	double	sprite_distance[sprite_nb];

	ft_test_sprite(s, sprite, sprite_nb, sprite_order, sprite_distance);
	i = sprite_nb - 1;
	while (i >= 0)
	{
		ft_draw_sprite(sprite, sprite_order, s, i);
		i--;
	}
}
