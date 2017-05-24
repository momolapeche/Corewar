/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_arena.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 15:03:59 by tguttin           #+#    #+#             */
/*   Updated: 2017/03/25 10:34:53 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

char g_hexa[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a',
	'b', 'c', 'd', 'e', 'f'};

void	print(unsigned char *tmp_arena, unsigned char *arena)
{
	unsigned char	c;
	int				count;

	count = -1;
	write(1, "\n\n\033[66A", 7);
	while (++count < MEM_SIZE)
	{
		if (arena[count] != 0)
			write(1, "\033[32m", 5);
		if (!(count % 64))
			write(1, "\n", 1);
		if (tmp_arena[count])
			write(1, "\033[31m", 5);
		c = g_hexa[arena[count] >> 4];
		write(1, &c, 1);
		c = g_hexa[arena[count] & 0xf];
		write(1, &c, 1);
		write(1, " ", 1);
		if (arena[count] != 0)
			write(1, "\033[0m", 5);
		if (tmp_arena[count])
			write(1, "\033[0m", 5);
	}
}

void	print_arena(unsigned char *arena, t_info *info)
{
	static unsigned char	tmp_arena[MEM_SIZE];
	t_proc					*tmp_proc;

	tmp_proc = info->proc;
	ft_bzero(tmp_arena, MEM_SIZE);
	while (tmp_proc)
	{
		tmp_arena[tmp_proc->pc] = 1;
		tmp_proc = tmp_proc->next;
	}
	print(tmp_arena, arena);
}
