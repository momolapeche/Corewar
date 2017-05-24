/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:52:58 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 20:50:54 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_espace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

char		*ft_strtrim(char const *s)
{
	size_t i;
	size_t start;

	i = 0;
	if (s != NULL)
	{
		while (ft_espace(s[i]) == 1 && s[i] != 0)
			i++;
		start = i;
		i = ft_strlen(s + start);
		while (ft_espace(s[start + i - 1]) && i > 0)
			i--;
		return (ft_strsub(s, start, i));
	}
	return (NULL);
}
