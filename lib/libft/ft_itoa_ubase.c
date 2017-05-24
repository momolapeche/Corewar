/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ubase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:07:13 by opicher           #+#    #+#             */
/*   Updated: 2016/03/24 17:12:58 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenint_b(unsigned long long c, int base)
{
	size_t i;

	i = 0;
	while (c != 0)
	{
		c = c / base;
		i++;
	}
	return (i);
}

char			*ft_itoa_ubase(unsigned long long n, int base)
{
	char				*s;
	int					i;

	s = ft_strnew(ft_lenint_b(n, base) + 1);
	i = ft_lenint_b(n, base);
	if (n == 0)
		s[0] = '0';
	while (n != 0)
	{
		i--;
		if (n % base > 9)
			s[i] = n % base - 10 + 97;
		else
			s[i] = n % base + 48;
		n /= base;
	}
	return (s);
}
