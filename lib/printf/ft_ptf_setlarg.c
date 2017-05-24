/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_setlarg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/11 13:50:51 by opicher           #+#    #+#             */
/*   Updated: 2016/04/07 12:43:56 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ptf_t_s(char c)
{
	if (c == 'c')
		return (1);
	if (c == 'C')
		return (1);
	if (c == 's')
		return (1);
	if (c == 'S')
		return (1);
	return (0);
}

static char	*ptf_setempty(t_cur_flag *cur)
{
	char	*new;
	int		i;

	new = ft_strnew(cur->larg_v);
	i = 0;
	while (i < cur->larg_v)
	{
		if (cur->larg_t == '0' && cur->prec_p == 0 && cur->i2 != '-')
			new[i] = '0';
		else if (cur->larg_t == '0' && ptf_t_s(FLAG_T) == 1 && cur->i2 != '-')
			new[i] = '0';
		else
			new[i] = ' ';
		i++;
	}
	return (new);
}

static void	ptf_strcpy(char *new, char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		new[i] = s[i];
		i++;
	}
}

static void	larg_adjust(char *s, t_cur_flag *cur, char *new)
{
	if (s[0] == '-' && cur->prec == 0 && cur->larg_t == '0' && cur->i2 != '-')
	{
		new[0] = '-';
		new[cur->larg_v - ft_strlen(s)] = '0';
	}
	if (s[0] == ' ' && cur->prec_p == 0 && cur->larg_t == '0' && cur->i4 == ' ')
	{
		new[0] = ' ';
		new[cur->larg_v - ft_strlen(s)] = '0';
	}
	if (s[0] == '+' && cur->prec == 0 && cur->larg_t == '0' && cur->i2 != '-')
	{
		new[0] = '+';
		new[cur->larg_v - ft_strlen(s)] = '0';
	}
	if (cur->larg_t == '0' && cur->prec == 0 && cur->i2 != '-')
		if (cur->i3 == '#' && (cur->type.flag == 'x' || cur->type.flag == 'X'))
		{
			new[1] = new[cur->larg_v - ft_strlen(s) + 1];
			new[cur->larg_v - ft_strlen(s) + 1] = '0';
		}
}

char		*ptf_setlarg(char *s, t_cur_flag *cur)
{
	char	*new;

	if ((int)ft_strlen(s) < cur->larg_v && cur->larg_v > cur->prec)
	{
		new = ptf_setempty(cur);
		if (cur->type.flag == 'c' || cur->type.flag == 'C')
		{
			if (cur->i2 == '-')
				new[0] = s[0];
			else
				new[cur->larg_v - 1] = s[0];
		}
		else if (cur->i2 == '-' || (FLAG_T == 'p' && cur->larg_t == '0'))
			ptf_strcpy(new, s);
		else
			ptf_strcpy(&new[cur->larg_v - ft_strlen(s)], s);
		larg_adjust(s, cur, new);
		free(s);
		return (new);
	}
	return (s);
}
