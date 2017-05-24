/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmenegau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 16:29:47 by rmenegau          #+#    #+#             */
/*   Updated: 2017/04/01 16:16:40 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

const t_op	g_op_tab[17] =
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

void		if_new_fct(t_proc *proc, unsigned char *arena)
{
	if (arena[proc->pc % MEM_SIZE] <= 16 && arena[proc->pc % MEM_SIZE] > 0)
	{
		proc->preview = arena[proc->pc % MEM_SIZE];
		proc->nb_cycle = g_op_tab[proc->preview - 1].nb_cycle - 1;
	}
	else
	{
		proc->pc++;
		proc->pc %= MEM_SIZE;
		proc->preview = -1;
	}
}

void		launch_new_fct(t_info *info, t_proc *proc)
{
	clear_param(info->param);
	if (proc->preview != -1 && g_op_tab[proc->preview - 1].fct != NULL)
	{
		if (pars_param(info, proc) && check_proto(info, proc))
		{
			maj_buffer(info, proc);
			g_op_tab[proc->preview - 1].fct(info, proc, info->param);
			if (proc->preview != 9)
				increase_pc(info, proc);
		}
	}
}

void		for_each_cycle(t_info *info, t_proc *proc, unsigned char *arena)
{
	info->nb_cycle++;
	if (info->dump && !(info->nb_cycle % info->limit_dump))
		print_arena(info->arena, info);
	else if (info->sdl && !(info->nb_cycle % info->limit_sdl))
	{
		launch_sdl(info);
		SDL_RenderPresent(info->renderer);
	}
	while (proc != NULL)
	{
		if (proc->nb_cycle == 0)
			if_new_fct(proc, arena);
		else if (--proc->nb_cycle == 0)
			launch_new_fct(info, proc);
		proc = proc->next;
	}
	if (info->sdl)
		check_event(info);
}

void		virtual_machine(unsigned char *arena, t_info *info)
{
	int			cycle;
	int			cycle_to_die;
	t_proc		*proc;

	cycle_to_die = CYCLE_TO_DIE;
	info->nb_cycle = 0;
	while (cycle_to_die > 0)
	{
		info->nb_live = 0;
		cycle = 0;
		while (++cycle <= cycle_to_die && (proc = info->proc))
			for_each_cycle(info, proc, arena);
		if (!(kill_reinit(&info->proc, info)))
			break ;
		if (info->nb_live >= NBR_LIVE || info->nb_checks == MAX_CHECKS)
		{
			cycle_to_die -= CYCLE_DELTA;
			info->nb_checks = 0;
			info->nb_live = 0;
		}
		else
			info->nb_checks++;
	}
	kill_reinit(&info->proc, info);
	choose_winner(info);
}
