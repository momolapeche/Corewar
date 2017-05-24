/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:17:30 by ptao              #+#    #+#             */
/*   Updated: 2017/04/01 18:00:17 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** Retourne 1 si le parametre est de type registre ou non
*** Requis : reg, chaine a scanner
*** Facultatif : NA
*/

int		ft_is_register(char *reg)
{
	int		len;
	long	num;

	len = ft_strlen(reg);
	if (len != 2 && len != 3)
		return (0);
	if (reg[0] != 'r')
		return (0);
	if (!ft_isnum_str(&reg[1]))
		return (0);
	num = ft_atoi_ll(&reg[1]);
	if (num < 1 || num > REG_NUMBER)
		return (0);
	return (1);
}

/*
*** Retourne 1 si la chaine en entree est de type numerique
*** Requis : par, chaine a scanner
*** Facultatif : NA
*/

int		valid_numeric_param(char *par)
{
	long	num;

	if (par[1] == '+' || par[1] == '-')
	{
		if (!ft_isnum_str(&par[2]))
			return (0);
	}
	else
	{
		if (!ft_isnum_str(&par[1]))
			return (0);
	}
	num = ft_atoi_ll(&par[1]);
	return (1);
}

/*
*** Retourne 1 si la chaine en entree est de type variable directe
*** Requis : par, chaine a scanner
*** Facultatif : NA
*/

int		ft_is_direct_param(char *par)
{
	if (par[0] != DIRECT_CHAR)
		return (0);
	if (par[1] == '+' || par[1] == '-' || ft_isdigit(par[1]))
	{
		if (!valid_numeric_param(par))
			return (0);
	}
	else if (par[1] == LABEL_CHAR)
	{
		if (par[2] == 0)
			return (0);
		if (!is_label_str(&par[2]))
			return (0);
	}
	else
		return (0);
	return (1);
}

/*
*** Retourne 1 si la chaine en entree est de type label avec le label_char
*** Requis : par, chaine a scanner
*** Facultatif : NA
*/

int		ft_is_label_param(char *par)
{
	if (par[0] != LABEL_CHAR)
		return (0);
	if (par[1] == 0)
		return (0);
	if (!is_label_str(&par[1]))
		return (0);
	return (1);
}
