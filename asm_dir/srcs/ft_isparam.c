/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isparam.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 14:15:44 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 23:05:11 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*cpylabel(char *s)
{
	char	*lab;
	int		i;

	i = 0;
	lab = ft_strnew(ft_strlen(s));
	while (s[i] != 0 && ft_strchr(LABEL_CHARS, s[i]) != NULL)
	{
		lab[i] = s[i];
		i++;
	}
	lab[i] = 0;
	return (lab);
}

void		ft_paramdir(char *l, int s, t_param *par)
{
	int		m;
	int		i;

	m = 0;
	i = s - 1;
	if (l[1] != LABEL_CHAR && ((l[1] >= '0' && l[1] <= '9') || l[1] == '-'))
	{
		m = ft_atoi(&l[1]);
		par->val = ft_strnew(s);
		ft_writenbr(m, &par->val, s - 1);
	}
	else if (l[1] == LABEL_CHAR)
		par->label = cpylabel(&l[2]);
	else
	{
		par->label = NULL;
		par->val = NULL;
	}
}

int			ft_paramind(char *l, t_param *param)
{
	int t;

	param->s = 2;
	if (l[0] != LABEL_CHAR)
	{
		param->val = ft_strnew(2);
		param->lab = 0;
		param->label = NULL;
		t = ft_atoi(l);
		ft_writenbr(t, &param->val, 1);
	}
	else
	{
		param->lab = 1;
		param->label = cpylabel(&l[1]);
	}
	return (2);
}

int			ft_paramreg(char *l, t_param *param)
{
	int t;

	param->lab = 0;
	param->val = ft_strnew(1);
	param->label = NULL;
	param->s = 1;
	t = ft_atoi(&l[1]);
	ft_writenbr(t, &param->val, 0);
	return (1);
}

int			ft_isparam(char *l)
{
	if (l != NULL)
	{
		if (l[0] == 'r')
			return (T_REG);
		if (l[0] == DIRECT_CHAR)
			return (T_DIR);
		if ((l[0] >= '0' && l[0] <= '9') || l[0] == '-' ||
			l[0] == LABEL_CHAR || l[0] == '+')
			return (T_IND);
	}
	return (0);
}
