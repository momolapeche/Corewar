/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/27 11:25:30 by opicher           #+#    #+#             */
/*   Updated: 2015/12/01 15:15:32 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	void	*temp;
	size_t	i;

	temp = ft_memalloc(len);
	i = 0;
	while (i < len)
	{
		((char *)temp)[i] = ((char *)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char *)dest)[i] = ((char *)temp)[i];
		i++;
	}
	return (dest);
}
