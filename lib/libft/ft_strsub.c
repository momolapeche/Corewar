/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 17:56:51 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 20:51:07 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *sub;

	if (s != NULL)
	{
		if (s[start] == 0)
		{
			sub = ft_strnew(0);
			return (sub);
		}
		sub = ft_strnew(len + 1);
		ft_strncpy(sub, &s[start], len);
		return (sub);
	}
	return (NULL);
}
