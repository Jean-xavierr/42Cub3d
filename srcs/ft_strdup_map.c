/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/11 10:58:15 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/11 11:04:31 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

char	*ft_strdup_map(char *s)
{
	int		i;
	int		n;
	int		len;
	char	*dest;

	i = 0;
	len = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			len++;
		i++;
	}
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	n = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			dest[n++] = s[i];
		i++;
	}
	dest[n] = '\0';
	free(s);
	return (dest);
}
