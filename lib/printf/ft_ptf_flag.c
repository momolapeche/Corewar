/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/09 15:09:20 by opicher           #+#    #+#             */
/*   Updated: 2016/11/17 17:30:23 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_converttab g_list[] =
{
	{'d', ptf_int, 10},
	{'i', ptf_int, 10},
	{'u', ptf_unsigned, 10},
	{'U', ptf_long, 10},
	{'D', ptf_long, 10},
	{'o', ptf_unsigned, 8},
	{'O', ptf_long, 8},
	{'x', ptf_unsigned, 16},
	{'X', ptf_unsigned, 16},
	{'c', ptf_char, 0},
	{'C', ptf_char, 0},
	{'s', ptf_string, 0},
	{'S', ptf_wildstr, 0},
	{'p', ptf_point, 0},
	{'b', ptf_unsigned, 0},
	{'B', ptf_colorb, 0},
	{'R', ptf_colorr, 0},
	{'G', ptf_colorg, 0},
	{'Y', ptf_colory, 0},
	{'N', ptf_colorn, 0},
	{'r', ptf_returnline, 0},
	{'%', ptf_purcent, 0},
	{0, NULL, 0}
};

static int		ptf_indic_a(const char *c, t_cur_flag *a)
{
	int i;

	i = 0;
	if (c[0] == '0')
	{
		i++;
		a->flag_size += 1;
		a->larg_t = '0';
	}
	while (c[i] == '+' || c[i] == '-' || c[i] == ' ' || c[i] == '#')
	{
		ptf_indic_cplt(c[i], a);
		a->flag_size += 1;
		i++;
	}
	return (0);
}

static int		ptf_larg_a(const char *c, t_cur_flag *a, va_list ap)
{
	int	larg;

	larg = 0;
	a->larg_t = a->larg_t == '0' ? '0' : ' ';
	if (c[a->flag_size] == '*')
	{
		larg = va_arg(ap, int);
		a->flag_size += 1;
		if (larg < 0)
		{
			larg = -larg;
			a->i2 = '-';
		}
	}
	else
	{
		larg = ft_atoi(&c[a->flag_size]);
		if (larg != 0)
			a->flag_size += ft_intlen(larg);
	}
	a->larg_v = larg;
	return (larg);
}

static void		ptf_preci_a(const char *c, t_cur_flag *a, va_list ap)
{
	a->prec = 0;
	if (c[a->flag_size] == '.')
	{
		a->prec_p = 1;
		while (c[a->flag_size] == '.')
			a->flag_size += 1;
		if (c[a->flag_size] == '*')
		{
			a->prec = va_arg(ap, int);
			a->flag_size += 1;
			if (a->prec < 0)
			{
				a->prec_p = 0;
				a->prec = 0;
			}
		}
		if (ft_isdigit(c[a->flag_size]) && c[a->flag_size] != '%')
		{
			a->prec = ft_atoi(&c[a->flag_size]);
			a->flag_size += (a->prec == 0 ? 1 : ft_intlen(a->prec));
		}
	}
}

static void		ptf_modif_a(const char *c, t_cur_flag *a)
{
	if (*c == 'h' || *c == 'l' || *c == 'j' || *c == 'L' || *c == 'z')
	{
		a->modif[0] = c[0];
		a->flag_size++;
		if (c[1] == 'h' || c[1] == 'l')
		{
			a->modif[1] = c[1];
			a->flag_size++;
		}
	}
}

t_cur_flag		*ptf_analyse_flag(const char *c, va_list ap)
{
	t_cur_flag		*cur;
	int				j;

	cur = ptf_curflag_init();
	j = 0;
	while (ptf_isflag(c[FLAG_S]) == 1)
	{
		if (ptf_isindic(c[FLAG_S]) == 1 || c[FLAG_S] == '0')
			ptf_indic_a(&c[FLAG_S], cur);
		if ((c[FLAG_S] >= '1' && c[FLAG_S] <= '9') || c[FLAG_S] == '*')
			ptf_larg_a(c, cur, ap);
		if (c[FLAG_S] == '.')
			ptf_preci_a(c, cur, ap);
		if (ptf_ismodif(c[FLAG_S]) == 1)
			ptf_modif_a(&c[FLAG_S], cur);
	}
	while (g_list[j].flag != 0 && c[FLAG_S] != g_list[j].flag)
		j++;
	cur->type = g_list[j];
	if (cur->type.flag == 0)
		cur->unk = c[FLAG_S];
	if (cur->unk != 0 || cur->type.flag != 0)
		FLAG_S += 1;
	return (cur);
}
