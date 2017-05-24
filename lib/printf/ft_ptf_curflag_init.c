/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_curflag_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 17:12:01 by opicher           #+#    #+#             */
/*   Updated: 2016/04/01 15:40:21 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_cur_flag	*ptf_curflag_init(void)
{
	t_cur_flag *new;

	new = (t_cur_flag *)malloc(sizeof(t_cur_flag));
	new->i1 = 0;
	new->i2 = 0;
	new->i3 = 0;
	new->i4 = 0;
	new->flag_size = 1;
	new->larg_t = ' ';
	new->larg_v = 0;
	new->prec = 0;
	new->prec_p = 0;
	new->modif = ft_strnew(2);
	return (new);
}
