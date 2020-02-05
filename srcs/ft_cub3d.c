/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 17:02:44 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/05 13:00:55 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_expose(t_storage *s)
{
	int		i;

	i = 0;
	s->mlx->img = mlx_new_image(s->mlx->ptr, s->info->rx, s->info->ry);
	s->mlx->data_img = mlx_get_data_addr(s->mlx->img, &s->mlx->bpixel,
	&s->mlx->size_line, &s->mlx->endian);
	s->mlx->bpixel = s->mlx->bpixel / 8;
	while (i < s->info->rx * (s->info->ry / 2))
		*(int *)&s->mlx->data_img[i++ * s->mlx->bpixel] = s->info->colorc;
	while (i < s->info->rx * (s->info->ry))
		*(int *)&s->mlx->data_img[i++ * s->mlx->bpixel] = s->info->colorf;
	ft_raycaster(s, s->ray);
	ft_draw_mini_map(s);
	ft_player_pos_cam(s, s->player);
	mlx_put_image_to_window(s->mlx->ptr, s->mlx->win, s->mlx->img, 0, 0);
	if (s->save == 0)
		mlx_destroy_image(s->mlx->ptr, s->mlx->img);
	if (s->move->esc == 1)
		ft_exit_prog(s);
	return (0);
}

int		ft_management_program(t_info *map, t_mlx *mlx)
{
	t_move		move;
	t_player	player;
	t_ray		ray;
	t_storage	storage;
	t_texture	texture[5];

	ft_init_struct_move(&move);
	ft_init_struct_player(&player);
	ft_init_struct_ray(&ray);
	storage.info = map;
	storage.mlx = mlx;
	storage.player = &player;
	storage.move = &move;
	storage.ray = &ray;
	ft_init_pos_player(&storage, &player);
	storage.save = 0;
	if ((mlx->ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if (!(mlx->win = mlx_new_window(mlx->ptr, map->rx, map->ry, "Cub3d")))
		return (printf("windows fail"));
	ft_init_texture(&storage, texture, 64, 64);
	mlx_hook(mlx->win, KEYPRESS_EVENT, KEYPRESS_MASK, ft_keypress, &move);
	mlx_hook(mlx->win, KEYRELEASE_EVENT, KEYRELEASE_MASK, ft_keyrelease, &move);
	mlx_loop_hook(mlx->ptr, ft_expose, &storage);
	mlx_loop(mlx->ptr);
	return (0);
}

int		ft_init_program(int save, char **av, t_mlx mlx)
{
	t_info	info_map;

	ft_init_struct_infomap(&info_map);
	if (!ft_read_management(av[1], &info_map))
		return (0);
	ft_check_len_map(&info_map);
	if (save == 1)
		ft_save(&info_map, &mlx);
	else
		ft_management_program(&info_map, &mlx);
	return (0);
}

int		main(int ac, char **av)
{
	int		save;
	t_mlx	mlx;

	save = 0;
	mlx.ptr = 0;
	if (ac < 2)
		ft_management_error(-1, "");
	else if (ac > 3)
		ft_management_error(0, "");
	else if (ac == 3)
	{
		if ((ft_strncmp(av[2], "--save", 7) != 0))
			return (ft_management_error(-2, ""));
		else
			save = 1;
	}
	if (ac == 2 || (ac == 3 && save == 1))
		ft_init_program(save, av, mlx);
	return (0);
}
