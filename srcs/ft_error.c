/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 17:04:43 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/11 11:48:48 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(int error, char *s)
{
	if (error == -1)
		ft_putstr("Error: The programme cannot run without file [*.cub]\n");
	else if (error == 0)
	{
		ft_putstr("Error: To much argument, the programme can run only with");
		ft_putstr(" file [*.cub]\n");
	}
	else if (error == 1)
	{
		ft_putstr("Error: Extension of files no correct, put map in format");
		ft_putstr(" [*.cub]\n");
	}
	else if (error == 2)
		ft_putstr("Error: open(*.cub) failed\n");
	else if (error == 3)
	{
		ft_putstr("Error: information no correct |");
		ft_putstr(s);
		ft_putstr("|\n");
	}
	else if (error == 4)
		ft_putstr(s);
}
