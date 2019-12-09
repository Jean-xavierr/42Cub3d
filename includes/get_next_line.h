/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 11:17:24 by jereligi          #+#    #+#             */
/*   Updated: 2019/11/07 09:26:09 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define GNL_ERROR -1
# define GNL_EOF 0
# define GNL_LINE_READ 1

int		get_next_line(int fd, char **line);
int		ft_strlen_c(char *str, char c);
int		ft_is_c(char *str, char c);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup_c(char *str, char c);
char	*ft_strcut_c(char *str, char c);

#endif
