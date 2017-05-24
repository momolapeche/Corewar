/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_motdec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/25 16:45:57 by opicher           #+#    #+#             */
/*   Updated: 2016/02/25 23:44:10 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_motdec(char const *s, char c)
{
	size_t	i;
	size_t	nb;

	if (s == NULL)
		return (0);
	i = 0;
	nb = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c && s[i] != 0)
				i++;
			nb++;
		}
		else
			i++;
	}
	return (nb);
}
