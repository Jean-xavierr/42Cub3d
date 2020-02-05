/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:31:22 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/05 13:37:03 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_get_pos_player(t_info *info_map, int i, int x)
{
	if (info_map->player_start == '0')
	{
		info_map->player_x = x;
		info_map->player_y = i;
		info_map->player_start = info_map->map[i][x];
		info_map->map[i][x] = '0';
	}
	else
		return (ft_management_error(7, ""));
	return (1);
}
