/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:56 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/04 13:53:45 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_extension(char *s)
{
	int		i;
	int		n;
	char	*cub;

	i = 0;
	cub = ".cub";
	while (s[i])
	{
		n = 0;
		while (s[i + n] == cub[n] && cub[n])
		{
			if (s[i + n + 1] == '\0' && cub[n + 1] == '\0')
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

int		ft_check_open_texture(t_info *info_map)
{
	if ((open(info_map->north_t, O_RDONLY)) == -1)
		return (0);
	if ((open(info_map->south_t, O_RDONLY)) == -1)
		return (0);
	if ((open(info_map->east_t, O_RDONLY)) == -1)
		return (0);
	if ((open(info_map->west_t, O_RDONLY)) == -1)
		return (0);
	return (1);
}

int		ft_parse_info(t_info *info_map)
{
	if (info_map->rx <= 0 || info_map->ry <= 0)
	{
		ft_management_error(4, "Error: resolution no correct\n");
		return (0);
	}
	info_map->rx = info_map->rx > 2560 ? 2560 : info_map->rx;
	info_map->ry = info_map->ry > 1440 ? 1440 : info_map->ry;
	if (info_map->colorf == 0 || info_map->colorc == 0)
	{
		ft_management_error(4, "Error: color floor or ceil have to < 256\n");
		return (0);
	}
	if (!ft_check_open_texture(info_map))
	{
		ft_management_error(9, "Error: open(texture) failed\n");
		return (0);
	}
	return (1);
}

int		ft_check_map(t_info *info_map)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while (info_map->map[i])
	{
		x = 0;
		while (info_map->map[i][x])
		{
			if (info_map->map[i][x] != '0' && info_map->map[i][x] != '1' && 
			info_map->map[i][x] != '2' && info_map->map[i][x] != 'N' &&
			info_map->map[i][x] != 'S' && info_map->map[i][x] != 'E' && 
			info_map->map[i][x] != 'W')
			{
				ft_management_error(6, "");
				return (0);
			}
			if (info_map->map[i][x] == 'N' || info_map->map[i][x] == 'S' ||
			info_map->map[i][x] == 'E' || info_map->map[i][x] == 'W')
			{
				printf("pos\n");
				if (info_map->player_start == '0')
				{
					info_map->player_x = x;
					info_map->player_y = i;
					info_map->player_start = info_map->map[i][x];
					info_map->map[i][x] = '0';
				}
				else
				{
					ft_management_error(7, "");
					return (0);
				}
			}
			x++;
		}
		i++;
	}
	if (info_map->player_start == '0')
	{
		ft_management_error(8, "");
		return (0);
	}
	return (1);
}

int		ft_parse_management(t_info *info_map, t_len_map *len)
{
	ft_putstr("parsing :\n");
	if (!ft_parse_info(info_map))
		return (0);
	if (!ft_parse_map_line_updown(info_map) || !ft_parse_map_line_between(info_map, len))
	{
		ft_management_error(5, "");
		return (0);
	}
	if (!ft_check_map(info_map))
		return (0);
	return (1);
}
