/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:00:06 by opicher           #+#    #+#             */
/*   Updated: 2017/02/28 16:27:14 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_stristr(const char *s1, const char *s2)
{
	int i;
	int j;

	j = 0;
	if (*s2 == '\0')
		return (0);
	while (s1[j] != '\0')
	{
		i = 0;
		while (s1[i + j] == s2[i] && s2[i] != '\0')
			i++;
		if (s2[i] == '\0')
			return (j);
		j++;
	}
	return (0);
}
