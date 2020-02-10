/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:02:53 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/10 15:46:06 by jereligi         ###   ########.fr       */
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
# include "includes/struct.h"

/*
** define
*/

# define KEYPRESS_EVENT 2
# define KEYPRESS_MASK 1
# define KEYRELEASE_EVENT 3
# define KEYRELEASE_MASK 2

/*
** Cub3d.c
*/
int		ft_expose(t_storage *storage);

/*
** ft_mini_map.c
*/
void	ft_color_wall_mini_map(t_storage *storage, int y, int x, int color);
void	ft_draw_mini_map(t_storage *storage);

/*
** ft_read_map
*/
int		ft_read_info(char *s, t_info *info_map);
int		ft_read_management(char *s, t_info *info_map);

/*
** ft_parse_info.c
*/
int		ft_check_extension(char *s);
int		ft_parse_info(t_info *info_map);
int		ft_parse_management(t_info *info_map, t_len_map *len);

/*
** ft_parse_map.c
*/
int		ft_parse_map_line_updown(t_info *info_map);
int		ft_parse_map_line_between(t_info *info_map, t_len_map *len);

/*
** ft_get_info.c
*/
int		ft_get_resolution(char *s, t_info *info_map);
int		ft_get_texture_path_north_south(char *s, t_info *info_map);
int		ft_get_texture_path_west_east_s(char *s, t_info *info_map);
int		ft_get_color(char *s, t_info *info_map);
int		ft_get_info_map(char *s, t_info *info_map);

/*
** ft_error.c
*/
int		ft_management_error(int error, char *s);

/*
** ft_init.c
*/
void	ft_init_struct_infomap(t_info *info_map);
void	ft_init_struct_move(t_move *move);
void	ft_init_struct_player(t_player *player);
void	ft_init_struct_ray(t_ray *ray);
void	ft_init_pos_player(t_storage *storage, t_player *player);

/*
** ft_init_storage.c
*/
void	ft_init_storage(t_info *info_map, t_mlx *mlx,
t_player *player, t_storage *storage);
void	ft_fill_storage(t_move *move, t_ray *ray, t_storage *storage);

/*
** ft_fill_map
*/
void	ft_check_len_map(t_info *info_map);

/*
** ft_exit_prog.c
*/
int		ft_exit_prog(t_storage *storage);

/*
** ft_keyboard_action.c
*/
int		ft_keyrelease(int keycode, t_move *move);
int		ft_keypress(int keycode, t_move *move);

/*
** ft_move_player_mini_map.c
*/
void	ft_move_player_mini_map(t_storage *storage);
void	ft_player_pos_cam(t_storage *storage, t_player *player);

/*
** ft_raycaster
*/
void	ft_raycaster(t_storage *storage, t_ray *ray);

/*
** ft_management_texture
*/
int		ft_init_texture(t_storage *storage, t_texture *texture, int w, int h);
void	ft_management_texture(t_storage *storage, t_ray *ray, int x);

/*
** ft_draw_wall_color
*/
void	ft_draw_wall_color(t_storage *storage, t_ray *ray, int x);

/*
** ft_draw_wall_texture
*/
void	ft_draw_wall_texture_sn(t_storage *s, t_texture *texture,
t_text_info *text_i, int x);
void	ft_draw_wall_texture_ew(t_storage *s, t_texture *texture,
t_text_info *text_i, int x);

/*
** ft_memcpy
*/
void	*ft_memcpy(void *dst, const void *src, int n);

/*
** ft_strncmp
*/
int		ft_strncmp(const char *s1, const char *s2, int n);

/*
** ft_save
*/
void	ft_save(t_info *info_map, t_mlx *mlx);

/*
** ft_parse_info_2
*/
int		ft_get_pos_player(t_info *info_map, int i, int x);
void	ft_get_sprite_nb(t_info *info_map);
void	ft_get_pos_sprite(t_info *info_map, t_storage *storage);

/*
** ft_sprite
*/
void	ft_management_sprite(t_storage *s, t_sprite *sprite, int sprite_nb);

/*
** ft_utils.c
*/
int		ft_strlen(char *s);
void	ft_putstr(char *s);
int		ft_is_wall(char c);
int		ft_atoi(char *s);
char	*ft_strjoin_point(char *s1, char *s2);
int		ft_verif_rgb_is_valid(int nb[4], int n);
int		ft_get_info_map_resolution(char *s, t_info *info_map);

/*
** ft_strdup_map.c
*/
char	*ft_strdup_map(char *s);

/*
** ft_strcpy.c
*/
char	*ft_strcpy(char *dest, char *src);

/*
** ft_get_next_line
*/
int		get_next_line(int fd, char **line);

/*
** ft_split.c
*/
char	**ft_split(char const *s, char c);

#endif
