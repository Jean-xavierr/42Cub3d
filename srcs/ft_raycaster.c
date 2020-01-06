/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:36:58 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/06 13:17:56 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_player(t_player *player)
{
	player->posX = 2;
	player->posY = 2;
	player->dirX = -1;
	player->dirY = 0;
	player->planeX = 0;
	player->planeY = 0.66;
}

void	ft_init_mlx(t_mlx *mlx, t_info *info_map)
{
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, info_map->rx, info_map->ry, "Cub3d");
}

void	ft_raycaster(t_info *info_map)
{
	t_player	player;
	t_mlx		mlx;	

	ft_init_player(&player);
	ft_init_mlx(&mlx, info_map);	
	mlx_loop(mlx.ptr);
}
