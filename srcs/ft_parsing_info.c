/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:41:47 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/11 11:07:04 by jereligi         ###   ########.fr       */
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

int		ft_parsing_info(t_info *info_map)
{
	if (info_map->rx <= 0 || info_map->ry <= 0)
		ft_error(4, "Error: resolution no correct\n");
	if (info_map->colorf == 0 || info_map->colorc == 0)
		ft_error(4, "Error: color floor or ceil can < 256\n");
	//if (!ft_check_open_texture(info_map))
	return (1);
}
/*
int		ft_parsing_map(t_info *info_map)
{




}
*/
void	ft_parsing_management(t_info *info_map)
{
	ft_parsing_info(info_map);
//	ft_parsing_map(info_map);
}
