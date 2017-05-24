/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_champion_header.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 00:44:43 by ptao              #+#    #+#             */
/*   Updated: 2017/03/08 19:17:26 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Supprime les backslashs de la chaine de caracteres a traiter
*** Requis : la chaine de caracteres a traiter str, longueur de la chaine
*** et un indicateur de modif initialise a 0
*** Si une suppression d antislash se produit, l'indicateur de modif prend
*** la valeur 1
*** Facultatif : NA
*/

void	replace_backslash(int *modif, int len, char **str)
{
	char	*tmp;
	int		i;

	tmp = *str;
	i = 0;
	while (i < len)
	{
		if (tmp[i] == '\\' && tmp[i + 1] == '"')
		{
			while (tmp[i])
			{
				tmp[i] = tmp[i + 1];
				i++;
			}
			*modif = 1;
		}
		i++;
	}
	*str = tmp;
}

/*
*** Retire les antislashs qui protegent les guillemets
*** Requis : la chaine de caracteres a traiter
*** Facultatif : NA
*/

void	remove_backslash_quote(char **str)
{
	int		len;
	char	*tmp;
	int		modif;

	tmp = *str;
	len = ft_strlen(tmp) - 1;
	modif = 1;
	while (modif)
	{
		modif = 0;
		replace_backslash(&modif, len, &tmp);
	}
	*str = tmp;
}

/*
*** Controle le header du champion et alimente la structure "body",
*** qui ne contient que le corps du champion.
*** Requis : la structure globale t_champ du champion
*** Facultatif : NA
*/

int		header_lock(t_champ *champ, int *bool)
{
	char	**line;
	int		nbword;
	int		i;

	line = ft_strsplit_whitespaces(champ->l);
	nbword = chartab_nb_index(line);
	i = mark_header_tag(nbword, line, bool, champ->nb_line);
	if (i != -1)
		i = format_tag(champ->l, champ->nb_line, line[0]);
	remove_backslash_quote(&(champ->l));
	if (line != NULL)
		free_tab2(line, nbword);
	return (i);
}

int		check_champion_header(t_champ *champ, t_champ **body)
{
	int		bool;
	int		i;

	bool = 0;
	i = 0;
	while (champ != NULL)
	{
		if (bool == 3)
		{
			*body = champ;
			return (1);
		}
		null_first_char(&champ->l, COMMENT_CHAR);
		if (champ->l[0] != 0 && champ->l != NULL)
		{
			i = header_lock(champ, &bool);
			if (i == -1)
				return (-1);
		}
		champ = champ->next;
	}
	return (1);
}
