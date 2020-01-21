/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:51:59 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/21 13:08:32 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	ft_fill_map(t_info *info_map, int y, int len_max)
{
	int		x;
	char	**new_map;


	if (!(new_map = (char **)malloc(sizeof(char *) * (y + 1))))
		return ;
	x = 0;
	while (x <= y)
	{
		if (!(new_map[x] = (char *)malloc(sizeof(char) * (len_max + 1))))
			return ;
		new_map[0][0] = '\0';
		x++;
	}
	x = 0;
	y = 0;
	while (info_map->map[y])
	{
		x = 0;	
		while (info_map->map[y][x] != '\0')
		{
			new_map[y][x] = info_map->map[y][x];
			x++;
		}
		new_map[y][x] = '\0';
		if (x <= len_max)
		{
			while (x <= len_max)
			{
				new_map[y][x] = '1';
				x++;
			}
			new_map[y][x] = '\0';
		}
		y++;
	}
	new_map[y] = 0;
/*	x = 0;
	printf("\nnew_map");
	while (new_map[x] != '\0')
	{
		printf("\n|%s|", new_map[x]);
		x++;
	}
	x = 0;
	printf("\nancien_map");
	while (info_map->map[x])
	{
		printf("\n|%s|", info_map->map[x]);
		x++;
	}*/
	y = 0;
	while (info_map->map[y])
		free(info_map->map[y++]);
	free(info_map->map);
	info_map->map = new_map;
	y = 0;
	printf("\nnew_info_map");
	while (info_map->map[y])
	{
		printf("\n|%s|", info_map->map[y]);
		y++;
	}
}

int		ft_check_len_map(t_info *info_map)
{
	int		y;
	int		x;
	int		len_max;

	y = 0;
	len_max = 0;
	while (info_map->map[y])
	{
		x = 0;
		while (info_map->map[y][x])
		{
			if (x > len_max)
				len_max = x;
			x++;
		}
		y++;
	}
	printf("\ny = %d", y);
	printf("\nlen_max = %d",len_max);
	info_map->len_x = len_max;
	info_map->len_y = y;
	ft_fill_map(info_map, y, len_max);
	return(len_max);
}
