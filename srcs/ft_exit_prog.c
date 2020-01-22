/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 14:52:34 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/22 14:54:11 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					ft_exit_prog(t_storage *storage)
{
	int		y;

	y = 0;
	while (storage->info->map[y])
	{
		free(storage->info->map[y]);
		y++;
	}
	free(storage->info->map[y]);
	free(storage->info->map);
	write(1, "FREE -> ", 8);
	mlx_clear_window(storage->mlx->ptr, storage->mlx->win);
	write(1, "CLEAR -> ", 9);
	mlx_destroy_window(storage->mlx->ptr, storage->mlx->win);
	write(1, "DESTROY \n", 7);
	exit(0);
	return (1);
}
