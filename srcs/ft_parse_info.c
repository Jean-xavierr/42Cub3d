/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 14:45:56 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/11 14:49:20 by jereligi         ###   ########.fr       */
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

int		ft_parse_info(t_info *info_map)
{
	if (info_map->rx <= 0 || info_map->ry <= 0)
	{
		ft_error(4, "Error: resolution no correct\n");
		return (0);
	}
	if (info_map->colorf == 0 || info_map->colorc == 0)
	{
		ft_error(4, "Error: color floor or ceil can < 256\n");
		return (0);
	}
	//if (!ft_check_open_texture(info_map))
	return (1);
}

void	ft_parse_management(t_info *info_map)
{
	ft_putstr("parsing :\n");
	if (!ft_parse_info(info_map))
		ft_putstr("ERROR INFO");
	else
		ft_putstr("INFO OK\n");
	if (ft_parse_map_line_updown(info_map))
		ft_putstr("MAP OK\n");
	else
		ft_putstr("MAP ERROR\n");
	if (ft_parse_map_line_between(info_map))
		ft_putstr("Mur ok");
	else
		ft_putstr("Mur ko");
}
