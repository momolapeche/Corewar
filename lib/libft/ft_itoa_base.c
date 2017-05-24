/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:07:13 by opicher           #+#    #+#             */
/*   Updated: 2016/02/18 16:57:15 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenint_b(long long c, int base)
{
	size_t i;

	i = 0;
	if (c < 0)
		i++;
	while (c != 0)
	{
		c = c / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_base(long long n, int base)
{
	char				*s;
	int					i;
	unsigned long long	p;

	s = ft_strnew(ft_lenint_b(n, base) + 1);
	i = ft_lenint_b(n, base);
	if (n == 0)
		s[0] = '0';
	if (n < 0)
		s[0] = '-';
	p = n < 0 ? -n : n;
	while (p != 0)
	{
		i--;
		if (p % base > 9)
			s[i] = p % base - 10 + 97;
		else
			s[i] = p % base + 48;
		p /= base;
	}
	return (s);
}
