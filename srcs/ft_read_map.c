/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:06:09 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/07 16:19:59 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_read_info(char *s, t_info *info_map)
{
	int		i;
	int		fd;
	char	*line;
	char	*map_tmp;

	i = 0;
	if (!(map_tmp = (char *)malloc(sizeof(char))))
		return (ft_management_error(9, "Error malloc"));
	map_tmp[0] = 0;
	if ((fd = open(s, O_RDWR)) == -1)
		return (ft_management_error(2, ""));
	while (((i = get_next_line(fd, &line)) != 0) && !ft_is_wall(line[0]))
	{
		if (!ft_get_info_map(line, info_map))
			return (0);
		free(line);
	}
	line = ft_strdup_map(line);
	map_tmp = ft_strjoin_point(map_tmp, line);
	free(line);
	while ((i = get_next_line(fd, &line)) != 0)
	{
		line = ft_strdup_map(line);
		map_tmp = ft_strjoin_point(map_tmp, line);
		free(line);
	}
	free(line);
	info_map->map = ft_split(map_tmp, '.');
	free(map_tmp);
	return (0);
}

int		ft_read_management(char *s, t_info *info_map)
{
	t_len_map	len;

	if (ft_check_extension(s) == 0)
	{
		ft_management_error(1, "");
		return (0);
	}
	else
	{
		ft_read_info(s, info_map);
		if (!ft_parse_management(info_map, &len))
			return (0);
	}
	return (1);
}
