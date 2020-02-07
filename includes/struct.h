/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 13:59:31 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/07 14:27:07 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

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
	double	pos_y;
	double	pos_x;
	float	x;
	float	y;
	double	dir_x;
	double	dir_y;
	double	ms;
	double	rot_s;
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
	double			plane_x;
	double			plane_y;
	double			cam_x;
	double			raydir_x;
	double			raydir_y;
	int				map_x;
	int				map_y;
	double			sidedist_x;
	double			sidedist_y;
	double			deltadist_x;
	double			deltadist_y;
	double			perpwalldist;
	int				step_x;
	int				step_y;
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
	double	wallx;
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

#endif
