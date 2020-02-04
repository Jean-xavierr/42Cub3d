/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keyboard_action.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:57:01 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/04 10:42:49 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					ft_keyrelease(int keycode, t_move *move)
{
	printf("\nkeycode |%d| : ", keycode);
	if (keycode == 53)
		move->esc = 0;
	else if (keycode == 13)
		move->foward = 0;
	else if (keycode == 1)
		move->retreat = 0;
	else if (keycode == 0)
		move->left = 0;
	else if (keycode == 2)
		move->right = 0;
	else if (keycode == 123)
		move->turn_left = 0;
	else if (keycode == 124)
		move->turn_right = 0;
	else if (keycode == 257)
		move->sprint = 0;
	printf("0");
	return (0);
}

int					ft_keypress(int keycode, t_move *move)
{
	printf("\nkeycode |%d| : ", keycode);
	if (keycode == 53)
	{
		move->esc = 1;
		printf("esc");
	}
	else if (keycode == 13)
	{
		move->foward = 1;
		printf("forward");
	}
	else if (keycode == 1)
	{
		move->retreat = 1;
		printf("retreat");
	}
	else if (keycode == 0)
	{
		move->left = 1;
		printf("left");
	}
	else if (keycode == 2)
	{
		move->right = 1;
		printf("right");
	}
	else if (keycode == 123)
	{
		move->turn_left = 1;
		printf("turn left");
	}
	else if (keycode == 124)
	{
		move->turn_right = 1;
		printf("turn right");
	}
	else if (keycode == 257)
	{
		move->sprint = 1;
		printf ("sprint");
	}
	else if (keycode == 18)
		move->texture = 1;
	else if (keycode == 19)
		move->texture = 0;
	return (0);
}
