/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:02:53 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/07 13:20:53 by jereligi         ###   ########.fr       */
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

typedef struct		s_sprite
{
	double	x;
	double	y;
}					t_sprite;

typedef struct		s_sprite_info
{
	int		i;
	int		nb;
	double	x;
	double	y;
	double	inv_det;
	double	transformx;
	double	transformy;
	int		screen_x;
	int		height;
	int		drawstart_y;
	int		drawend_y;
	int		width;
	int		drawstart_x;
	int		drawend_x;
	int		texwidth;
	int		texheight;
	int		texx;
	int		texy;
	int		texture;
}					t_sprite_info;

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
	int		player_y;
	int		player_x;
	char	player_start;
	int		sprite_nb;
}					t_info;

typedef struct		s_player
{
	double	posY;
	double	posX;
	float	x;
	float	y;
	double	dirX;
	double	dirY;
	double	ms;
	double	rot_speed;
}					t_player;
	
typedef struct		s_mlx
{
	void	*ptr;
	void	*win;
	char	*img;
	char	*data_img;
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
	int				texture;
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

typedef struct		s_text_info
{
	int		lineheight;
	int		drawstart;
	int		drawend;
	double  wallx;
	int		x;
	int		y;
	int		width;
	int		height;
}					t_text_info;

typedef struct		s_texture
{
	void	*ptr;
	char	*img;
	int		bpixel;
	int		size_line;
	int		endian;
}					t_texture;

typedef struct		s_mini_map
{
	int		y;
	int		x;
	int		x_max;
	int		t_x;
	int		t_y;
	int		line;
}					t_mini_map;

typedef struct		s_save
{
	int			fd;
	int			size;
	int			unused;
	int			offset_begin;
	int			header_bytes;
	short int	plane;
	short int	bpixel;
}					t_save;

typedef	struct		s_storage
{
	t_info		*info;
	t_mlx		*mlx;
	t_player	*player;
	t_move		*move;
	t_ray		*ray;
	t_texture	*texture;
	t_sprite	sprite[50];
	double		*zbuffer;
	int			save;
}					t_storage;

/* --> Cub3d.c <-- */
int		ft_expose(t_storage *storage);

/* --> ft_mini_map.c <-- */
void	ft_color_wall_mini_map(t_storage *storage, int y, int x, int color);
void	ft_draw_mini_map(t_storage *storage);

/* --> ft_read_map <-- */
int		ft_read_map(char *s, t_info *info_map);
int		ft_read_management(char *s, t_info *info_map);

/* --> ft_parse_info.c <-- */
int		ft_check_extension(char *s);
int		ft_parse_info(t_info *info_map);
int		ft_parse_management(t_info *info_map, t_len_map *len);

/* --> ft_parse_map.c <-- */
int		ft_parse_map_line_updown(t_info *info_map);
int		ft_parse_map_line_between(t_info *info_map, t_len_map *len);

/* --> ft_get_info.c <-- */
void	ft_get_resolution(char *s, t_info *info_map);
void	ft_get_texture_path(char *s, t_info *info_map);
void	ft_get_color(char *s, t_info *info_map);
int		ft_get_info_map(char *s, t_info *info_map);

/* --> ft_error.c <-- */
int		ft_management_error(int error, char *s);

/* --> ft_init.c <-- */
void	ft_init_struct_infomap(t_info *info_map);
void	ft_init_struct_move(t_move *move);
void	ft_init_struct_player(t_player *player);
void	ft_init_struct_ray(t_ray *ray);
void	ft_init_pos_player(t_storage *storage, t_player *player);

/* --> ft_fill_map <-- */
void	ft_check_len_map(t_info *info_map);

/* --> ft_exit_prog.c <-- */
int		ft_exit_prog(t_storage *storage);

/* --> ft_keyboard_action.c */
int		ft_keyrelease(int keycode, t_move *move);
int		ft_keypress(int keycode, t_move *move);

/* --> ft_move_player_mini_map.c <-- */
void	ft_move_player_mini_map(t_storage *storage);
void	ft_player_pos_cam(t_storage *storage, t_player *player);

/* --> ft_raycaster <-- */
void	ft_raycaster(t_storage *storage, t_ray *ray);

/* --> ft_management_texture <-- */
int		ft_init_texture(t_storage *storage, t_texture *texture, int w, int h);
void	ft_management_texture(t_storage *storage, t_ray *ray, int x);

/* --> ft_memcpy <-- */
void	*ft_memcpy(void *dst, const void *src, int n);

/* --> ft_strncmp <-- */
int		ft_strncmp(const char *s1, const char *s2, int n);

/* --> ft_save <-- */
void	ft_save(t_info *info_map, t_mlx *mlx);

/* --> ft_parse_info_2 <-- */
int		ft_get_pos_player(t_info *info_map, int i, int x);
void	ft_get_sprite_nb(t_info *info_map);
void	ft_get_pos_sprite(t_info *info_map, t_storage *storage);

/* --> ft_sprite <-- */
void	ft_management_sprite(t_storage *s, t_sprite *sprite, int sprite_nb);

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
