/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_tool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 00:47:20 by ptao              #+#    #+#             */
/*   Updated: 2017/02/15 18:56:28 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Retourne le nombre de ligne dans un tableau de caracteres a 2 dim.
*** Requis : le tableau
*/

int		chartab_nb_index(char **tab)
{
	int	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

/*
*** Libere les tableaux de caractere a 2 dimensions.
*** Requis : le nombre de lignes du tableau
*/

void	free_tab2(char **tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}
