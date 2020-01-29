/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:02:44 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/29 13:48:31 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int					ft_expose(t_storage	*storage)
{
	int		i;

	i = 0;
	storage->mlx->img = mlx_new_image(storage->mlx->ptr, storage->info->rx, storage->info->ry);
	storage->mlx->data_img = mlx_get_data_addr(storage->mlx->img, &storage->mlx->bpixel, &storage->mlx->size_line, &storage->mlx->endian);
	storage->mlx->bpixel = storage->mlx->bpixel / 8;
	while (i < storage->info->rx * (storage->info->ry / 2))
	{
		*(int *)&storage->mlx->data_img[i * storage->mlx->bpixel] = 50;
		i++;
	}
	while (i < storage->info->rx * (storage->info->ry))
	{
		*(int *)&storage->mlx->data_img[i * storage->mlx->bpixel] = 3289700;
		i++;
	}
	ft_raycaster(storage);
	ft_draw_mini_map(storage);
	//ft_move_player_mini_map(storage);
	ft_player_pos_cam(storage, storage->player);
	mlx_put_image_to_window(storage->mlx->ptr, storage->mlx->win, storage->mlx->img, 0, 0);
	mlx_destroy_image(storage->mlx->ptr, storage->mlx->img);
	if (storage->move->esc == 1)
		ft_exit_prog(storage);
	return (0);
}

int		ft_management_programme(t_info *info_map, t_mlx *mlx)
{
	t_move		move;
	t_player	player;
	t_storage	storage;


	ft_init_struct_move(&move);
	ft_init_struct_player(&player);
	storage.info = info_map;
	storage.mlx = mlx;
	storage.player = &player;
	storage.move = &move;
	if ((mlx->ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if ((mlx->win = mlx_new_window(mlx->ptr, info_map->rx, info_map->ry, "Cub3d")) == NULL)
		return (printf("windows fail"));
	mlx_hook(mlx->win, KEYPRESS_EVENT, KEYPRESS_MASK, ft_keypress, &move);
	mlx_hook(mlx->win, KEYRELEASE_EVENT, KEYRELEASE_MASK, ft_keyrelease, &move);
 	mlx_loop_hook(mlx->ptr, ft_expose, &storage);
	mlx_loop(mlx->ptr);
	return (0);
}

int		main(int ac, char **av)
{
	t_info	info_map;
	t_mlx	mlx;

	mlx.ptr = 0;
	if (ac < 2)
		ft_error(-1, "");
	else if (ac > 2)
		ft_error(0, "");
	else
	{
		ft_init_struct_infomap(&info_map);
		ft_read_management(av[ac - 1], &info_map);
		ft_check_len_map(&info_map);
		ft_management_programme(&info_map, &mlx);
	}
/*	printf("texture |%s|\n", info_map.north_t);
	printf("texture |%s|\n", info_map.south_t);
	printf("texture |%s|\n", info_map.west_t);
	printf("texture |%s|\n", info_map.east_t);
	printf("texture |%s|\n", info_map.sprite_t);
	printf("colorf |%d|\n", info_map.colorf);
	printf("colorc |%d|\n", info_map.colorc);*/
	return (0);
}
