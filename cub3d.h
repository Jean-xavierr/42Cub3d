/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:02:53 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/10 10:51:26 by jereligi         ###   ########.fr       */
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
	char	*NO;
	char	*SO;
	char	*WE;
	char	*EA;
	char	*S;
	int		*F;
	int		*C;
}					t_info;

/* --> Cub3d.c <-- */

/* --> ft_read_map <-- */
void	ft_read_map(char *s);
void	ft_read_management(char *s);

/* --> ft_parsing_info.c <-- */
int		ft_check_extension(char *s);
int		ft_parsing_info(char *s);

/* --> ft_error.c <-- */
void	ft_error(int error);

//  ----------------
// 	function utils.c
//  ----------------

/* --> ft_utils.c <-- */
int		ft_strlen(char *s);
void	ft_putstr(char *s);
int		ft_is_wall(char c);
char	*ft_strjoin_point(char *s1, char *s2);

/* --> ft_get_next_line <-- */
int		get_next_line(int fd, char **line);

/* --> ft_split.c <-- */
char	**ft_split(char const *s, char c);

#endif
