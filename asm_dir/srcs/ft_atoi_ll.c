/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/26 14:45:29 by ptao              #+#    #+#             */
/*   Updated: 2016/06/26 14:45:42 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_atoi_ll(const char *str)
{
	long long int	nbr;
	int				i;
	int				sign;

	sign = 0;
	i = 0;
	nbr = 0;
	while ((str[sign] >= 9 && str[sign] <= 13) || str[sign] == ' ')
		sign++;
	i = sign;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nbr = ((nbr * 10) + (str[i] - 48));
		i++;
	}
	if (str[sign] == '-')
		nbr = -nbr;
	return (nbr);
}
