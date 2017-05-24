/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 13:41:17 by opicher           #+#    #+#             */
/*   Updated: 2016/11/14 14:32:03 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 != NULL && s2 != NULL)
	{
		new = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
		while (s1[i] != 0)
		{
			new[i] = s1[i];
			i++;
		}
		while (s2[j] != 0)
		{
			new[i + j] = s2[j];
			j++;
		}
		return (new);
	}
	return (NULL);
}
