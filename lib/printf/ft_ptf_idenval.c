/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_idenval.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 14:19:09 by opicher           #+#    #+#             */
/*   Updated: 2016/04/05 18:19:44 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*ptf_int(t_unknow u, t_cur_flag *cur)
{
	char	*new;

	if (cur->modif[0] == 'l' || cur->modif[0] == 'z' || cur->modif[0] == 'j')
		return (ptf_long(u, cur));
	else if (cur->modif[0] == 'h' && cur->modif[1] == 'h')
		new = ft_itoa(u.c);
	else if (cur->modif[0] == 'h' && cur->modif[1] != 'h')
		new = ft_itoa(u.sd);
	else
		new = ft_itoa(u.i);
	if (cur->prec_p != 0)
	{
		if (u.i == 0 && cur->prec == 0)
			new[0] = '\0';
		else
			new = ptf_setprec(new, cur);
	}
	if (cur->i1 == '+' && u.i >= 0)
		new = ft_strjoinndel(ft_strdup("+"), new);
	else if (cur->i4 == ' ' && u.i >= 0)
		new = ft_strjoinndel(ft_strdup(" "), new);
	if (cur->larg_v != 0)
		new = ptf_setlarg(new, cur);
	return (new);
}

char		*ptf_long(t_unknow u, t_cur_flag *cur)
{
	char	*new;
	int		unsig;

	unsig = 0;
	if (cur->type.flag == 'U' || cur->type.flag == 'O')
		unsig = 1;
	if (unsig == 1)
		new = ft_itoa_ubase(u.ul, cur->type.base);
	else
		new = ft_itoa_base(u.l, cur->type.base);
	if (cur->prec_p != 0 && u.ul == 0)
		new = ptf_setprec(ft_strnew(0), cur);
	else if (cur->prec_p != 0)
		new = ptf_setprec(new, cur);
	if (cur->i1 == '+' && u.i > 0 && unsig != 1)
		new = ft_strjoinndel(ft_strdup("+"), new);
	else if (cur->i4 == ' ' && u.i > 0 && unsig != 1)
		new = ft_strjoinndel(ft_strdup(" "), new);
	if (cur->i3 == '#' && cur->type.flag == 'O' && new[0] != '0')
		new = ft_strjoinndel(ft_strdup("0"), new);
	if (cur->larg_v != 0)
		new = ptf_setlarg(new, cur);
	return (new);
}

char		*ptf_point(t_unknow u, t_cur_flag *cur)
{
	char *new;

	new = ft_itoa_base((long long)u.v, 16);
	if (cur->prec_p != 0)
	{
		if (u.v == 0)
			new = ptf_setprec(ft_strnew(0), cur);
		else
			new = ptf_setprec(new, cur);
	}
	new = ft_strjoinndel(ft_strdup("0x"), new);
	if (cur->larg_v != 0)
		new = ptf_setlarg(new, cur);
	return (new);
}

static char	*ft_strtoup(char *new)
{
	int i;

	i = 0;
	while (new[i])
	{
		new[i] = ft_toupper(new[i]);
		i++;
	}
	return (new);
}

char		*ptf_unsigned(t_unknow u, t_cur_flag *cur)
{
	char *new;

	if (cur->modif[0] == 'l' || cur->modif[0] == 'z' || cur->modif[0] == 'j')
		new = ft_itoa_ubase(u.ul, cur->type.base);
	else if (cur->modif[0] == 'h' && cur->modif[1] == 'h')
		new = ft_itoa_ubase(u.uc, cur->type.base);
	else if (cur->modif[0] == 'h' && cur->modif[1] != 'h')
		new = ft_itoa_ubase(u.usd, cur->type.base);
	else
		new = ft_itoa_ubase(u.ui, cur->type.base);
	if (cur->type.flag == 'X')
		ft_strtoup(new);
	if (cur->prec_p != 0 && u.i == 0 && cur->prec == 0)
		new[0] = '\0';
	else if (cur->prec_p != 0)
		new = ptf_setprec(new, cur);
	if (cur->i3 == '#' && cur->type.flag == 'x' && u.ul > 0)
		new = ft_strjoinndel(ft_strdup("0x"), new);
	if (cur->i3 == '#' && cur->type.flag == 'X' && u.ul > 0)
		new = ft_strjoinndel(ft_strdup("0X"), new);
	if (cur->i3 == '#' && cur->type.flag == 'o' && new[0] != '0')
		new = ft_strjoinndel(ft_strdup("0"), new);
	if (cur->larg_v != 0)
		new = ptf_setlarg(new, cur);
	return (new);
}
