/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/23 19:19:46 by tguttin           #+#    #+#             */
/*   Updated: 2017/02/10 20:32:14 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	add(t_info *info, t_proc *proc, t_param *param)
{
	if (!info)
		return ;
	proc->reg[param[2].value] =
		proc->reg[param[0].value] + proc->reg[param[1].value];
	proc->carry = !proc->reg[param[2].value];
}

void	sub(t_info *info, t_proc *proc, t_param *param)
{
	if (!info)
		return ;
	proc->reg[param[2].value] =
		proc->reg[param[0].value] - proc->reg[param[1].value];
	proc->carry = !proc->reg[param[2].value];
}

void	and(t_info *info, t_proc *proc, t_param *param)
{
	proc->reg[param[2].value] = get_value(info, proc, param[0], Y_IDX_MOD)
		& get_value(info, proc, param[1], Y_IDX_MOD);
	proc->carry = !proc->reg[param[2].value];
}

void	or(t_info *info, t_proc *proc, t_param *param)
{
	proc->reg[param[2].value] = get_value(info, proc, param[0], Y_IDX_MOD)
	| get_value(info, proc, param[1], Y_IDX_MOD);
	proc->carry = !proc->reg[param[2].value];
}

void	xor(t_info *info, t_proc *proc, t_param *param)
{
	proc->reg[param[2].value] = get_value(info, proc, param[0], Y_IDX_MOD)
	^ get_value(info, proc, param[1], Y_IDX_MOD);
	proc->carry = !proc->reg[param[2].value];
}
