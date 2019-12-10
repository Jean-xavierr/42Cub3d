/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:06:09 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/10 16:52:37 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void		ft_read_map(char *s, t_info *info_map)
{
	int		i;
	int		fd;
	char	*line;
	char	*map_tmp;
	char	**map;

	i = 0;
	if (!(map_tmp = (char *)malloc(sizeof(char))))
		return (ft_putstr("Error malloc"));
	if ((fd = open(s, O_RDWR)) == -1)
		return (ft_error(2));
	while (((i = get_next_line(fd, &line)) != 0) && !ft_is_wall(line[0]))
	{
		if (!ft_get_info_map(line, info_map))
			return ;
		free(line);
	}
	map_tmp = ft_strjoin_point(map_tmp, line);
	free(line);
	while ((i = get_next_line(fd, &line)) != 0)
	{
		map_tmp = ft_strjoin_point(map_tmp, line);
		free(line);
	}
	//printf("test map %s\n", map_tmp);
	map = ft_split(map_tmp, '.');
	i = 0;
	while (map[i])
		printf("[%s]\n", map[i++]);
}

void		ft_read_management(char *s, t_info *info_map)
{
	if (ft_check_extension(s) == 0)
		return (ft_error(1));
	else
		ft_read_map(s, info_map);
}
