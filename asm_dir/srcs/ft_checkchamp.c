/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checkchamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:37:31 by tguttin           #+#    #+#             */
/*   Updated: 2017/03/08 17:22:26 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

void	free_list(t_pa *list)
{
	t_pa	*tmp;
	t_pa	*act;

	tmp = list;
	act = list;
	while (tmp != NULL)
	{
		act = tmp->next;
		free(tmp->parm);
		free(tmp);
		tmp = act;
	}
}

int		check_unique_label(t_champ *ref)
{
	t_champ	*tmp;
	t_champ	*ori;
	int		count;

	ori = ref;
	while (ori != NULL)
	{
		tmp = ref;
		count = 0;
		while (tmp != NULL)
		{
			if (tmp->label != NULL && ori->label != NULL)
				if (ft_strcmp(tmp->label, ori->label) == 0)
					count++;
			tmp = tmp->next;
		}
		if (count > 1)
			return (print_err("Multiple occurences of label", ori->label, -1));
		ori = ori->next;
	}
	return (1);
}

/*
*** Stockage des labels pour verifier la validite des parametres label
*/

void	save_label(char *str, t_champ *body)
{
	null_first_char(&str, COMMENT_CHAR);
	body->label = ft_islabel(str);
}

int		fill_struct_body(t_champ *body)
{
	t_pa	*list;
	char	*tmp;
	t_champ	*ref;
	int		i;

	i = 0;
	ref = body;
	while (body != NULL)
	{
		tmp = ft_strdup(body->l);
		save_label(tmp, body);
		free(tmp);
		body = body->next;
	}
	list = save_parameters(ref);
	if (check_label_characters(ref) != -1)
	{
		i = existing_label(ref, list);
		if (i != -1)
			i = check_unique_label(ref);
	}
	else
		i = -1;
	free_list(list);
	return (i);
}

int		check_champ(t_champ *champ)
{
	t_champ	*body;

	body = NULL;
	if (champ == NULL)
		return (print_err("Empty champion input", NULL, -1));
	if (check_champion_header(champ, &body) == -1)
		return (print_err("Incorrect champion header", NULL, -1));
	if (check_champion_body(body) == -1)
		return (print_err("Incorrect champion body", NULL, -1));
	return (fill_struct_body(body));
}
