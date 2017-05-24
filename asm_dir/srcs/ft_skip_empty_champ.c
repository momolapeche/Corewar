/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_empty_champ.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 00:31:15 by ptao              #+#    #+#             */
/*   Updated: 2017/02/15 19:48:06 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int			scan_empty(char *str)
{
	if (str[0] != 0)
		return (0);
	return (1);
}

t_champ		*ft_skip_empty_champ(t_champ *champ)
{
	int		skip;
	char	*str;

	champ = champ->next;
	skip = 1;
	if (champ == NULL)
		return (NULL);
	while (skip)
	{
		if (ft_strcmp(champ->l, "") == 0)
			champ = champ->next;
		else
		{
			str = ft_strdup(champ->l);
			if (!scan_empty(str))
				skip = 0;
			else
				champ = champ->next;
			free(str);
		}
	}
	return (champ);
}
