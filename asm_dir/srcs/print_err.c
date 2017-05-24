/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_err.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 00:51:39 by ptao              #+#    #+#             */
/*   Updated: 2017/03/04 18:47:33 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
*** Affiche un message d'erreur sur la sortie d'erreur et interrompt le
*** programme.
*** Requis : le tableau
*** Facultatif : Affichage du parametre en erreur ou non (param = NULL)
*** Facultatif : Affichage du numero de ligne en erreur ou non (numline = -1)
*/

int	print_err(char *str, char *param, int numline)
{
	char *tmp;

	tmp = NULL;
	ft_putstr_fd("ERROR : ", 2);
	ft_putstr_fd(str, 2);
	if (param != NULL)
	{
		ft_putstr_fd(" [", 2);
		ft_putstr_fd(param, 2);
		ft_putstr_fd("]", 2);
	}
	if (numline > 0)
	{
		ft_putstr_fd(" in line ", 2);
		tmp = ft_itoa(numline);
		ft_putstr_fd(tmp, 2);
		free(tmp);
	}
	ft_putstr_fd("\n", 2);
	return (-1);
}
