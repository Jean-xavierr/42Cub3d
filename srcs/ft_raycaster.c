/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raycaster.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/06 10:36:58 by jereligi          #+#    #+#             */
/*   Updated: 2020/01/24 11:22:19 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_init_ray(t_ray *ray)
{
	ray->planeX = 0;
	ray->planeY = 0.66;

}

void	ft_raycaster(t_storage *storage)
{
	t_ray	ray;

	ft_init_ray(&ray);	
	storage->ray = &ray;

}
