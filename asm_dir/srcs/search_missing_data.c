/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_missing_data.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:01:22 by ptao              #+#    #+#             */
/*   Updated: 2017/03/04 18:15:28 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Assure la continuite avec le module search_missing_data.
*** Si un caractere est present entre deux separateurs, la variable other
*** est incrementee.
*** Requis : l nouvelle chaine, sep1 ancienne chaine debutant par
*** un separateur, la variable other
*** Facultatif : NA
*/

void	search_missing_data01(char **l, char **sep1, int *other)
{
	*l = *sep1 + 1;
	while (**l != SEPARATOR_CHAR && **l != 0)
	{
		if (**l != 9 && **l != 3)
			*other = *other + 1;
		*l = *l + 1;
	}
}

/*
*** Verifie si des caracteres sont presents entre deux separateurs
*** Requis : l chaine a scanner
*** Facultatif : numero de ligne a afficher en erreur (ou non, si egal a -1)
*/

int		search_missing_data(char *l, int nb_line)
{
	char	*sep1;
	int		other;

	other = 1;
	while (*l != 0)
	{
		if (other == 0)
			return (print_err("Missing data between ,,", NULL, nb_line));
		sep1 = ft_strchr(l, SEPARATOR_CHAR);
		if (sep1 == NULL)
			break ;
		other = 0;
		if (ft_strchr(sep1 + 1, SEPARATOR_CHAR) != NULL)
			search_missing_data01(&l, &sep1, &other);
		else
			break ;
	}
	return (1);
}
