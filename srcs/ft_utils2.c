/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:57:50 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/10 15:45:01 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_verif_rgb_is_valid(int nb[4], int n)
{
	if (nb[0] > 255 || nb[1] > 255 || nb[2] > 255)
		return (-2);
	else if (nb[0] < 0 || nb[1] < 0 || nb[2] < 0)
		return (-2);
	else
		nb[n] = 65536 * nb[0] + 256 * nb[1] + nb[2];
	return (nb[n]);
}

int		ft_get_texture_path_west_east_s(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	while (s[i] == ' ')
		i++;
	if (s[0] == 'W')
	{
		if (info_map->west_t[0] != '\0')
			return (ft_management_error(11, s));
		ft_strcpy(info_map->west_t, &s[i]);
	}
	else if (s[0] == 'E')
	{
		if (info_map->east_t[0] != '\0')
			return (ft_management_error(11, s));
		ft_strcpy(info_map->east_t, &s[i]);
	}
	else if (s[0] == 'S')
	{
		if (info_map->sprite_t[0] != '\0')
			return (ft_management_error(11, s));
		ft_strcpy(info_map->sprite_t, &s[i]);
	}
	return (1);
}

int		ft_get_info_map_resolution(char *s, t_info *info_map)
{
	if ((ft_get_resolution(s, info_map)) == 0)
		return (ft_management_error(10, ""));
	return (1);
}
