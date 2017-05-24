/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/27 15:42:14 by opicher           #+#    #+#             */
/*   Updated: 2016/02/18 21:31:36 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base_check(char c, int base)
{
	if (base <= 10)
	{
		if (c >= '0' && c <= '0' + base - 1)
			return (1);
	}
	else
	{
		if (c >= '0' && c <= '9')
			return (1);
		if (ft_toupper(c) >= 'A' && ft_toupper(c) <= 'A' + base - 11)
			return (1);
	}
	return (0);
}

static int	ft_val_base(char c, int base)
{
	int a;

	a = 0;
	if (c >= '0' && c <= '0' + base - 1)
		a = c - '0';
	else
		a = ft_toupper(c) - 'A' + 10;
	return (a);
}

long long	ft_atoi_base(const char *str, int base)
{
	long long	i;
	int			sign;

	i = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_base_check(*str, base) != 0 && *str != '\0')
	{
		i = i * base;
		i = i + ft_val_base(*str, base);
		str++;
	}
	return (i * sign);
}
