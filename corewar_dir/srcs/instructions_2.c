/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:15:27 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/01 19:45:43 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	live(t_info *info, t_proc *proc, t_param *param)
{
	t_igchamp	*tmp;
	t_champ		*tm;
	int			value;

	value = get_value(info, proc, param[0], Y_IDX_MOD);
	proc->live++;
	tmp = proc->igchamp;
	tm = info->champs;
	while (tmp != NULL && value != tmp->id)
		tmp = tmp->next;
	while (tm != NULL && value != tm->id_champ)
		tm = tm->next;
	if ((param[0].size = 4) && tmp != NULL)
	{
		info->winner = tmp->id;
		if (!info->dump && !info->end && !info->sdl)
		{
			write(1, "Un processus a dit que le joueur ", 33);
			write(1, tm->header.prog_name, ft_strlen(tm->header.prog_name));
			write(1, " est en vie.\n", 13);
		}
	}
}

void	aff(t_info *info, t_proc *proc, t_param *param)
{
	if (!info)
		return ;
	write(1, &(proc->reg[param[0].value]), 1);
}

void	zjmp(t_info *info, t_proc *proc, t_param *param)
{
	int value;

	if (!info)
		return ;
	if (proc->carry)
	{
		value = get_value(info, proc, param[0], Y_IDX_MOD);
		value = apply_idx_mod_int(value);
		proc->pc += value;
		while (proc->pc < 0)
			proc->pc += MEM_SIZE;
	}
	else
		proc->pc += 3;
	proc->pc %= MEM_SIZE;
	clear_param(info->param);
}

void	ld(t_info *info, t_proc *proc, t_param *param)
{
	proc->reg[param[1].value] = get_value(info, proc, param[0], Y_IDX_MOD);
	proc->carry = !proc->reg[param[1].value];
}

void	lld(t_info *info, t_proc *proc, t_param *param)
{
	proc->reg[param[1].value] = get_value(info, proc, param[0], N_IDX_MOD);
	proc->carry = !proc->reg[param[1].value];
}
