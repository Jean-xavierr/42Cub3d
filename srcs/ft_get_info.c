/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:49:26 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/10 18:17:05 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_resolution(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	info_map->rx = ft_atoi(&s[i]);
	while (s[i] != ' ')
		i++;
	info_map->ry = ft_atoi(&s[i]);
}

void	ft_get_texture_path(char *s, t_info *info_map)
{
	int	i;

	i = 2;
	while (s[i] == ' ')
		i++;
	if (s[0] == 'N')
		ft_strcpy(info_map->north_t, &s[i]);
	else if (s[0] == 'S' && s[1] == 'O')
		ft_strcpy(info_map->south_t, &s[i]);
	else if (s[0] == 'W')
		ft_strcpy(info_map->west_t, &s[i]);
	else if (s[0] == 'E')
		ft_strcpy(info_map->east_t, &s[i]);
	else if (s[0] == 'S')
		ft_strcpy(info_map->sprite_t, &s[i]);
}

int		ft_convert_rgb_to_integer(char *s)
{
	int		i;
	int		n;
	int		nb[4];

	i = 1;
	n = 0;
	while (s[i])
	{
		if ((s[i] == '-' || s[i] == '+') || (s[i] >= '0' && s[i] <= '9'))
		{
			nb[n++] = ft_atoi(&s[i]);
			if (s[i] == '-' && s[i] == '+')
				i++;
			while (s[i] >= '0' && s[i] <= '9')
				i++;
		}
		i++;
	}
	nb[n] = 65536 * nb[0] + 256 * nb[1] + nb[2];
	return (nb[n]);
}

void	ft_get_color(char *s, t_info *info_map)
{
	if (s[0] == 'F')
		info_map->colorf = ft_convert_rgb_to_integer(s);
	else
		info_map->colorc = ft_convert_rgb_to_integer(s);
}

int		ft_get_info_map(char *s, t_info *info_map)
{
	printf("|%s| : ", s);
	if (s[0] == 'R')
		ft_get_resolution(s, info_map);
	else if ((s[0] == 'N' && s[1] == 'O') || (s[0] == 'S' && s[1] == 'O') \
	|| (s[0] == 'W' && s[1] == 'E') || (s[0] == 'W' && s[1] == 'E') \
	|| (s[0] == 'E' && s[1] == 'A') || (s[0] == 'S' && s[1] == ' '))
		ft_get_texture_path(s, info_map);
	else if (s[0] == 'F' || s[0] == 'C')
		ft_get_color(s, info_map);
	else if (s[0] == '\n' || s[0] == '\0')
		printf("vide\n");
	else
	{
		ft_error(3, s);
		return (0);
	}
	return (1);
}
