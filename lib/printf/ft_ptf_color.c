/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/16 21:09:36 by opicher           #+#    #+#             */
/*   Updated: 2016/05/16 21:52:41 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ptf_colorb(t_cur_flag *cur)
{
	char *new;

	if (cur->larg_v == 0)
		new = ft_strdup("\033[0;34;40m");
	else
		new = ft_strdup("\033[0;40;34m");
	return (new);
}

char	*ptf_colorr(t_cur_flag *cur)
{
	char *new;

	if (cur->larg_v == 0)
		new = ft_strdup("\033[0;31;40m");
	else
		new = ft_strdup("\033[0;40;31m");
	return (new);
}

char	*ptf_colorg(t_cur_flag *cur)
{
	char *new;

	if (cur->larg_v == 0)
		new = ft_strdup("\033[0;32;40m");
	else
		new = ft_strdup("\033[0;40;32m");
	return (new);
}

char	*ptf_colory(t_cur_flag *cur)
{
	char *new;

	if (cur->larg_v == 0)
		new = ft_strdup("\033[0;33;40m");
	else
		new = ft_strdup("\033[0;40;33m");
	return (new);
}

char	*ptf_colorn(t_cur_flag *cur)
{
	char *new;

	if (cur->larg_v == 0)
		new = ft_strdup("\033[0;37;40m");
	else
		new = ft_strdup("\033[0;37;40m");
	return (new);
}
