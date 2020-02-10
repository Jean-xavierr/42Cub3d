/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:04:43 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/10 15:25:31 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_information_start(int error)
{
	if (error == -1)
		ft_putstr("Error: The programme cannot run without file [*.cub]\n");
	else if (error == 0)
	{
		ft_putstr("Error: To much argument, the programme can run only with");
		ft_putstr(" file [*.cub] and option --save\n");
	}
	else if (error == 1)
	{
		ft_putstr("Error: Extension of files no correct, put map in format");
		ft_putstr(" [*.cub]\n");
	}
	else if (error == 2)
		ft_putstr("Error: open(*.cub) failed\n");
	else if (error == 10)
		ft_putstr("Error: third argument no correct, only optin --save\n");
}

void	ft_information_error(int error, char *s)
{
	if (error == 3)
	{
		ft_putstr("Error: information no correct [");
		ft_putstr(s);
		ft_putstr("]\n");
	}
	else if (error == 4)
	{
		ft_putstr("Error: color for floor or ceil not correct [");
		ft_putstr(s);
		ft_putstr("]\nExemple : F 220,100,0\n");
	}
	else if (error == 10)
		ft_putstr("Error: Mutiple resolution, put only one resolution\n");
	else if (error == 11)
	{
		ft_putstr("Error: Duplicate texture [");
		ft_putstr(s);
		ft_putstr("]\n");
	}
}

void	ft_map_error(int error)
{
	if (error == 5)
		ft_putstr("Error: Map no valid, the map isn't surrounded by a wall\n");
	else if (error == 6)
	{
		ft_putstr("Error: Character in the map no valid, ");
		ft_putstr("put only [0,1,2,N,S,E,W]\n");
	}
	else if (error == 7)
		ft_putstr("Error: Multiple player positions\n");
	else if (error == 8)
		ft_putstr("Error: No player positions\n");
}

int		ft_management_error(int error, char *s)
{
	if (error >= -2 && error <= 2)
		ft_information_start(error);
	if (error == 3 || error == 4 || error == 10 || error == 11)
		ft_information_error(error, s);
	if (error >= 5 && error <= 8)
		ft_map_error(error);
	if (error == 9)
		ft_putstr(s);
	if (error == 4)
		return (-1);
	return (0);
}
