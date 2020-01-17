/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:56:46 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/17 16:00:20 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"


void		ft_mini_map(t_info *info_map, t_mlx *mlx, int x, int y, int color)
{
	int		n2;
	int		n3;
	int		n4;
	int		t_x;
	int		t_y;
	int 	line;
	int		size_line;

	n2 = 0;
	n4 = 0;
	line = 0;
	t_x = (info_map->rx / 4) / info_map->len_y;
	t_y = (info_map->ry / 4) / info_map->len_x;
	size_line = mlx->size_line / 4;
	while (n2 < (x * t_x))
	{
		line = line + size_line;
		n2++;
	}
	n2 = 0;
	n4 = (y + 1) * t_y;
	while (n2 < t_x)
	{
		n3 = y * t_y;
		while (n3 < n4)
		{
			*(int *)(&mlx->data_img[(line + n3) * mlx->bpixel]) = color;
			n3++;
		}
		line = line + size_line;
		n2++;
	}
}

void	ft_draw_mini_map(t_info *info_map, t_mlx *mlx)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	mlx->endian = 0;
	while (info_map->map[x])
	{
		y = 0;
		while (info_map->map[x][y])
		{
			if (info_map->map[x][y] == '1')
				ft_mini_map(info_map, mlx, x, y, 000000);
			y++;
		}
		x++;
	}
}

int		ft_map_2D(t_info *info_map, t_mlx *mlx)
{
	int		i;

	i = 0;
	if ((mlx->ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if ((mlx->win = mlx_new_window(mlx->ptr, info_map->rx, info_map->ry, "Cub3d")) == NULL)
		return (printf("windows fail"));
	mlx->img = mlx_new_image(mlx->ptr, info_map->rx, info_map->ry);
	mlx->data_img = mlx_get_data_addr(mlx->img, &mlx->bpixel, &mlx->size_line, &mlx->endian);
	mlx->bpixel = mlx->bpixel / 8;
	printf("size_line %d", mlx->size_line);
	while (i < ((mlx->size_line / mlx->bpixel) * info_map->ry))
	{
		*(int *)&mlx->data_img[i * mlx->bpixel] = 16777215;
		i++;
	}
	ft_draw_mini_map(info_map, mlx);
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img, 0 , 0);
	mlx_loop(mlx->ptr);
	return (0);
}
