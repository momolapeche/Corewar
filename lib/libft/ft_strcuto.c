/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcuto.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 15:38:43 by opicher           #+#    #+#             */
/*   Updated: 2016/01/21 15:58:18 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcuto(char *src, int c)
{
	int		i;
	char	*dst;

	i = 0;
	if (src == NULL)
		return (NULL);
	dst = ft_strnew(ft_strlento(src, c));
	while (src[i] != c && src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	free(src);
	return (dst);
}
