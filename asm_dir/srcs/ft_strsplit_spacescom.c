/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_spacescom.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 23:40:06 by ptao              #+#    #+#             */
/*   Updated: 2017/04/01 23:08:18 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int	ft_getlenc(char *s)
{
	int		i;
	int		ltot;

	ltot = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != '\t' && s[i] != ' ' && s[i] != SEPARATOR_CHAR &&
			s[i] != '\n')
			ltot++;
		i++;
	}
	return (ltot);
}

static int	nbchar(char *str)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != '\t' && str[i] != ' ' && str[i] != 0 &&
		str[i] != SEPARATOR_CHAR && str[i] != '\n')
	{
		count++;
		i++;
	}
	return (count);
}

static char	*make_str(char *dst, char *src)
{
	int		i;

	i = 0;
	while (src[i] != 0 && src[i] != '\t' && src[i] != ' ' &&
		src[i] != SEPARATOR_CHAR && src[i] != '\n')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**make_tab(char **tab, char *s)
{
	int		lgwrd;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i] != 0)
	{
		while (s[i] != 0 && (s[i] == '\t' || s[i] == ' ' ||
				s[i] == SEPARATOR_CHAR || s[i] == '\n'))
			i++;
		if (s[i])
		{
			lgwrd = nbchar(&s[i]);
			tab[j] = ft_strnew(lgwrd + 1);
			if (tab[j] == NULL)
				return (NULL);
			tab[j] = make_str(tab[j], &s[i]);
			j++;
			i = i + lgwrd;
		}
	}
	tab[j] = 0;
	return (tab);
}

char		**ft_strsplit_spacescom(char *s)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * (ft_getlenc((char*)s) + 1));
	if (tab == NULL)
		return (NULL);
	tab = make_tab(tab, s);
	return (tab);
}
