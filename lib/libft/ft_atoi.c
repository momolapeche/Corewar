/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 14:06:48 by opicher           #+#    #+#             */
/*   Updated: 2016/03/14 17:08:08 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i;
	int sign;
	int a;

	a = 0;
	i = 0;
	sign = 1;
	while (ft_isspace(str[a]))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign = -1;
		a++;
	}
	while (str[a] >= '0' && str[a] <= '9')
	{
		i = i * 10;
		i = i + str[a] - '0';
		a++;
	}
	return (i * sign);
}
