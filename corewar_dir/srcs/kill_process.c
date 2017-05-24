/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kill_process.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 13:43:48 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/01 19:40:10 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	cor_fork(t_info *info, t_proc *proc, t_param *param)
{
	t_proc		*new;
	int			y;
	int			value;

	y = -1;
	value = get_value(info, proc, param[0], Y_IDX_MOD);
	value = apply_idx_mod_int(value);
	new = create_proc(proc->pc + value, proc->reg[0], proc->igchamp);
	new->carry = proc->carry;
	new->live = proc->live;
	while (++y < REG_NUMBER)
		new->reg[y] = proc->reg[y];
	new->next = info->proc;
	info->proc = new;
}

/*
** Exactement comme fork mais sans % IDX_MOD sur le pc
** + couteux en terme de cycle, + de portée.
*/

void	cor_lfork(t_info *info, t_proc *proc, t_param *param)
{
	t_proc		*new;
	int			y;
	int			value;

	y = -1;
	value = get_value(info, proc, param[0], N_IDX_MOD);
	new = create_proc((proc->pc + value), proc->reg[0], proc->igchamp);
	new->carry = proc->carry;
	new->live = proc->live;
	while (++y < REG_NUMBER)
		new->reg[y] = proc->reg[y];
	new->next = info->proc;
	info->proc = new;
}

void	kill_process(t_proc **b_proc, t_info *info, t_proc *proc, t_proc *tmp)
{
	if ((proc = *b_proc))
		while (proc != NULL)
		{
			info->nb_live += proc->live;
			while (proc->next && proc->next->live == 0)
			{
				if (proc->next->next != NULL)
				{
					tmp = proc->next->next;
					free(proc->next);
					proc->next = tmp;
				}
				else
				{
					free(proc->next);
					proc->next = NULL;
				}
			}
			if (proc->live)
				proc->live = 0;
			proc = proc->next;
		}
}

int		kill_reinit(t_proc **beg_proc, t_info *info)
{
	t_proc		*proc;
	t_proc		*tmp;

	proc = NULL;
	while (*beg_proc && (*beg_proc)->live == 0)
	{
		tmp = (*beg_proc)->next;
		free(*beg_proc);
		*beg_proc = tmp;
	}
	kill_process(beg_proc, info, proc, tmp);
	if (info->proc == NULL)
		return (0);
	return (1);
}
