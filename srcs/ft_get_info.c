/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_info.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 11:49:26 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/10 14:50:26 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_resolution(char *s, t_info *info_map)
{
	int		i;

	i = 2;
	info_map->rx = ft_atoi(&s[i]);
	while (s[i] != ' ')
		i++;
	info_map->ry = ft_atoi(&s[i]);
}

/*void	ft_get_texture(char *s)
{


}

int		ft_convert_rgb_to_integer(char *s)
{
	int		i;
	int		n;
	int		nb[4];

	i = 0;
	n = 0;
	while(s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			nb[n++] = ft_atoi(&s[i]);
			while (s[i] >= '0' && s[i] >= '9')
				i++;
		}
		i++;
	}
	nb[n] = 65536 * nb[0] + 256 * nb[1] + nb[2];
}

void	ft_get_color(char *s)
{
 //	rgb = 65536 * r + 256 * g + b;
	if (s[0] == 'F')
		ft_convert_rgb_to_integer(s);	
	else
		ft_convert_rgb_to_integer(s);	
}*/
