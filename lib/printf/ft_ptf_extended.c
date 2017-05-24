/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_extended.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 21:18:00 by opicher           #+#    #+#             */
/*   Updated: 2016/05/16 21:44:58 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_checkex(int c)
{
	if (c == 'B')
		return (1);
	if (c == 'R')
		return (1);
	if (c == 'G')
		return (1);
	if (c == 'G')
		return (1);
	if (c == 'Y')
		return (1);
	if (c == 'N')
		return (1);
	if (c == 'r')
		return (1);
	if (c == '%')
		return (1);
	return (0);
}

char	*ptf_returnline(t_cur_flag *cur)
{
	char *new;

	new = ft_strdup("\033[");
	new = ft_strjoinndel(new, ft_itoa(cur->larg_v));
	new = ft_strjoinndel(new, ft_strdup("A"));
	return (new);
}
