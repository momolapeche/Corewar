/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tool.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 00:53:55 by ptao              #+#    #+#             */
/*   Updated: 2017/02/28 17:38:39 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*** Recherche un caractere dans une chaine de caracteres et raccourcit
*** la chaine au niveau du caractere, qui nest pas inclus.
*** Facultatif : Affichage du numero de ligne ou non (numline = -1)
*/

void	null_first_char(char **str, char c)
{
	char	*ptr;

	ptr = ft_strchr(*str, c);
	if (ptr != NULL)
		*ptr = 0;
}

/*
*** Retourne 1 la chaine en entree est numerique, sinon 0
*** Requis : str  chaine a scanner
*** Facultatif : NA
*/

int		ft_isnum_str(char *str)
{
	int	i;

	i = str[0] == '-' ? 1 : 0;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}
