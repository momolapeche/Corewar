/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writedefbin.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/08 16:39:03 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 23:09:07 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** ecriture du code dans la chane de charactere "BIN" finale
*/

char	*writedefbin(char *bin, t_champ *c, int s)
{
	int		i;
	int		m;
	t_param *tmp;

	if (c != NULL)
	{
		i = (c->oct_crypt != 0 ? 2 : 1);
		bin[s] = c->opcode;
		if (c->oct_crypt != 0)
			bin[s + 1] = c->oct_crypt;
		tmp = c->param;
		while (tmp != NULL)
		{
			m = 0;
			while (m < tmp->s)
			{
				bin[s + i] = tmp->val[m];
				i++;
				m++;
			}
			tmp = tmp->next;
		}
		writedefbin(bin, c->next, s + c->size);
	}
	return (bin);
}
