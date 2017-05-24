/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyze_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:53:40 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/01 21:16:45 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	get_number(int fd, void *var, int amount)
{
	char	*tmp;

	tmp = var;
	while (amount--)
		read(fd, &tmp[amount], 1);
}

void	analyze_header(t_champ *champ)
{
	get_number(champ->fd, &champ->header.magic, 4);
	if (champ->header.magic != COREWAR_EXEC_MAGIC)
		cor_error("bad file");
	read(champ->fd, champ->header.prog_name, PROG_NAME_LENGTH);
	get_number(champ->fd, &champ->header.prog_size, 8);
	read(champ->fd, champ->header.comment, COMMENT_LENGTH);
	champ->header.prog_name[PROG_NAME_LENGTH] = '\0';
	champ->header.comment[COMMENT_LENGTH] = '\0';
	if (champ->header.prog_size == 0 ||
			champ->header.prog_size > CHAMP_MAX_SIZE)
		cor_error("bad code");
	read(champ->fd, champ->code, champ->header.prog_size);
}

int		is_valid(int id, t_info *info)
{
	t_champ *tmp;

	tmp = info->champs;
	while (tmp)
	{
		if (id == tmp->id_champ)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int		give_id(t_info *info)
{
	static int id = -1;

	while (!is_valid(id, info))
		id--;
	return (id);
}

int		add_champ(t_info *info, char *champion, int id)
{
	t_champ		*champ;

	if (++info->n_champ > MAX_PLAYERS)
		cor_error("Too many champions");
	if (!(champ = (t_champ *)ft_memalloc(sizeof(t_champ))))
		cor_error("NO MORE MEMORY");
	if (info->f_number && id && is_valid(id, info))
		champ->id_champ = id;
	else
		champ->id_champ = give_id(info);
	if (!info->champs)
		info->champs = champ;
	else if (info->champs != NULL)
		get_add_end(info->champs)->next = champ;
	if ((champ->fd = open(champion, O_RDONLY)) == -1)
		return (0);
	analyze_header(champ);
	close(champ->fd);
	return (1);
}
