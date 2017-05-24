/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 14:51:08 by opicher           #+#    #+#             */
/*   Updated: 2015/12/01 15:50:27 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenint(int c)
{
	size_t i;

	i = 0;
	if (c < 0)
		i++;
	while (c != 0)
	{
		c = c / 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*s1;
	int				i;
	unsigned int	p;

	s1 = ft_strnew(ft_lenint(n) + 1);
	i = ft_lenint(n);
	if (n == 0)
		s1[0] = '0';
	if (n < 0)
		s1[0] = '-';
	p = n < 0 ? -n : n;
	while (p != 0)
	{
		i--;
		s1[i] = p % 10 + 48;
		p /= 10;
	}
	return (s1);
}
