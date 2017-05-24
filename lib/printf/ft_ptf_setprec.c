/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_setprec.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 14:41:31 by opicher           #+#    #+#             */
/*   Updated: 2016/04/05 17:37:01 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ptf_setprec(char *s, t_cur_flag *cur)
{
	char	*new;
	int		i;

	if ((int)ft_strlen(s) <= cur->prec)
	{
		i = 0;
		new = ft_strnew((s[0] == '-' ? cur->prec + 1 : cur->prec));
		while (i < (s[0] == '-' ? cur->prec + 1 : cur->prec))
		{
			new[i] = '0';
			i++;
		}
		if (s[0] == '-')
		{
			s[0] = '0';
			new[0] = '-';
			i = cur->prec - ft_strlen(s) + 1;
		}
		else
			i = cur->prec - ft_strlen(s);
		ft_strcpy(&new[i], s);
		free(s);
		return (new);
	}
	return (s);
}

char	*ptf_setprecs(char *s, t_cur_flag *cur)
{
	char	*new;
	int		i;

	i = 0;
	new = ft_strnew(cur->prec);
	while (i < cur->prec)
	{
		new[i] = s[i];
		i++;
	}
	free(s);
	return (new);
}

char	*ptf_setprecw(char *s, t_cur_flag *cur, t_unknow u)
{
	int i;
	int size;

	i = 0;
	size = 0;
	while (size < cur->prec)
	{
		size += ft_strlen(ft_ptf_utf8(u.ws[i]));
		if (size <= cur->prec)
			s = ft_strjoinndel(s, ft_ptf_utf8(u.ws[i]));
		i++;
	}
	return (s);
}
