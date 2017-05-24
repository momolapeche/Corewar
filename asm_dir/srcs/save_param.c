/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_param.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 22:35:08 by ptao              #+#    #+#             */
/*   Updated: 2017/03/08 17:19:26 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static t_pa	*new_param(char **str, int numline, int i, int nb_words)
{
	t_pa	*new;

	new = NULL;
	if (i < nb_words)
	{
		new = (t_pa*)malloc(sizeof(t_pa));
		new->numline = numline;
		new->parm = ft_strdup(str[i]);
		new->next = new_param(str, numline, i + 1, nb_words);
	}
	return (new);
}

static t_pa	*param_lock(t_champ *body, char *ptr)
{
	char	**line;
	int		nbword;
	t_pa	*new;

	line = strsplit_separator(ptr, SEPARATOR_CHAR);
	nbword = chartab_nb_index(line);
	new = new_param(line, body->nb_line, 1, nbword);
	free_tab2(line, nbword);
	return (new);
}

static char	*ptr_lock(t_champ *body)
{
	char *ptr;

	if (body->label != NULL)
	{
		ptr = ft_strchr(body->l, LABEL_CHAR);
		ptr = ptr + 1;
	}
	else
		ptr = body->l;
	return (ptr);
}

t_pa		*save_parameters(t_champ *body)
{
	t_pa	*new;
	t_pa	*tmp;
	char	*ptr;

	new = NULL;
	tmp = NULL;
	if (body != NULL)
	{
		ptr = ptr_lock(body);
		if (ptr != NULL && ptr[0] != 0)
		{
			new = param_lock(body, ptr);
			if (new != NULL)
			{
				tmp = new;
				while (new != NULL && new->next != NULL)
					new = new->next;
				new->next = save_parameters(body->next);
			}
		}
		if (ptr == NULL || ptr[0] == 0 || new == NULL)
			return (save_parameters(body->next));
	}
	return (tmp);
}
