/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chrlabel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 16:15:06 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 20:13:24 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void	ft_errorlabelunfound(t_champ *c, char *label)
{
	ft_printf("No such label %s while attempting to dereference");
	ft_printf(" token [TOKEN][%03d:", c->nb_line);
	ft_printf("%03d] ", ft_stristr(c->l, label) - 1);
	ft_printf("DIRECT_LABEL \"");
	ft_putchar('%');
	ft_printf(":%s\"\n", label);
}

static char	*ft_tradlab(int lab, int s)
{
	char *new;

	new = ft_strnew(s);
	ft_writenbr(lab, &new, s - 1);
	return (new);
}

static int	ft_calrev(t_champ *c, char *s)
{
	int		j;
	int		m;
	t_champ	*tmp;

	m = 0;
	j = 0;
	tmp = c;
	while (c->nb_line > 1 && m != 1)
	{
		if (c->label != NULL && ft_strcmp(c->label, s) == 0)
			m = 1;
		c = c->back;
		if (m != 1)
			j -= c->size;
	}
	if (m == 0)
	{
		ft_errorlabelunfound(tmp, s);
		exit(2);
	}
	return (j);
}

static char	*ft_calclab(t_champ *c, char *s, int size)
{
	char	*new;
	int		j;
	int		m;
	t_champ	*tmp;

	j = 0;
	m = 0;
	tmp = c;
	while (c != NULL && m != 1)
	{
		if (c->label != NULL && ft_strcmp(c->label, s) == 0)
			m = 1;
		else
			j += c->size;
		c = c->next;
	}
	if (c == NULL && m == 0)
		j = ft_calrev(tmp, s);
	new = ft_tradlab(j, size);
	return (new);
}

/*
*** fonction de cherche et de calcul des distance des label apres la premiere
*** traduction
*/

void		ft_chrlabel(t_champ *c)
{
	t_param *tmp;

	if (c != NULL && c->l != NULL)
	{
		tmp = c->param;
		while (tmp != NULL)
		{
			if (tmp->lab == 1 && tmp->label != NULL)
			{
				tmp->val = ft_calclab(c, tmp->label, tmp->s);
				tmp->lab = 0;
			}
			tmp = tmp->next;
		}
		if (c->next != NULL)
			ft_chrlabel(c->next);
	}
}
