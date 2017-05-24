/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_first_word.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:03:06 by ptao              #+#    #+#             */
/*   Updated: 2017/03/27 17:48:24 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Verifie si le mot en parametre est un label. Rend 1 le cas echeant, sinon 0.
*** Requis : word chaine a scanner
*** Facultatif : NA
*/

int		is_label(char *wordsrc)
{
	int		len;
	char	*word;
	int		ret;

	ret = 0;
	word = ft_strdup(wordsrc);
	len = ft_strlen(word);
	if (len > 1)
	{
		if (word[len - 1] == LABEL_CHAR)
		{
			word[len - 1] = 0;
			if (is_label_str(word))
				ret = 1;
		}
		free(word);
		return (ret);
	}
	else
		free(word);
	return (ret);
}

/*
*** Recherche le mot en parametre dans le tableau qui contient
*** la liste des operations
*** Requis : word chaine a scanner
*** Facultatif : NA
*/

int		is_op(char *word)
{
	int	i;

	i = 0;
	while (i < NB_OP)
	{
		if (ft_strcmp((g_tab[i]).name, word) == 0)
			return (1);
		i++;
	}
	return (0);
}

/*
*** Teste le label.
*** Requis : label chaine a scanner
*** Facultatif : numero de lignes a afficher en cas d'erreur
*/

int		check_label(char *label, int numline)
{
	int		len;
	int		i;
	char	prot[2];

	len = ft_strlen(label);
	if (len < 2)
		return (print_err("Invalid value for label", label, numline));
	if (label[len - 1] != LABEL_CHAR)
		return (print_err("Incomplete label", label, numline));
	label[len - 1] = 0;
	i = 0;
	if (ft_strlen(label) > MAX_SIZE_LABEL)
		return (print_err("Oversized label", label, numline));
	while (label[i])
	{
		if (!is_label_char(label[i]))
		{
			prot[0] = label[i];
			prot[1] = 0;
			return (print_err("Invalid character detected", prot, numline));
		}
		i++;
	}
	return (1);
}

/*
*** Retourne 1 si le premier mot d'une ligne est un label,
*** 2 s'il s'agit d'une operation, sinon 0.
*** Requis : word, chaine a scanner
*** Facultatif : numero de lignes a afficher en cas d'erreur
*/

int		type_first_word(char *word, int numline)
{
	int		len;

	len = ft_strlen(word);
	if (len < 1)
		print_err("No value for first word", NULL, numline);
	if (is_label(word))
	{
		check_label(word, numline);
		return (1);
	}
	else
	{
		if (!is_op(word))
			print_err("Unknown op", word, numline);
		return (2);
	}
	return (0);
}
