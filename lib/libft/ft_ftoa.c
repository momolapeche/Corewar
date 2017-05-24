/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 14:03:05 by opicher           #+#    #+#             */
/*   Updated: 2016/04/07 19:56:03 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_floatlen(double f)
{
	size_t	i;
	long	j;
	double	r;

	i = 0;
	j = f < 0 ? (long)-f : (long)f;
	r = f < 0 ? -f - j : f - j;
	if (f < 0)
		i++;
	while (j > 0)
	{
		i++;
		j /= 10;
	}
	while ((r - (long)r) != 0)
	{
		i++;
		r *= 10;
	}
	return (i);
}

static void		ft_rearg(double f, char *s, size_t i)
{
	size_t	j;
	size_t	k;
	char	*c;

	j = f < 0 ? 1 : 0;
	k = 0;
	c = ft_strnew(i);
	while (i != j)
	{
		c[k] = s[i];
		i--;
		k++;
		c[k] = s[i];
	}
	i = 0;
	while (c[i] != 0)
	{
		s[i + j] = c[i];
		i++;
	}
	free(c);
}

static void		ft_afterdot(char *new, size_t i, double r)
{
	if (r != 0)
	{
		new[i] = '.';
		i++;
	}
	while ((r - (long)r) != 0)
	{
		r *= 10;
		new[i] = (long)r % 10 + '0';
		i++;
	}
}

char			*ft_ftoa(double f)
{
	char	*new;
	size_t	i;
	long	j;
	double	r;

	i = f < 0 ? 1 : 0;
	j = f < 0 ? (long)-f : (long)f;
	r = f < 0 ? -f - j : f - j;
	new = ft_strnew(ft_floatlen(f + 1));
	if (f < 0)
		new[0] = '-';
	while (j > 0)
	{
		new[i] = j % 10 + '0';
		i++;
		j /= 10;
	}
	ft_rearg(f, new, i - 1);
	ft_afterdot(new, i, r);
	return (new);
}
