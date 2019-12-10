/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:02:53 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/10 16:52:33 by jereligi         ###   ########.fr       */
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

/* --> structure <-- */
typedef	struct		s_info
{
	int		rx;
	int		ry;
	char	north_t[256];
	char	south_t[256];
	char	west_t[256];
	char	east_t[256];
	char	sprite_t[256];
	int		colorf;
	int		colorc;
}					t_info;

/* --> Cub3d.c <-- */

/* --> ft_read_map <-- */
void	ft_read_map(char *s, t_info *info_map);
void	ft_read_management(char *s, t_info *info_map);

/* --> ft_parsing_info.c <-- */
int		ft_check_extension(char *s);
int		ft_parsing_info(char *s, t_info *info_map);

/* --> ft_get_info.c <-- */
void	ft_get_resolution(char *s, t_info *info_map);
void	ft_get_texture_path(char *s, t_info *info_map);
void	ft_get_color(char *s, t_info *info_map);
int		ft_get_info_map(char *s, t_info *info_map);

/* --> ft_error.c <-- */
void	ft_error(int error);

/* --> ft_init.c <-- */
void	ft_init_struct_infomap(t_info *info_map);

//  ----------------
// 	function utils.c
//  ----------------

/* --> ft_utils.c <-- */
int		ft_strlen(char *s);
void	ft_putstr(char *s);
int		ft_is_wall(char c);
int		ft_atoi(char *s);
char	*ft_strjoin_point(char *s1, char *s2);

/* --> ft_strcpy.c <-- */
char	*ft_strcpy(char *dest, char *src);

/* --> ft_get_next_line <-- */
int		get_next_line(int fd, char **line);

/* --> ft_split.c <-- */
char	**ft_split(char const *s, char c);

#endif
