/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:00:06 by opicher           #+#    #+#             */
/*   Updated: 2015/11/24 18:06:48 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int i;
	int j;

	j = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[j] != '\0')
	{
		i = 0;
		while (s1[i + j] == s2[i] && s2[i] != '\0')
			i++;
		if (s2[i] == '\0')
			return ((char *)&s1[j]);
		j++;
	}
	return (NULL);
}
