/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:33:55 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/09 17:08:46 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int		ft_strlen(char *s)
{
	int		i;
	
	i = 0;
	if (s == NULL)
		return (0);
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int		i;

	i = 0;
	while (s[i])
		write(1, &s[i++], 1);
}

char		*ft_strjoin_point(char *s1, char *s2)
{
	int		i;
	int		n;
	int		len_s;
	char	*new_s;

	i = 0;
	len_s = ft_strlen(s1) + ft_strlen(s2);
	new_s = (char *)malloc(sizeof(char) * (len_s + 2));
	if (new_s == NULL)
		return (0);
	while (s1[i])
	{
		new_s[i] = s1[i];
		i++;
	}
	n = 0;
	while (s2[n])
		new_s[i++] = s2[n++];
	new_s[i++] = '.';
	new_s[i] = '\0';
	free(s1);
	return (new_s);
}
