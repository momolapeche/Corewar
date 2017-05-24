/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_separator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 00:59:05 by ptao              #+#    #+#             */
/*   Updated: 2017/04/01 23:01:35 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Verifie le cas derreur ou un separateur se trouve derriere un label
*** Requis : l chaine a scanner
*** Facultatif : numero de ligne a afficher en erreur (ou non, si egal a -1)
*/

int		search_separator_after_label(char *l, int nb_line)
{
	char	*sep1;

	sep1 = ft_strchr(l, LABEL_CHAR);
	if (sep1 != NULL)
	{
		sep1 = sep1 + 1;
		while (*sep1 == 9 || *sep1 == 32)
			sep1 = sep1 + 1;
		if (*sep1 == SEPARATOR_CHAR)
			return (print_err("Separator after label", NULL, nb_line));
	}
	return (1);
}

/*
*** Verifie si les cas d'erreur des separateurs
*** Requis : tabeau de caracteres a 2 dim contenant les mots d'une ligne
*** et nbword, le nombre de mots
*** Facultatif : numero de ligne a afficher en erreur (ou non, si egal a -1)
*/

int		check_separator_cases(int nbword, char **line, int nb_line)
{
	int	i;
	int	len;

	i = 1;
	if (nbword > 1)
		if (line[1][0] == SEPARATOR_CHAR)
			return (print_err("Invalid separator after op", line[0], nb_line));
	while (i < (nbword - 1))
	{
		len = ft_strlen(line[i]);
		if (line[i][len - 1] != SEPARATOR_CHAR)
		{
			if (line[i + 1][0] != SEPARATOR_CHAR)
				return (print_err("Missing separator after", line[i], nb_line));
		}
		else if (line[i][len - 1] == SEPARATOR_CHAR)
		{
			if (line[i + 1][0] == SEPARATOR_CHAR)
				return (print_err("Invalid separator after", line[i], nb_line));
		}
		i++;
	}
	return (1);
}

/*
*** Verifie s'il ne manque pas des separateurs
*** Requis : l chaine a scanner
*** Facultatif : numero de ligne a afficher en erreur (ou non, si egal a -1)
*/

int		search_missing_separator(char *l, int nb_line)
{
	char	*sep1;
	int		nbword;
	char	**line;
	char	*sep2;
	int		i;

	i = 0;
	sep2 = ft_strchr(l, 9);
	if (sep2 == NULL || ft_strchr(l, 32) < ft_strchr(l, 9))
		sep2 = ft_strchr(l, 32);
	sep1 = ft_strchr(l, LABEL_CHAR);
	if (sep1 == NULL || (sep1 != NULL && sep2 != NULL && sep2 < sep1))
		sep1 = l;
	else
		sep1 = sep1 + 1;
	if (*sep1 != 0)
	{
		line = ft_strsplit_whitespaces(sep1);
		nbword = chartab_nb_index(line);
		i = check_separator_cases(nbword, line, nb_line);
		free_tab2(line, nbword);
	}
	return (i);
}

/*
*** Verifie si les separateurs sont bien places
*** Requis : l chaine a scanner
*** Facultatif : numero de ligne a afficher en erreur (ou non, si egal a -1)
*/

int		check_misplaced_separator(char *l, int nb_line)
{
	int		length;

	if (l != NULL)
		if (search_missing_data(l, nb_line) == -1)
			return (-1);
	if (search_separator_after_label(l, nb_line) == -1)
		return (-1);
	if (search_missing_separator(l, nb_line) == -1)
		return (-1);
	if (l[0] == SEPARATOR_CHAR)
		return (print_err("Invalid first character", NULL, nb_line));
	length = ft_strlen(l);
	if (length > 0 && l[length - 1] == SEPARATOR_CHAR)
		return (print_err("Invalid last character", NULL, nb_line));
	return (1);
}
