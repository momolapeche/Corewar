/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champion_body.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:10:01 by ptao              #+#    #+#             */
/*   Updated: 2017/03/08 18:44:55 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define INV_POS "Invalid position for LABEL_CHAR"

/*
*** Verifie le type de ligne du corps du champion
*** Requis : tableau 2 dim de char, nbre de lignes
*** Facultatif : numero de ligne
*/

int		check_body_line(int nbword, char **line, int nb_line)
{
	int	type;

	if (nbword == 1)
		return (check_label(line[0], nb_line));
	else
	{
		type = type_first_word(line[0], nb_line);
		if (type == 1)
			return (check_opline(&line[1], nb_line));
		else if (type == 2)
			return (check_opline(line, nb_line));
	}
	return (1);
}

/*
*** Teste le premier mot d'une ligne
*** Requis : le mot
*** Facultatif : numero de ligne
*/

int		check_first_word(char *l, int nb_line)
{
	int	i;

	if (l[0] == LABEL_CHAR)
		return (print_err("Undefined label", NULL, nb_line));
	i = 0;
	while (l[i])
	{
		if (l[i] == LABEL_CHAR && (l[i + 1] != 32 && l[i + 1] != 9 &&
									l[i + 1] != 0))
			return (print_err(INV_POS, NULL, nb_line));
		if (l[i] == 32 || l[i] == 9)
			break ;
		i++;
	}
	return (1);
}

/*
*** Verifie le corps du champion
*** Requis : structure t_champ
*/

int		check_champion_body(t_champ *champ)
{
	char	**line;
	int		nbword;
	int		i;

	i = 0;
	while (champ != NULL)
	{
		null_first_char(&champ->l, COMMENT_CHAR);
		i = check_first_word(champ->l, champ->nb_line);
		if (i != -1)
			i = check_misplaced_separator(champ->l, champ->nb_line);
		line = strsplit_separator(champ->l, SEPARATOR_CHAR);
		nbword = chartab_nb_index(line);
		if (nbword != 0 && i != -1)
			i = check_body_line(nbword, line, champ->nb_line);
		if (line != NULL)
			free_tab2(line, nbword);
		if (i == -1)
			return (-1);
		champ = champ->next;
	}
	return (1);
}
