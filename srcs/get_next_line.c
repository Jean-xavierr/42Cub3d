/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:26:13 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/09 14:29:50 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

int		ft_strlen_c(char *str, char c)
{
	int i;

	i = 0;
	while (str && str[i] && str[i] != c)
		i++;
	return (i);
}

int		ft_is_c(char *str, char c)
{
	int i;

	i = 0;
	while (str && str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_get_info(char **storage_read, char **line, char c)
{
	void *tmp;

	tmp = *storage_read;
	*line = ft_strdup_c(*storage_read, c);
	*storage_read = ft_strcut_c(*storage_read, c);
	free(tmp);
	if (c == '\n')
		return (GNL_LINE_READ);
	else if (c == '\0')
		return (GNL_EOF);
	return (0);
}

int		ft_file_reading(int fd, char **storage_read, char **line)
{
	int			ret_read;
	char		*buf;

	if (!(buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	while ((ret_read = read(fd, buf, BUFFER_SIZE)))
	{
		if (ret_read == -1)
			break ;
		buf[ret_read] = '\0';
		if ((*storage_read = ft_strjoin(*storage_read, buf)) &&
		ft_is_c(buf, '\n') == 1)
			break ;
	}
	free(buf);
	if (ret_read >= 0 && ft_is_c(*storage_read, '\n') == 1)
		return (ft_get_info(storage_read, line, '\n'));
	if (ret_read == 0 && BUFFER_SIZE > 0)
		return (ft_get_info(storage_read, line, '\0'));
	return (GNL_ERROR);
}

int		get_next_line(int fd, char **line)
{
	static char	*storage_read[250];

	if (line == NULL)
		return (GNL_ERROR);
	if (fd >= 0 && !(storage_read[fd]))
	{
		if (!(storage_read[fd] = (char*)malloc(1)))
			return (0);
		storage_read[fd][0] = '\0';
	}
	if (fd >= 0 && ft_is_c(storage_read[fd], '\n') == 1)
		return (ft_get_info(&storage_read[fd], line, '\n'));
	if (fd >= 0)
		return (ft_file_reading(fd, &storage_read[fd], line));
	return (GNL_ERROR);
}
