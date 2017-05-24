/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_fct_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 11:07:17 by tguttin           #+#    #+#             */
/*   Updated: 2017/03/24 11:07:19 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

const t_op g_op_tab2[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4, live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4, ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 4, st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 4, add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 4, sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4, and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4, or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4, xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2, zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1, 2, ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25, "store index", 1, 1, 2, sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2, cor_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4, lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14, 50, "long load index", 1, 1, 2, lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2, cor_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 4, aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0, NULL}

};

/*
**	Une fois que l'on sait que l'instruction est correctement formatée,
**	Une dernière fonction nous permet de récupérer l'argument en question
**	dans l'arène et de le stocker dans la variable 'value' de chaque structure
**	arguments. Il aurait été possible et logique de le faire dans la fonction
**	deal_mult_param mais cette dernière n'étant dèja pas à la norme... On ne
**	va pas lui rajouter d'autres instructions !
*/

void	get_param_value(t_param *param, unsigned char *arena, int pc)
{
	unsigned int	index;
	int				i;
	unsigned int	tmp;

	tmp = 0;
	index = 0;
	while (param[index].size != -1 && index < 3)
	{
		i = 0;
		param[index].value = 0;
		while (i < param[index].size)
		{
			param[index].value |= arena[(pc + i + tmp) % MEM_SIZE]
				<< (8 * (param[index].size - (i + 1)));
			i++;
		}
		if (param[index].type == T_REG)
			param[index].value -= 1;
		tmp += param[index].size;
		index += 1;
	}
}

void	increase_pc(t_info *info, t_proc *proc)
{
	proc->pc += 1 + g_op_tab2[proc->preview - 1].octet;
	if (info->param[0].size != -1 && g_op_tab2[proc->preview - 1].nb_param >= 1)
	{
		proc->pc += info->param[0].size;
		if (info->param[1].size != -1 &&
			g_op_tab2[proc->preview - 1].nb_param >= 2)
		{
			proc->pc += info->param[1].size;
			if (info->param[2].size != -1 &&
				g_op_tab2[proc->preview - 1].nb_param >= 3)
				proc->pc += info->param[2].size;
		}
	}
	proc->pc %= MEM_SIZE;
	clear_param(info->param);
}

void	get_val(unsigned char tmp, t_param *param, t_proc *proc, unsigned pos)
{
	if ((tmp & 0xc0) == 0x80)
	{
		param[pos].size = g_op_tab2[proc->preview - 1].label_size;
		param[pos].type = T_DIR;
	}
	else if ((tmp & 0xc0) == 0x40)
	{
		param[pos].size = 1;
		param[pos].type = T_REG;
	}
	else if ((tmp & 0xc0) == 0xc0)
	{
		param[pos].size = 2;
		param[pos].type = T_IND;
	}
}

void	deal_mult_param(unsigned char *arena, t_param *param, t_proc *proc)
{
	unsigned		pos;
	unsigned		cond;
	unsigned char	tmp;

	pos = 0;
	cond = 0x300;
	tmp = arena[(proc->pc + 1) % MEM_SIZE];
	while ((cond >>= 2) >> 2)
	{
		get_val(tmp, param, proc, pos);
		pos++;
		tmp <<= 2;
	}
}

/*
**	pars param est appellé a chaque cycle et ce sur chaque processus.
**	pars param va lire la mémoire et vérifier que l'index actuel du processus
**	courant dans la mémoire correspond à une instruction. Si oui, en fonction
**	de si cette dernière possède un octet d'encodage ou non, la fonction
**	deal_mult_param sera appelée. Sinon, l'instruction et son paramètre seront
**	récupérés et vérifés au sein de pars_param.
**	Si les arguments sont valides, la fonction renverra 1, et le tableau
**	param sera remplie comme il se doit.
**	Sinon la fonction renvoie 0.
*/

int		pars_param(t_info *info, t_proc *proc)
{
	if (g_op_tab2[proc->preview - 1].octet)
	{
		deal_mult_param(info->arena, info->param, proc);
		get_param_value(info->param, info->arena, proc->pc + 2);
		return (1);
	}
	else
	{
		info->param[0].size = g_op_tab2[proc->preview - 1].label_size;
		info->param[0].type = T_DIR;
		info->param[0].value = get_mem_value(info->arena,
			(proc->pc + 1) % MEM_SIZE, info->param[0].size);
		return (1);
	}
	return (0);
}
