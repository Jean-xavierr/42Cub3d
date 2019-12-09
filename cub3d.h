/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:02:53 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/09 15:06:02 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "includes/get_next_line.h"
# include "includes/minilibx_opengl/mlx.h"

/* --> ft_read_map <-- */
int		ft_read_map(char *s);

/* --> ft_get_next_line <-- */
int		get_next_line(int fd, char **line);

//  ----------------
// 	function utils.c
//  ----------------

/* --> ft_strlen.c <-- */
int		ft_strlen(char *s);

/* --> ft_strjoin_point.c <-- */
char	*ft_strjoin_point(char *s1, char *s2);

/* --> ft_split.c <-- */
char	**ft_split(char const *s, char c);

#endif
