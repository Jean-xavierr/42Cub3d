/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_2D.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 11:56:46 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/12 14:14:18 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

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
	int		x;
	int		y;

	x = 0;
	y = 0;
	i = 0;
	img = NULL;
	if ((mlx_ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if ((mlx_win = mlx_new_window(mlx_ptr, 640, 480, "Cub3d")) == NULL)
		return (printf("windows fail"));
	img = mlx_new_image(mlx_ptr, 640, 480);
	data_img = mlx_get_data_addr(img, &pixel, &size_line, &endian);
	// pixel = nombre de bits pour un pixel
	pixel = pixel / 8;
//	while (i < ((size_line / pixel) * 480))
	while (info_map->map[y])
	{
		write(1, "\n", 2);
		write(1, "Y", 1);
		while (info_map->map[y][x] != '\0')
		{
			if (info_map->map[y][x] == '1')
				*(int *)&data_img[i * pixel] = 16777215;
			x++;
			i++;
			write(1, "X", 2);
		}
		x = 0;
		y++;
		i++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img, 0 , 0);
	mlx_loop(mlx_ptr);
	return (0);
}
