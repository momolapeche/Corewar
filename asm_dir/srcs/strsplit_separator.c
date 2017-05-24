/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit_separator.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 00:30:37 by ptao              #+#    #+#             */
/*   Updated: 2017/03/04 20:30:38 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_getlenc(char *s, char c)
{
	int		i;
	int		ltot;

	ltot = 0;
	i = 0;
	while (s[i] != 0)
	{
		if (s[i] != c && s[i] != 9 && s[i] != 32)
			ltot++;
		i++;
	}
	return (ltot);
}

static int	nbchar(char *str, char c)
{
	int		count;
	int		i;

	i = 0;
	count = 0;
	while (str[i] != c && str[i] != 9 && str[i] != 32 && str[i] != 0)
	{
		count++;
		i++;
	}
	return (count);
}

static char	*make_str(char *dst, char *src, char c)
{
	int		i;

	i = 0;
	while (src[i] != 0 && src[i] != c && src[i] != 9 && src[i] != 32)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

static char	**make_tab(char **tab, char *s, char c)
{
	int		lgwrd;
	int		i;
	int		j;

	j = 0;
	i = 0;
	while (s[i] != 0)
	{
		while ((s[i] == c || s[i] == 9 || s[i] == 32) && s[i] != 0)
			i++;
		if (s[i])
		{
			lgwrd = nbchar(&s[i], c);
			tab[j] = (char*)malloc(sizeof(char) * (lgwrd + 1));
			if (tab[j] == NULL)
				return (NULL);
			tab[j] = make_str(tab[j], &s[i], c);
			j++;
			i = i + lgwrd;
		}
	}
	tab[j] = 0;
	return (tab);
}

char		**strsplit_separator(char const *s, char c)
{
	char	**tab;

	if (s == NULL)
		return (NULL);
	tab = (char**)malloc(sizeof(char*) * (ft_getlenc((char*)s, c) + 1));
	if (tab == NULL)
		return (NULL);
	tab = make_tab(tab, (char*)s, c);
	return (tab);
}
