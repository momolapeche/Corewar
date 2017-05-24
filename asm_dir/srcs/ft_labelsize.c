/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_labelsize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:03:00 by opicher           #+#    #+#             */
/*   Updated: 2017/01/09 16:36:35 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Fonction de definition de la taille des parametre direct (label) en fonction
*** de l'operation/opcode
*/

int	ft_labelsize(int op_code)
{
	if (op_code == 1 || op_code == 2 || op_code == 6 || op_code == 7)
		return (4);
	if (op_code == 8 || op_code == 13)
		return (4);
	if (op_code == 9 || op_code == 10 || op_code == 11 || op_code == 12)
		return (2);
	if (op_code == 14 || op_code == 15)
		return (2);
	return (0);
}
