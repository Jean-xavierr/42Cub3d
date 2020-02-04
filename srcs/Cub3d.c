/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:02:44 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/04 18:34:18 by jereligi         ###   ########.fr       */
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
		*(int *)&storage->mlx->data_img[i * storage->mlx->bpixel] = storage->info->colorc;
		i++;
	}
	while (i < storage->info->rx * (storage->info->ry))
	{
		*(int *)&storage->mlx->data_img[i * storage->mlx->bpixel] = storage->info->colorf;
		i++;
	}
	ft_raycaster(storage, storage->ray);
	ft_draw_mini_map(storage);
	ft_player_pos_cam(storage, storage->player);
	mlx_put_image_to_window(storage->mlx->ptr, storage->mlx->win, storage->mlx->img, 0, 0);
	if (storage->save == 0)
		mlx_destroy_image(storage->mlx->ptr, storage->mlx->img);
	if (storage->move->esc == 1)
		ft_exit_prog(storage);
	return (0);
}

int		ft_management_programme(t_info *info_map, t_mlx *mlx)
{
	t_move		move;
	t_player	player;
	t_ray		ray;
	t_storage	storage;
	t_texture	texture[5];

	ft_init_struct_move(&move);
	ft_init_struct_player(&player);
	ft_init_struct_ray(&ray);
	storage.info = info_map;
	storage.mlx = mlx;
	storage.player = &player;
	storage.move = &move;
	storage.ray = &ray;
	ft_init_pos_player(&storage, &player);
	if ((mlx->ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if ((mlx->win = mlx_new_window(mlx->ptr, info_map->rx, info_map->ry, "Cub3d")) == NULL)
		return (printf("windows fail"));
	ft_init_texture(&storage, texture, 64, 64);
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
	int		save;

	save = 0;
	mlx.ptr = 0;
	if (ac < 2)
		ft_management_error(-1, "");
	else if (ac > 3)
		ft_management_error(0, "");
	else if (ac == 3)
	{
		if ((ft_strncmp(av[2], "--save", 7) != 0))
		{
			ft_management_error(9, "Error: third argument no correct, only option --save\n");
			return (0);
		}
		else
		{
			write(1, "save", 4);
			save = 1;
		}
	}
	if (ac == 2 || (ac == 3 && save == 1))
	{
		ft_init_struct_infomap(&info_map);
		if (!ft_read_management(av[1], &info_map))
			return (0);
		ft_check_len_map(&info_map);	
		if (save == 1)
			ft_save(&info_map, &mlx);
		else
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
