/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:17:24 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/01 16:14:15 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	maj_buf_st(t_info *info, t_proc *proc, int value)
{
	t_igchamp	*tmp;
	int			i;
	int			pc;
	int			sum;

	i = 0;
	tmp = info->igchamp;
	while (value < 0)
		value += MEM_SIZE;
	sum = value + 4;
	pc = value;
	while (tmp && tmp->id != proc->reg[0] && (++i))
		tmp = tmp->next;
	if (i == info->n_champ)
		i = -1;
	while (pc < sum)
	{
		info->buffer[pc % MEM_SIZE] = i;
		pc++;
	}
}

void	sti(t_info *info, t_proc *proc, t_param *param)
{
	int value;

	value = get_value(info, proc, param[1], Y_IDX_MOD);
	value += get_value(info, proc, param[2], Y_IDX_MOD);
	print_mem_value(info, apply_idx_mod_int(value) +
		proc->pc, proc->reg[param[0].value]);
	if (info->sdl)
		maj_buf_st(info, proc, apply_idx_mod_int(value) + proc->pc);
}

void	st(t_info *info, t_proc *proc, t_param *param)
{
	int tmp;

	if (param[1].type == T_REG)
		proc->reg[param[1].value] = proc->reg[param[0].value];
	else if (param[1].type == T_IND)
	{
		tmp = (proc->pc + apply_idx_mod((short)param[1].value));
		while (tmp < 0)
			tmp += MEM_SIZE;
		if (info->sdl)
			maj_buf_st(info, proc, tmp % MEM_SIZE);
		print_mem_value(info, tmp % MEM_SIZE, proc->reg[param[0].value]);
	}
}

void	lldi(t_info *info, t_proc *proc, t_param *param)
{
	int value;

	value = get_value(info, proc, param[1], N_IDX_MOD);
	value += get_value(info, proc, param[0], N_IDX_MOD);
	proc->reg[param[2].value] = get_mem_value(info->arena, proc->pc
		+ value, REG_SIZE);
	proc->carry = !proc->reg[param[2].value];
}

void	ldi(t_info *info, t_proc *proc, t_param *param)
{
	int value;

	value = get_value(info, proc, param[1], Y_IDX_MOD);
	value += get_value(info, proc, param[0], Y_IDX_MOD);
	value = apply_idx_mod_int(value);
	proc->reg[param[2].value] = get_mem_value(info->arena, proc->pc
		+ value, REG_SIZE);
}
