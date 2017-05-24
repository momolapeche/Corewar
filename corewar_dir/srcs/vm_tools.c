/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:44:09 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/01 21:25:46 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	Cette fonction est appelée à la fin de chaque instructions ainsi que dans
**	create_proc. Elle va réinitialiser le tableau param contenu dans chaque
**	processus.
*/

void	clear_param(t_param *param)
{
	param[0].type = 0;
	param[1].type = 0;
	param[2].type = 0;
	param[0].value = 0;
	param[1].value = 0;
	param[2].value = 0;
	param[0].size = -1;
	param[1].size = -1;
	param[2].size = -1;
}

void	choose_winner(t_info *info)
{
	t_champ		*winner;
	int			i;

	i = 0;
	winner = info->champs;
	while (winner && info->winner != winner->id_champ)
	{
		winner = winner->next;
		i++;
	}
	if (info->dump == 1)
		write(1, "\n\n", 2);
	write(1, "\n\033[35mLe joueur ", 16);
	ft_putnbr(winner->id_champ);
	write(1, " : ", 3);
	write(1, winner->header.prog_name, ft_strlen(winner->header.prog_name));
	write(1, " a gagné ! \033[0m\n", 17);
	info->win_name = winner->header.prog_name;
	info->winner = i;
}

int		apply_idx_mod(short value)
{
	if (value < 0)
		return (-(-value % IDX_MOD));
	return (value % IDX_MOD);
}

int		apply_idx_mod_int(int value)
{
	long	tmp;

	if (value < 0)
	{
		tmp = -value;
		return (-(tmp % IDX_MOD));
	}
	return (value % IDX_MOD);
}

int		get_value(t_info *info, t_proc *proc, t_param param, int boul)
{
	int tmp;

	if (param.type == T_REG)
		return (proc->reg[param.value]);
	else if (param.type == T_DIR)
		return (param.size == 2 ? (short)param.value : param.value);
	else if (param.type == T_IND)
	{
		tmp = (short)param.value;
		if (boul)
			tmp = apply_idx_mod(tmp);
		return (get_mem_value(info->arena, proc->pc + tmp, REG_SIZE));
	}
	return (0);
}
