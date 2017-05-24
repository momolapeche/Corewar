/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_opline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/13 01:16:38 by ptao              #+#    #+#             */
/*   Updated: 2017/03/31 22:14:02 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define INV_PAR "Invalid number of parameters for op"

/*
*** Verifie si le tableau de parametres en entree a 2 dim contient des
*** parametres de type autorise
*** Requis : line tableau 2 dim, i index de la table reference, iw index
*** du parametre de la ligne courante
*** Facultatif : numero de ligne
*/

int		valid_parameter_type(int iw, int i, char **line, int numline)
{
	int		valid;

	valid = 0;
	if ((g_tab[i]).param[iw - 1] & T_REG)
	{
		if (ft_is_register(line[iw]))
			valid = 1;
	}
	if ((g_tab[i]).param[iw - 1] & T_DIR)
	{
		if (ft_is_direct_param(line[iw]))
			valid = 1;
	}
	if ((g_tab[i]).param[iw - 1] & T_IND)
	{
		if (ft_isnum_str(line[iw]) || ft_is_label_param(line[iw]))
			valid = 1;
	}
	if (valid == 0)
		return (print_err("Invalid direct parameter", line[iw], numline));
	return (1);
}

/*
*** Verifie les operations
*** Requis : line tableau 2 dim
*** Facultatif : numero de ligne
*/

int		check_opline(char **line, int numline)
{
	int		nbword;
	int		i;
	int		iw;

	nbword = chartab_nb_index(line);
	i = 0;
	while (i < NB_OP)
	{
		if (ft_strcmp((g_tab[i]).name, line[0]) == 0)
			break ;
		i++;
	}
	if (i >= NB_OP)
		return (print_err("Invalid function name", line[0], numline));
	if ((g_tab[i]).index != (nbword - 1))
		return (print_err(INV_PAR, line[0], numline));
	iw = 1;
	while (iw < nbword)
	{
		if (valid_parameter_type(iw, i, line, numline) == -1)
			return (-1);
		iw++;
	}
	return (1);
}
