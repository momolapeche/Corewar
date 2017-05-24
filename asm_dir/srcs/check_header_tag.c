/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_header_tag.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 01:15:46 by ptao              #+#    #+#             */
/*   Updated: 2017/03/08 17:39:35 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Affiche en message d'erreur un parametre de type char.
*** Requis : le caractere en erreur (tagchar)
*** Facultatif : Affichage du numero de ligne ou non (numline = -1)
*/

int		error_tagchar(char tagchar, int numline)
{
	char	prot[2];

	prot[0] = tagchar;
	prot[1] = 0;
	return (print_err("Invalid character detected", prot, numline));
}

/*
*** Quitte en erreur si une etiquette du header est mal formattee avec des
*** guillemets
*** Quitte en erreur si la valeur associee a l'etiquette nest pas alphanumerique
*** Facultatif : Affichage du numero de ligne ou non (numline = -1)
*/

int		check_header_tag_format(char *tag, int numline, char *tag_type)
{
	int		len;

	len = ft_strlen(tag);
	if (len < 1)
		return (print_err("No value for header tag", NULL, numline));
	if (tag[0] == '"')
	{
		if (len > 1 && tag[len - 2] != '\\' && tag[len - 1] == '"')
		{
			tag[len - 1] = 0;
			tag = &tag[1];
		}
	}
	else
		return (print_err("Unpaired quote in header", NULL, numline));
	return (check_tag(tag, numline, tag_type));
}

/*
*** Controle les etiquettes du header du champion.
*** Requis : le tableau, le nombre de lignes, booleen indiquant
*** la presence de l'etiquette nom ou commentaire.
*** Facultatif : Affichage du numero de ligne en erreur ou non (numline = -1)
*/

int		mark_header_tag(int nbword, char **line, int *bool, int numline)
{
	if (nbword != 0)
	{
		if (ft_strcmp(line[0], NAME_CMD_STRING) == 0)
			if (*bool == 1)
				return (print_err("Double header name tag", NULL, numline));
			else
				*bool |= 1;
		else if (ft_strcmp(line[0], COMMENT_CMD_STRING) == 0)
			if (*bool & 2)
				return (print_err("Double header comment tag", NULL, numline));
			else
				*bool |= 2;
		else
			return (print_err("Invalid header tag", line[0], numline));
	}
	return (1);
}

/*
***
*** Fonction qui extrait uniquement le nom/comment du header
*** pour le faire checker
*/

int		format_tag(char *str, int numline, char *tag_type)
{
	int	i;

	i = 0;
	while (str[i] == 32 || str[i] == 9)
		i++;
	while (str[i] != 32 && str[i] != 9)
		i++;
	while (str[i] == 32 || str[i] == 9)
		i++;
	return (check_header_tag_format(&str[i], numline, tag_type));
}
