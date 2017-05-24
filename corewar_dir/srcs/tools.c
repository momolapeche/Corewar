/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:48:08 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/01 18:35:43 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int			get_id(t_info *info, int count)
{
	t_igchamp	*tmp;
	int			i;

	i = -1;
	tmp = info->igchamp;
	while (++i < count && tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->id);
}

/*
**	fill_arena est une fonction qui va remplir l'arène du 'code' des champions
**	fill arena créera également la liste capitale 'proc' contenu dans info.
**	Je sais pas pourquoi c'est fill arena qui s'occupe de cette dernière tâche
**	mais bon. Je devais être bourré ce jour là.
*/

void		put_new_at_end(t_proc *new, t_proc **begin)
{
	t_proc *tmp;

	if (*begin == NULL)
		*begin = new;
	else
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void		fill_arena(unsigned char *arena, t_info *info)
{
	float		size;
	int			count;
	t_champ		*tmp;
	t_proc		*tmp2;
	size_t		i;

	tmp = info->champs;
	size = MEM_SIZE / info->n_champ;
	count = -1;
	i = -1;
	while (++i < MEM_SIZE)
		info->buffer[i] = -1;
	while (++count < info->n_champ && !(i = 0))
	{
		while (i < tmp->header.prog_size)
		{
			arena[(int)(count * size + i)] = tmp->code[i];
			info->buffer[(int)(count * size + i)] = count;
			i++;
		}
		tmp2 = create_proc(count * size, info->f_number ?
			get_id(info, count) : -(count + 1), info->igchamp);
		put_new_at_end(tmp2, &info->proc);
		tmp = tmp->next;
	}
}

/*
** Create_champ_tab est une fonction qui va créer un liste contenant tous les
** champions ainsi que leur informations mais en jeu. Cette liste sera parcouru
** lors d'une instruction pour trouver le numéro de champion correspondant au
** numero trouvé.
*/

t_igchamp	*create_champ_tab(t_champ *champs, t_info *info)
{
	t_igchamp	*new;

	if (champs == NULL)
		return (NULL);
	if (!(new = (t_igchamp *)ft_memalloc(sizeof(t_igchamp))))
		cor_error("NO MORE MEMORY");
	new->id = champs->id_champ;
	info->winner = new->id;
	new->next = create_champ_tab(champs->next, info);
	return (new);
}

/*
** get_add_end est une fonction qui va renvoyer l'addresse du dernier maillon
** de la liste des champions.
*/

t_champ		*get_add_end(t_champ *champs)
{
	if (champs->next != NULL)
		return (get_add_end(champs->next));
	return (champs);
}
