/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 15:53:07 by opicher           #+#    #+#             */
/*   Updated: 2016/03/15 15:41:30 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *s, size_t t)
{
	void	*tmp;
	size_t	i;

	tmp = s;
	s = malloc(t);
	i = 0;
	while (i < t)
	{
		((char *)s)[i] = ((char *)tmp)[i];
		i++;
	}
	free(tmp);
	return (s);
}
