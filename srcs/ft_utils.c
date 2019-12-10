/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 14:33:55 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/10 16:52:31 by jereligi         ###   ########.fr       */
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

int		ft_is_wall(char c)
{
	if (c == '1')
		return (1);
	return (0);
}

int		ft_atoi(char *str)
{
	int		i;
	int		nb;
	int		negpos;

	i = 0;
	nb = 0;
	negpos = 1;
	while ((str[i] == ' ') || (str[i] > 6 && str[i] < 14))
		i++;
	if (str[i] == '-')
		negpos = negpos * -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = nb * negpos;
	return (nb);
}

char	*ft_strjoin_point(char *s1, char *s2)
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
