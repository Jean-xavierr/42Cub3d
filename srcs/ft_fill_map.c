/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 10:51:59 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/17 14:14:30 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void	ft_fill_map(t_info *info_map, int x, int len_max)
{
	int		y;
	char	**new_map;


	if (!(new_map = (char **)malloc(sizeof(char *) * (x + 1))))
		return ;
/*	x = 0;
	while (info_map->map[x] != '\0')
	{
		y = 0;
		printf("\n");
		while (info_map->map[x][y] != '\0')
		{
			printf("%c", info_map->map[x][y]);
			y++;
		}
		x++;
	}*/
	y = 0;
	while (y <= x)
	{
		if (!(new_map[y] = (char *)malloc(sizeof(char) * (len_max + 1))))
			return ;
		new_map[0][0] = '\0';
		y++;
	}
	x = 0;
	y = 0;
	while (info_map->map[x])
	{
		y = 0;	
		while (info_map->map[x][y] != '\0')
		{
			new_map[x][y] = info_map->map[x][y];
			y++;
		}
		new_map[x][y] = '\0';
		if (y <= len_max)
		{
			while (y <= len_max)
			{
				new_map[x][y] = '1';
				y++;
			}
			new_map[x][y] = '\0';
		}
		x++;
	}
	new_map[x] = 0;
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
	x = 0;
	while (info_map->map[x])
		free(info_map->map[x++]);
	free(info_map->map);
	info_map->map = new_map;
	x = 0;
	printf("\nnew_info_map");
	while (info_map->map[x])
	{
		printf("\n|%s|", info_map->map[x]);
		x++;
	}
}

int		ft_check_len_map(t_info *info_map)
{
	int		x;
	int		y;
	int		len_max;

	x = 0;
	len_max = 0;
	while (info_map->map[x])
	{
		y = 0;
		while (info_map->map[x][y])
		{
			if (y > len_max)
				len_max = y;
			y++;
		}
		x++;
	}
	printf("\nx = %d", x);
	printf("\nlen_max = %d",len_max);
	info_map->len_x = x;
	info_map->len_y = len_max;
	ft_fill_map(info_map, x, len_max);
	return(len_max);
}
