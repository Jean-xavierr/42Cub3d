/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprite.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 16:27:07 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/05 17:02:15 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
void	ft_draw_sprite(t_sprite *sprite, int *sprite_order, t_storage *s)
{


}*/

void	ft_sort_sprites(int	*sprite_order, double *sprite_distance, int sprite_nb)
{
	int		i;
	int		tmp_order;
	double	tmp_dist;

	i = 0;
	while (i < sprite_nb)
	{
		if (sprite_distance[i] > sprite_distance[i + 1])
		{
			tmp_dist = sprite_distance[i];
			sprite_distance[i] = sprite_distance[i + 1];
			sprite_distance[i + 1] = tmp_dist;
			tmp_order = sprite_order[i];
			sprite_order[i] = sprite_order[i + 1];
			sprite_order[i + 1] = tmp_order;
			i--;
		}
		i++;
	}
}

void	ft_management_sprite(t_storage *s, t_sprite *sprite, int sprite_nb)
{
	int		sprite_order[sprite_nb];
	double	sprite_distance[sprite_nb];
	int		i;

	i = 0;	
	while (i < sprite_nb)
	{
		sprite_order[i] = i;
		sprite_distance[i] = ((s->player->posX - sprite[i].x) * (s->player->posX - sprite[i].x) + (s->player->posY - sprite[i].y));
		i++;
	}
	ft_sort_sprites(sprite_order, sprite_distance, sprite_nb);
//	ft_draw_spritei(sprite, sprite_order, s);
}
