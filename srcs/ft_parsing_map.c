/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 12:04:02 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/11 14:28:58 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_parsing_map_line_updown(t_info *info_map)
{
	int		i;
	int		n;

	i = 0;
	while (info_map->map[0][i])
	{
		if (info_map->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (info_map->map[i])
		i++;
	i--;
	info_map->len_map = i;
	n = 0;
	while (info_map->map[i][n])
	{
		if (info_map->map[i][n] != '1')
			return (0);
		n++;
	}
	return (1);
}

int		ft_parsing_map_line_middle(t_info *info_map)
{
	int		line;
	int		len_l1;
	int		len_l2;
	int		len_check;
	
	line = 1;
	while (info_map->map[line + 1] != NULL)
	{		
		len_l1 = ft_strlen(info_map->map[line]);
		len_l2 = ft_strlen(info_map->map[line + 1]);
		len_check = len_l1 - len_l2;	
		if (len_check == 0)
		{
			if (info_map->map[line][0] != '1' || info_map->map[line][len_l1 - 1] != '1')
				return (0);
			/*if (info_map->map[line + 1][0] != '1' || info_map->map[line + 1][len_l2 - 1] != '1')
				return (0);*/
		}
		else if (len_check >= 1)
		{
			if (info_map->map[line][0] != '1')
				return (0);
			len_l1 = len_l1 - len_check;
			while (info_map->map[line][len_l1])
			{
				if (info_map->map[line][len_l1] != '1')
					return (0);
				len_l1++;
			}	
			if (info_map->map[line + 1][0] != '1' || info_map->map[line + 1][len_l2 - 1] != '1')
				return (0);
		}
		else if (len_check < 0) 
		{	
			if (info_map->map[line + 1][0] != '1')
			{
				return (0);
			}
			len_check *= -1;
			len_l2 = len_l2 - len_check;
			while (info_map->map[line + 1][len_l2])
			{
				if (info_map->map[line + 1][len_l2] != '1')
					return (0);
				len_l2++;
			}	
			if (info_map->map[line][0] != '1' || info_map->map[line][len_l1 - 1] != '1')
				return (0);
		}
		line++;
	}
	return (1);
}
