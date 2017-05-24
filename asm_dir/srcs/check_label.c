/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_label.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 22:31:49 by ptao              #+#    #+#             */
/*   Updated: 2017/03/08 17:43:00 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"
#define INV_LAB "Invalid label char"
#define UND_LAB "Undefined label"

int		check_label_characters(t_champ *body)
{
	while (body != NULL)
	{
		if (body->label != NULL)
			if (!is_label_str(body->label))
				return (print_err(INV_LAB, body->label, body->nb_line));
		body = body->next;
	}
	return (1);
}

int		label_exists(char *str, t_champ *body)
{
	t_champ *tmp;

	tmp = body;
	while (tmp != NULL)
	{
		if (tmp->label != NULL)
			if (ft_strcmp(str, tmp->label) == 0)
				return (1);
		tmp = tmp->next;
	}
	return (0);
}

int		existing_label(t_champ *body, t_pa *list)
{
	int	bool;

	bool = 1;
	while (list != NULL)
	{
		if (list->parm[0] == DIRECT_CHAR && list->parm[1] == LABEL_CHAR)
		{
			bool = 0;
			if (label_exists(&(list->parm[2]), body))
				bool = 1;
		}
		if (bool == 0)
			return (print_err(UND_LAB, &(list->parm[2]), list->numline));
		list = list->next;
	}
	return (1);
}
