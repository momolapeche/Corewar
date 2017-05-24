/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writename.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:14:51 by opicher           #+#    #+#             */
/*   Updated: 2017/03/08 16:23:44 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Fonction de traduction du nom present dans le fichier .s pour
*** le mettre au format attendu du .cor
*/

static int	writename(char *bin, char *n)
{
	int i;

	i = 0;
	if (ft_strstr(n, NAME_CMD_STRING) == NULL)
		return (-1);
	n = ft_strchr(n, '"') + 1;
	while (n[i] != 0 && i < PROG_NAME_LENGTH)
	{
		bin[i] = n[i];
		i++;
	}
	return (1);
}

int			ft_writename(char *bin, t_champ *c)
{
	if (c != NULL)
	{
		while (c != NULL && ft_strstr(c->l, NAME_CMD_STRING) == NULL)
			c = c->next;
		if (c != NULL)
			writename(bin, c->l);
		else
			ft_printf("error\n");
	}
	return (0);
}
