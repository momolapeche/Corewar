/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:29:16 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/02 15:56:51 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

const t_op g_op_tab3[17] =
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

int		proto_is_wrong(t_info *info, t_proc *proc, int i)
{
	proc->pc += g_op_tab3[proc->preview - 1].octet + 1;
	while (i-- > 0)
		if (info->param[i].size != -1)
			proc->pc += info->param[i].size;
	proc->pc %= MEM_SIZE;
	clear_param(info->param);
	return (0);
}

int		check_proto(t_info *info, t_proc *proc)
{
	int	i;
	int boul;

	boul = 0;
	i = -1;
	if (g_op_tab3[proc->preview - 1].octet)
	{
		while (++i < g_op_tab3[proc->preview - 1].nb_param)
		{
			if (info->param[i].size == -1 ||
				!(g_op_tab3[proc->preview - 1].params[i] & info->param[i].type))
				boul = 1;
			if (info->param[i].type == T_REG &&
				(info->param[i].value >= REG_NUMBER
					|| info->param[i].value < 0))
				boul = 1;
		}
		if (boul)
			return (proto_is_wrong(info, proc, i));
	}
	return (1);
}

void	free_all(t_igchamp *igchamp, t_champ *champ)
{
	if (igchamp || champ)
		free_all(igchamp ? igchamp->next : NULL, igchamp ? champ->next : NULL);
	if (igchamp)
		free(igchamp);
	if (champ)
		free(champ);
}

int		main(int argc, char *argv[])
{
	t_info info;

	ft_bzero(&info, sizeof(t_info));
	info.limit_sdl = 1;
	if (argc <= 1 && write_help())
		cor_error(NULL);
	else if (argc > MAX_ARGS_NUMBER + 1)
		cor_error("TOO MANY ARGUMENTS");
	else if (argc > 1)
		check_args(&info, argv, argc - 1);
	if (info.n_champ == 0)
		cor_error("bad argument(s)");
	info.igchamp = create_champ_tab(info.champs, &info);
	fill_arena(info.arena, &info);
	if (info.sdl)
		init_sdl(&info);
	virtual_machine(info.arena, &info);
	if (info.sdl)
		deal_sdl(&info);
	if (info.end)
		print_arena(info.arena, &info);
	free_all(info.igchamp, info.champs);
	return (0);
}
