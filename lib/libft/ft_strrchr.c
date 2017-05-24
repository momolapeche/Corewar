/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 12:19:06 by opicher           #+#    #+#             */
/*   Updated: 2015/12/02 14:57:35 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int j;

	j = -1;
	i = 0;
	while (s[i] != '\0')
	{
		if (((char *)s)[i] == (char)c)
			j = i;
		i++;
	}
	if (((char *)s)[j] == (char)c && j > -1)
		return ((char *)&s[j]);
	if (((char *)s)[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}
