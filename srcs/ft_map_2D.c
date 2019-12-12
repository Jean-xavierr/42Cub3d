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
	int		n;

	x = 0;
	y = 0;
	i = 0;
	n = 0;
	img = NULL;
	if ((mlx_ptr = mlx_init()) == NULL)
		return (printf("init fail"));
	if ((mlx_win = mlx_new_window(mlx_ptr, 640, 480, "Cub3d")) == NULL)
		return (printf("windows fail"));
	img = mlx_new_image(mlx_ptr, 640, 480);
	data_img = mlx_get_data_addr(img, &pixel, &size_line, &endian);
	printf("pixel = %d", pixel);
	printf("size_line = %d", size_line);
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
			{
				while (n < 22)
				{
					*(int *)&data_img[i * pixel] = 16777215;
					i++;
					n++;
				}
			}
			else if (info_map->map[y][x] == '0')
			{
				while (n < 22)
				{
					*(int *)&data_img[i * pixel] = 000000;
					i++;
					n++;
				}
			}
			n = 0;
			x++;
			write(1, "X", 2);
		}
		i++;
		x = 0;
		y++;
	}
	mlx_put_image_to_window(mlx_ptr, mlx_win, img, 0 , 0);
	mlx_loop(mlx_ptr);
	return (0);
}
