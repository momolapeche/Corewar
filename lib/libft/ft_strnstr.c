/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/24 17:00:06 by opicher           #+#    #+#             */
/*   Updated: 2015/11/24 18:43:14 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t i;
	size_t j;

	j = 0;
	if (*s2 == '\0')
		return ((char *)s1);
	while (s1[j] != '\0' && j != n)
	{
		i = 0;
		while (s1[i + j] == s2[i] && s2[i] != '\0' && i + j != n)
			i++;
		if (i + j == n && s2[i] != '\0')
			return (NULL);
		if (s2[i] == '\0' || s1[i + j] == s2[i])
			return ((char *)&s1[j]);
		j++;
	}
	return (NULL);
}
