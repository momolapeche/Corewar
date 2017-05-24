/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writecom.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:14:51 by opicher           #+#    #+#             */
/*   Updated: 2017/03/02 19:46:52 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Fonction de traduction du comment present dans le .s pour le mettre
*** au format attendu du .cor
*/

static int	writecom(char *bin, char *n)
{
	int i;

	i = 0;
	if (ft_strstr(n, COMMENT_CMD_STRING) == NULL)
		return (-1);
	n = ft_strchr(n, '"') + 1;
	while (n[i] && i < COMMENT_LENGTH)
	{
		bin[i] = n[i];
		i++;
	}
	return (1);
}

int			ft_writecom(char *bin, t_champ *c)
{
	if (c != NULL)
	{
		while (c != NULL && ft_strstr(c->l, COMMENT_CMD_STRING) == NULL)
			c = c->next;
		if (c != NULL)
			writecom(bin, c->l);
		else
			ft_printf("error\n");
	}
	return (0);
}
