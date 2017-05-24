/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cor_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 13:43:02 by tguttin           #+#    #+#             */
/*   Updated: 2016/12/16 13:43:16 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Cor_error est la foncton d'error en géneral, lorsqu'une erreur survient,
** cor error est appellée. Le premier argument est la structure géneral;
** le deuxième argument est la chaine que l'on veut afficher si jamais le flag
** -e est actif.
*/

void		cor_error(char *str)
{
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(0);
}
