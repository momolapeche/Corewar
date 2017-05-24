/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:14:57 by opicher           #+#    #+#             */
/*   Updated: 2016/05/16 21:50:26 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#define LARG_V cur->larg_v

static char		*ptf_flag_use(va_list ap, t_cur_flag *cur)
{
	char		*resu;
	t_unknow	t;

	t.i = 0;
	if (ft_checkex(cur->type.flag) == 1)
		return (cur->type.f(cur));
	if (cur->type.flag == 0)
	{
		resu = ft_strnew(1);
		resu[0] = cur->unk;
		if (cur->prec_p != 0)
			cur->prec_p = 0;
		if (cur->larg_v != 0)
			resu = ptf_setlarg(resu, cur);
	}
	else
	{
		t = va_arg(ap, t_unknow);
		cur->val = t.i < 0 ? -1 : 1;
		resu = cur->type.f(t, cur);
	}
	return (resu);
}

static int		ptf_write(t_list *def, const char *s)
{
	int i;

	if (def == NULL)
		return (0);
	write(1, def->content, def->content_size);
	i = def->content_size + ptf_write(def->next, s);
	return (i);
}

static t_list	*ptf_listnewto(const char *s)
{
	t_list	*o;
	char	*tmp;

	tmp = ft_strcpyto(s, '%');
	o = ft_lstnew(tmp, ft_strlento(s, '%'));
	free(tmp);
	return (o);
}

static int		ptf_algo(const char *format, t_list *def, va_list ap)
{
	int			i;
	char		*tmp;
	t_cur_flag	*cur;

	cur = ptf_analyse_flag(format, ap);
	tmp = ptf_flag_use(ap, cur);
	if (FLAG_T == 'c' && cur->modif[0] != 'l')
		ft_lstadd_back(&def, ft_lstnew(tmp, cur->larg_v == 0 ? 1 : LARG_V));
	else if (FLAG_T == 'C' && tmp[0] == 0)
		ft_lstadd_back(&def, ft_lstnew(tmp, cur->larg_v == 0 ? 1 : LARG_V));
	else
		ft_lstadd_back(&def, ft_lstnew(tmp, ft_strlen(tmp)));
	i = cur->flag_size;
	ft_lstadd_back(&def, ptf_listnewto(&format[i]));
	free(tmp);
	ptf_freecur(cur);
	return (i);
}

int				ft_printf(const char *format, ...)
{
	int			i;
	va_list		ap;
	t_list		*def;

	i = 0;
	va_start(ap, format);
	def = ptf_listnewto(format);
	while (format[i])
	{
		if (format[i] == '%')
			i += ptf_algo(&format[i], def, ap);
		else
			i++;
	}
	va_end(ap);
	if (ptf_checkvalid(def) == -1)
	{
		ft_lstdel(&def, &ft_bzero);
		return (-1);
	}
	i = ptf_write(def, format);
	ft_lstdel(&def, &ft_bzero);
	return (i);
}
