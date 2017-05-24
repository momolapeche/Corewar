/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_utf8.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/23 16:20:36 by opicher           #+#    #+#             */
/*   Updated: 2016/05/16 22:24:44 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static char	*ft_p_one(unsigned int c)
{
	char *s;

	s = ft_strnew(1);
	s[0] = c;
	return (s);
}

static char	*ft_p_two(unsigned int c)
{
	char *s;

	s = ft_strnew(2);
	s[0] = 0xc0 + ((c >> 6) & 0x1f);
	s[1] = 0x80 + (c & 0x3f);
	return (s);
}

static char	*ft_p_three(unsigned int c)
{
	char *s;

	s = ft_strnew(3);
	s[0] = 0xe0 + ((c >> 12) & 0xf);
	s[1] = 0x80 + ((c >> 6) & 0x3f);
	s[2] = 0x80 + (c & 0x3f);
	return (s);
}

static char	*ft_p_four(unsigned int c)
{
	char *s;

	s = ft_strnew(4);
	s[0] = 0xf0 + ((c >> 18) & 0x7);
	s[1] = 0x80 + ((c >> 12) & 0x3f);
	s[2] = 0x80 + ((c >> 6) & 0x3f);
	s[3] = 0x80 + (c & 0x3f);
	return (s);
}

char		*ft_ptf_utf8(unsigned int c)
{
	char *s;

	if (c < 0x80)
		s = ft_p_one(c);
	else if (c < 0x800)
		s = ft_p_two(c);
	else if (c < 0x10000)
		s = ft_p_three(c);
	else
		s = ft_p_four(c);
	return (s);
}
