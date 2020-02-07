/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_movement_player.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 13:47:58 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/05 14:25:03 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_move_player_mini_map(t_storage *s)
{
	s->player->x = (int)(s->player->pos_x * ((s->info->rx / 3) /
	s->info->len_x));
	s->player->y = (int)(s->player->pos_y * ((s->info->ry / 3) / s->info->len_y))
	* s->mlx->size_line / 4;
	*(int *)(&s->mlx->data_img[(int)(s->player->x + s->player->y + 1) *
	4]) = 255;
	*(int *)(&s->mlx->data_img[(int)(s->player->x + s->player->y - 1) *
	4]) = 255;
	*(int *)(&s->mlx->data_img[(int)(s->player->x + s->player->y +
	(s->mlx->size_line / 4)) * 4]) = 255;
	*(int *)(&s->mlx->data_img[(int)(s->player->x + s->player->y -
	(s->mlx->size_line / 4)) * 4]) = 255;
}

void	ft_player_pos_x(t_storage *s, t_player *p)
{
	if (s->move->left == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x - s->ray->plane_x
		* p->ms)] != '1')
			p->pos_x = p->pos_x - s->ray->plane_x * p->ms;
		if (s->info->map[(int)(p->pos_y - s->ray->plane_y * p->ms)]
		[(int)(p->pos_x)] != '1')
			p->pos_y = p->pos_y - s->ray->plane_y * p->ms;
	}
	if (s->move->right == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x + s->ray->plane_x
		* p->ms)] != '1')
			p->pos_x = p->pos_x + s->ray->plane_x * p->ms;
		if (s->info->map[(int)(p->pos_y + s->ray->plane_y * p->ms)]
		[(int)(p->pos_x)] != '1')
			p->pos_y = p->pos_y + s->ray->plane_y * p->ms;
	}
}

void	ft_player_pos_dir(t_storage *s, t_player *p)
{
	double	old_dir_x;
	double	old_plane_x;

	if (s->move->turn_left == 1)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(-p->rot_speed) - p->dir_y * sin(-p->rot_speed);
		p->dir_y = old_dir_x * sin(-p->rot_speed) + p->dir_y * cos(-p->rot_speed);
		old_plane_x = s->ray->plane_y;
		s->ray->plane_y = s->ray->plane_y * cos(p->rot_speed) - s->ray->plane_x
		* sin(p->rot_speed);
		s->ray->plane_x = old_plane_x * sin(p->rot_speed) + s->ray->plane_x
		* cos(p->rot_speed);
	}
	if (s->move->turn_right == 1)
	{
		old_dir_x = p->dir_x;
		p->dir_x = p->dir_x * cos(p->rot_speed) - p->dir_y * sin(p->rot_speed);
		p->dir_y = old_dir_x * sin(p->rot_speed) + p->dir_y * cos(p->rot_speed);
		old_plane_x = s->ray->plane_y;
		s->ray->plane_y = s->ray->plane_y * cos(-p->rot_speed) - s->ray->plane_x
		* sin(-p->rot_speed);
		s->ray->plane_x = old_plane_x * sin(-p->rot_speed) + s->ray->plane_x
		* cos(-p->rot_speed);
	}
}

void	ft_player_pos_cam(t_storage *s, t_player *p)
{
	if (s->move->foward == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x + p->dir_x
		* p->ms)] != '1')
			p->pos_x += p->dir_x * p->ms;
		if (s->info->map[(int)(p->pos_y + p->dir_y * p->ms)]
		[(int)(p->pos_x)] != '1')
			p->pos_y += p->dir_y * p->ms;
	}
	if (s->move->retreat == 1)
	{
		if (s->info->map[(int)(p->pos_y)][(int)(p->pos_x - p->dir_x
		* p->ms)] != '1')
			p->pos_x -= p->dir_x * p->ms;
		if (s->info->map[(int)(p->pos_y - p->dir_y * p->ms)]
		[(int)(p->pos_x)] != '1')
			p->pos_y -= p->dir_y * p->ms;
	}
	ft_player_pos_x(s, p);
	ft_player_pos_dir(s, p);
	if (s->move->sprint == 1)
		p->ms = 0.12;
	if (s->move->sprint == 0)
		p->ms = 0.07;
}
