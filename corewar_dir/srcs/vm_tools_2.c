/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_tools_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/24 14:45:18 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/02 20:11:03 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
**	get_mem_value récupère les ''size'' prochains octets dans l'arène et les
**	met dans un seul nombre qui sera ensuite renvoyé comme valeur de retour.
*/

int		get_mem_value(unsigned char *arena, int pc, int size)
{
	int					i;
	unsigned			number;
	unsigned			tmp;

	number = 0;
	tmp = 0;
	i = -1;
	while (pc < 0)
		pc += MEM_SIZE;
	while (++i < size && i < 4)
		((unsigned char *)&number)[size - i - 1] = arena[(pc + i) % MEM_SIZE];
	return (number);
}

/*
**	Au contraire de get_mem_value qui récupère le contenu de la mémoire
**	pour le transferer au sein d'une variable, print_mem_value tranfert
**	chaque octet de la variable ''value'' reçu en paramètre dans l'arène.
**	à la position donnée.
** 	"BIENVENUE DANS L"ARÈNE PEUPLE DE LA CITÉE IMPÉRIALE !"
*/

void	print_mem_value(t_info *info, int pos, unsigned value)
{
	int	i;
	int	c;

	c = 0;
	i = 3;
	while (pos < 0)
		pos += MEM_SIZE;
	while (c < 4)
	{
		info->arena[((pos + c) % MEM_SIZE)] = value >> (8 * i);
		i--;
		c++;
	}
}

t_proc	*create_proc(int pos, int count, t_igchamp *champ)
{
	t_proc	*proc;
	int		i;

	i = -1;
	if (!(proc = (t_proc *)malloc(sizeof(t_proc))))
		cor_error("NO MORE MEMORY");
	proc->igchamp = champ;
	proc->live = 0;
	proc->carry = 0;
	proc->preview = 0;
	while (pos < 0)
		pos += MEM_SIZE;
	proc->pc = pos % MEM_SIZE;
	proc->nb_cycle = 0;
	proc->next = NULL;
	while (++i < REG_NUMBER)
		proc->reg[i] = 0;
	proc->reg[0] = count;
	return (proc);
}

/*
**	write_help est une fonction qui se lance si on lance la vm sans parametres.
**	elle est censé afficher le template d'utilisaton de ladite vm.
**	pour l'instant, elle affiche du caca (littéralement),
**	il faudra donc la changer lorsque l'on saura comment utiliser la vm.
*/

int		write_help(void)
{
	write(1, "NO CHAMPIONS FOUND", 18);
	return (1);
}

/*
** print_arena est une fonction qui va imprimer le contenu de l'arène à un
** format convenable
*/
