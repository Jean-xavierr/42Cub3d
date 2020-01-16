/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:56:46 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/12 15:41:13 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

/*
void		ft_mini_map(t_info *info_map, int x, int y, int color)
{
	int		n2;
	int		n3;
	int		n4;
	int 	line;
	int		size_line;

	n2 = 0;
	n4 = 0;

	t_x = (info_map->rx / 4) / taille de la ligne x;
	t_y = (info_map->ry / 4) / taille de la ligne y;
	size_line = img->size_line / 4;
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
i			*(int *)(&info->img.ptr[(line + n3) * info->img.bpp]) = color;
			n3++;
		}
		line = line + size_line;
		n2++;
	}
}
*/
/*
void	ft_draw_mini_map(t_info *info_map)
{
	int		x;
	int		y;

	x = 0;
	y = 0;
	while (x < info_map->rx)
	{
		y = 0;
		while (y < info_map->ry)
		{
			if (info_map->map[x][y] == '1')
				ft_mini_map(info_map, x, y, 16777215);
			y++;
		}
		x++;
	}
}*/

int		ft_map_2D(t_info *info_map)
{
	void	*mlx_ptr;
	void	*mlx_win;
	void	*img;
	char	*data_img;
	int		size_line;
	int		pixel;
	int 	endian;
	int		i;

	i = 0;
	img = NULL;
	if ((mlx_ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if ((mlx_win = mlx_new_window(mlx_ptr, 640, 480, "Cub3d")) == NULL)
		return (printf("windows fail"));
	img = mlx_new_image(mlx_ptr, 640, 480);
	data_img = mlx_get_data_addr(img, &pixel, &size_line, &endian);
//	printf("pixel = %d", pixel);
//	printf("size_line = %d", size_line);
	// pixel = nombre de bits pour un pixel
	pixel = pixel / 8;
	while (i < ((size_line / pixel) * info_map->ry))
	{
		*(int *)&data_img[i * pixel] = 16777215;
		i++;
	}
	//ft_draw_mini_map(info_map);
	mlx_put_image_to_window(mlx_ptr, mlx_win, img, 0 , 0);
	mlx_loop(mlx_ptr);
	return (0);
}
