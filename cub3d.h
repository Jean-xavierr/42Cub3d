/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:02:53 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/28 15:54:52 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include "includes/get_next_line.h"
# include <mlx.h>

/* --> define <-- */

#define KEYPRESS_EVENT 2
#define KEYPRESS_MASK 1
#define KEYRELEASE_EVENT 3
#define KEYRELEASE_MASK 2

/* --> structure <-- */

typedef	struct		s_info
{
	char	**map;
	int		len_map;
	int		len_x;
	int		len_y;
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

typedef struct		s_player
{
	float	posX;
	float	posY;
	float	x;
	float	y;
	double	dirX;
	double	dirY;
	double	move_speed;
	double	rot_speed;
}					t_player;
	
typedef struct		s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
	void	*data_img;
	int		bpixel;
	int		size_line;
	int		endian;
}					t_mlx;

typedef struct		s_move
{
	int				esc;
	int				foward;
	int				retreat;
	int				left;
	int				right;
	int				turn_left;
	int				turn_right;
	int				sprint;
}					t_move;

typedef struct		s_ray
{
	double			planeX;
	double			planeY;
	double			camX;
	double			raydirX;
	double			raydirY;
	int				mapX;
	int				mapY;
	double			sidedistX;
	double			sidedistY;
	double			deltadistX;
	double			deltadistY;
	double			perpwalldist;
	int				stepX;
	int				stepY;
	int				hit;
	int				side;
}					t_ray;

typedef struct		s_len_map
{
	int		l1;
	int		l2;
	int		check;
}					t_len_map;

typedef	struct		s_storage
{
	t_info		*info;
	t_mlx		*mlx;
	t_player	*player;
	t_move		*move;
	t_ray		*ray;
}					t_storage;

/* --> Cub3d.c <-- */
int		ft_map_2D(t_info *info_map, t_mlx *mlx);

/* --> ft_read_map <-- */
void	ft_read_map(char *s, t_info *info_map);
void	ft_read_management(char *s, t_info *info_map);

/* --> ft_parse_info.c <-- */
int		ft_check_extension(char *s);
int		ft_parse_info(t_info *info_map);
void	ft_parse_management(t_info *info_map, t_len_map *len);

/* --> ft_parse_map.c <-- */
int		ft_parse_map_line_updown(t_info *info_map);
int		ft_parse_map_line_between(t_info *info_map, t_len_map *len);

/* --> ft_get_info.c <-- */
void	ft_get_resolution(char *s, t_info *info_map);
void	ft_get_texture_path(char *s, t_info *info_map);
void	ft_get_color(char *s, t_info *info_map);
int		ft_get_info_map(char *s, t_info *info_map);

/* --> ft_error.c <-- */
void	ft_error(int error, char *s);

/* --> ft_init.c <-- */
void	ft_init_struct_infomap(t_info *info_map);
void	ft_init_struct_move(t_move *move);
void	ft_init_struct_player(t_player *player);

/* --> ft_fill_map <-- */
void	ft_check_len_map(t_info *info_map);

/* --> ft_exit_prog.c <-- */
int		ft_exit_prog(t_storage *storage);

/* --> ft_keyboard_action.c */
int		ft_keyrelease(int keycode, t_move *move);
int		ft_keypress(int keycode, t_move *move);

/* --> ft_move_player_mini_map.c <-- */
void	ft_move_player_mini_map(t_storage *storage);
void	ft_player_pos_cam(t_storage *storage);

/* --> ft_raycaster <-- */
void	ft_raycaster(t_storage *storage);

//  ----------------
// 	function utils.c
//  ----------------

/* --> ft_utils.c <-- */
int		ft_strlen(char *s);
void	ft_putstr(char *s);
int		ft_is_wall(char c);
int		ft_atoi(char *s);
char	*ft_strjoin_point(char *s1, char *s2);

/* --> ft_strdup_map.c <-- */
char	*ft_strdup_map(char *s);

/* --> ft_strcpy.c <-- */
char	*ft_strcpy(char *dest, char *src);

/* --> ft_get_next_line <-- */
int		get_next_line(int fd, char **line);

/* --> ft_split.c <-- */
char	**ft_split(char const *s, char c);

#endif
