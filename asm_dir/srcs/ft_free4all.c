/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free4all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:19:43 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 23:07:18 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void		ft_freeparam(t_param *par)
{
	if (par != NULL)
	{
		if (par->next != NULL)
			ft_freeparam(par->next);
		if (par->val != NULL)
			free(par->val);
		if (par->label != NULL)
			free(par->label);
		free(par);
	}
}

void		ft_freechamp(t_champ *c)
{
	int i;

	i = 0;
	if (c != NULL)
	{
		ft_freechamp(c->next);
		free(c->l);
		free(c->label);
		ft_freeparam(c->param);
		free(c);
	}
}

static void	ft_freebin(char **bin)
{
	int i;

	i = 0;
	while (i < 5)
	{
		free(bin[i]);
		i++;
	}
	free(bin);
}

void		ft_freetabchar(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void		ft_free4all(t_env *env, t_champ *c)
{
	if (c != NULL)
		ft_freechamp(c);
	if (env->bin != NULL)
		ft_freebin(env->bin);
	if (env != NULL)
		free(env);
}
