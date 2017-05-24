/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 14:34:18 by opicher           #+#    #+#             */
/*   Updated: 2016/03/15 17:16:33 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_letdec(char const *s, char c)
{
	size_t i;

	i = 0;
	while (s[i] != c && s[i] != 0)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		mot;

	if (!s)
		return (NULL);
	res = (char **)malloc((ft_motdec(s, c) + 1) * sizeof(char *));
	mot = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			res[mot] = ft_strsub(s, i, ft_letdec(&s[i], c));
			mot++;
			i += ft_letdec(&s[i], c);
		}
		else
			i++;
	}
	res[mot] = NULL;
	return (res);
}
