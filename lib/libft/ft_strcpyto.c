/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpyto.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:54:14 by opicher           #+#    #+#             */
/*   Updated: 2016/01/21 16:00:16 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpyto(const char *src, int c)
{
	int		i;
	char	*dst;

	i = 0;
	dst = ft_strnew(ft_strlento(src, c));
	while (src[i] != c && src[i] != 0)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}
