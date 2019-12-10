/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 13:41:47 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/10 18:10:08 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_check_extension(char *s)
{
	int		i;
	int		n;
	char	*cub;

	i = 0;
	cub = ".cub";
	while (s[i])
	{
		n = 0;
		while (s[i + n] == cub[n] && cub[n])
		{
			if (s[i + n + 1] == '\0' && cub[n + 1] == '\0')
				return (1);
			n++;
		}
		i++;
	}
	return (0);
}

/*int		ft_parsing_info()
{
	return (1);
}*/

void		ft_parsing_management()
{

}
