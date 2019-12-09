/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 09:58:23 by jereligi          #+#    #+#             */
/*   Updated: 2019/12/09 13:40:54 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/get_next_line.h"

char	*ft_strdup_c(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	if (!(new = (char*)malloc(sizeof(char) *
		(ft_strlen_c(str, c) + 1))))
		return (NULL);
	while (str && str[i] && str[i] != c)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strcut_c(char *str, char c)
{
	int		i;

	i = 0;
	if (!(str))
		return (NULL);
	if (ft_is_c(str, c) == 0)
		return (NULL);
	while (str[i] != c)
		i++;
	i++;
	return (ft_strdup_c(&str[i], '\0'));
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	if (!(new = (char*)malloc(sizeof(char) *
	((ft_strlen_c(s1, '\0') + ft_strlen_c(s2, '\0') + 1)))))
		return (NULL);
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j])
		new[i++] = s2[j++];
	new[i] = '\0';
	free(s1);
	return (new);
}
