/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jereligi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:11:23 by jereligi          #+#    #+#             */
/*   Updated: 2020/02/04 11:49:42 by jereligi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, int n)
{
	int					i;
	unsigned char		*src1;
	unsigned char		*src2;

	src1 = (unsigned char *)s1;
	src2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (src1[i] && src2[i] && src1[i] == src2[i] && i < n - 1)
		i++;
	return (src1[i] - src2[i]);
}
