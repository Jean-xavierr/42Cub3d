/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:40:18 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/11 13:35:24 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_struct_infomap(t_info *info_map)
{
	info_map->len_map = 0;
	info_map->rx = 0;
	info_map->ry = 0;
	info_map->north_t[0] = '\0';
	info_map->south_t[0] = '\0';
	info_map->west_t[0] = '\0';
	info_map->east_t[0] = '\0';
	info_map->sprite_t[0] = '\0';
	info_map->colorf = 0;
	info_map->colorc = 0;
}
