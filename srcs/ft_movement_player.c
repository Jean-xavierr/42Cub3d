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
	s->player->x = (int)(s->player->posX * ((s->info->rx / 3) /
	s->info->len_x));
	s->player->y = (int)(s->player->posY * ((s->info->ry / 3) / s->info->len_y))
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
		if (s->info->map[(int)(p->posY)][(int)(p->posX - s->ray->planeX
		* p->ms)] != '1')
			p->posX = p->posX - s->ray->planeX * p->ms;
		if (s->info->map[(int)(p->posY - s->ray->planeY * p->ms)]
		[(int)(p->posX)] != '1')
			p->posY = p->posY - s->ray->planeY * p->ms;
	}
	if (s->move->right == 1)
	{
		if (s->info->map[(int)(p->posY)][(int)(p->posX + s->ray->planeX
		* p->ms)] != '1')
			p->posX = p->posX + s->ray->planeX * p->ms;
		if (s->info->map[(int)(p->posY + s->ray->planeY * p->ms)]
		[(int)(p->posX)] != '1')
			p->posY = p->posY + s->ray->planeY * p->ms;
	}
}

void	ft_player_pos_dir(t_storage *s, t_player *p)
{
	double	old_dirx;
	double	old_planex;

	if (s->move->turn_left == 1)
	{
		old_dirx = p->dirX;
		p->dirX = p->dirX * cos(-p->rot_speed) - p->dirY * sin(-p->rot_speed);
		p->dirY = old_dirx * sin(-p->rot_speed) + p->dirY * cos(-p->rot_speed);
		old_planex = s->ray->planeY;
		s->ray->planeY = s->ray->planeY * cos(p->rot_speed) - s->ray->planeX
		* sin(p->rot_speed);
		s->ray->planeX = old_planex * sin(p->rot_speed) + s->ray->planeX
		* cos(p->rot_speed);
	}
	if (s->move->turn_right == 1)
	{
		old_dirx = p->dirX;
		p->dirX = p->dirX * cos(p->rot_speed) - p->dirY * sin(p->rot_speed);
		p->dirY = old_dirx * sin(p->rot_speed) + p->dirY * cos(p->rot_speed);
		old_planex = s->ray->planeY;
		s->ray->planeY = s->ray->planeY * cos(-p->rot_speed) - s->ray->planeX
		* sin(-p->rot_speed);
		s->ray->planeX = old_planex * sin(-p->rot_speed) + s->ray->planeX
		* cos(-p->rot_speed);
	}
}

void	ft_player_pos_cam(t_storage *s, t_player *p)
{
	if (s->move->foward == 1)
	{
		if (s->info->map[(int)(p->posY)][(int)(p->posX + p->dirX
		* p->ms)] != '1')
			p->posX += p->dirX * p->ms;
		if (s->info->map[(int)(p->posY + p->dirY * p->ms)]
		[(int)(p->posX)] != '1')
			p->posY += p->dirY * p->ms;
	}
	if (s->move->retreat == 1)
	{
		if (s->info->map[(int)(p->posY)][(int)(p->posX - p->dirX
		* p->ms)] != '1')
			p->posX -= p->dirX * p->ms;
		if (s->info->map[(int)(p->posY - p->dirY * p->ms)]
		[(int)(p->posX)] != '1')
			p->posY -= p->dirY * p->ms;
	}
	ft_player_pos_x(s, p);
	ft_player_pos_dir(s, p);
	if (s->move->sprint == 1)
		p->ms = 0.12;
	if (s->move->sprint == 0)
		p->ms = 0.07;
}
