/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_small_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 00:56:45 by ptao              #+#    #+#             */
/*   Updated: 2017/02/15 18:59:56 by ptao             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "asm.h"

/*
*** Retourne 1 si la chaine est alphanumerique et en minuscule. Sinon,
*** elle retourne 0.
*** Requis : str chaine a scanner
*** Facultatif : NA
*/

int		ft_isalnum_small_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] < 97 || str[i] > 122) && !ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

/*
*** Retourne 1 si le caractere est valide pour un label
*** Requis : c caractere a scanner
*** Facultatif : NA
*/

int		is_label_char(char c)
{
	int	i;

	i = 0;
	while (i < 37)
	{
		if (c == LABEL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

/*
*** Retourne 1 si la chaine est valide pour un label
*** Requis : str chaine a scanner
*** Facultatif : NA
*/

int		is_label_str(char *str)
{
	int	i;
	int	len;
	int	bool;

	i = 0;
	len = ft_strlen(str);
	if (len == 1)
		return (0);
	while (i < len)
	{
		bool = is_label_char(str[i]);
		if (bool == 0)
			return (0);
		i++;
	}
	return (1);
}

/*
*** Retourne 1 la chaine en entree est alphabetique et en
*** minuscule, sinon 0
*** Requis : str  chaine a scanner
*** Facultatif : NA
*/

int		ft_isalpha_small_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 97 || str[i] > 122)
			return (0);
		i++;
	}
	return (1);
}
