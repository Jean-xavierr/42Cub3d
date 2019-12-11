/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:02:44 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/11 11:07:10 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		main(int ac, char **av)
{
	t_info	info_map;

	if (ac < 2)
		ft_error(-1, "");
	else if (ac > 2)
		ft_error(0, "");
	else
	{
		ft_init_struct_infomap(&info_map);
		ft_read_management(av[ac - 1], &info_map);
	}
	printf("texture |%s|\n", info_map.north_t);
	printf("texture |%s|\n", info_map.south_t);
	printf("texture |%s|\n", info_map.west_t);
	printf("texture |%s|\n", info_map.east_t);
	printf("texture |%s|\n", info_map.sprite_t);
	printf("colorf |%d|\n", info_map.colorf);
	printf("colorc |%d|\n", info_map.colorc);
	return (0);
}
