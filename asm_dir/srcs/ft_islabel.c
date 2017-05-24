/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islabel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 19:13:43 by opicher           #+#    #+#             */
/*   Updated: 2017/03/08 16:42:31 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** prend une chaine de character et verifie au'il s'agit d'un label
*/

char	*ft_islabel(char *s)
{
	int		i;
	char	*new;

	i = 0;
	new = NULL;
	if (s != NULL && s[0] != 0)
	{
		while (s[i] && ft_strchr(LABEL_CHARS, s[i]) != NULL)
			i++;
		if (s[i] == LABEL_CHAR)
		{
			new = ft_strnew(i);
			ft_strncpy(new, s, i);
			return (new);
		}
	}
	return (new);
}
