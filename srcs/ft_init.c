/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 14:40:18 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/10 14:50:50 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_struct_infomap(t_info *info_map)
{
	info_map->rx = 0;
	info_map->ry = 0;
	info_map->NO = NULL;
	info_map->SO = NULL;
	info_map->WE = NULL;
	info_map->EA = NULL;
	info_map->S = NULL;
	info_map->colorf = 0;
	info_map->colorc = 0;
}
