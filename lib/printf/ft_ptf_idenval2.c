/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_idenval2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/08 15:33:42 by opicher           #+#    #+#             */
/*   Updated: 2016/04/13 15:13:24 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ptf_char(t_unknow u, t_cur_flag *cur)
{
	char *new;

	if (cur->type.flag == 'C' || cur->modif[0] == 'l')
		return (ft_ptf_utf8(u.wc));
	new = ft_strnew(1);
	if (u.c == 0)
		new[0] = '\0';
	else
		new[0] = u.c;
	if (cur->larg_v != 0)
		new = ptf_setlarg(new, cur);
	return (new);
}

char	*ptf_wildstr(t_unknow u, t_cur_flag *cur)
{
	char	*new;
	int		i;

	if (u.ui == 0 || u.s[0] == 0)
		new = ft_strdup("(null)");
	else
	{
		i = 0;
		new = ft_strnew(1);
		if (cur->prec_p != 0)
			new = ptf_setprecw(new, cur, u);
		else
			while (u.ws[i])
			{
				new = ft_strjoinndel(new, ft_ptf_utf8(u.ws[i]));
				i++;
			}
	}
	cur->prec = 0;
	if (cur->larg_v != 0)
		new = ptf_setlarg(new, cur);
	return (new);
}

char	*ptf_string(t_unknow u, t_cur_flag *cur)
{
	char *new;

	if (cur->modif[0] == 'l')
		return (ptf_wildstr(u, cur));
	if (u.s == NULL)
		new = ft_strdup("(null)");
	else
		new = ft_strdup(u.s);
	if (cur->prec_p != 0)
		new = ptf_setprecs(new, cur);
	cur->prec = 0;
	if (cur->larg_v != 0)
		new = ptf_setlarg(new, cur);
	return (new);
}

char	*ptf_purcent(t_cur_flag *cur)
{
	char *new;

	new = ft_strnew(1);
	new[0] = cur->type.flag;
	if (cur->prec_p > 0 && cur->larg_v != 0 && cur->prec != 0)
		new = ptf_setprec(new, cur);
	else
		cur->prec_p = 0;
	if (cur->larg_v > 0)
		new = ptf_setlarg(new, cur);
	return (new);
}
