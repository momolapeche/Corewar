/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_param.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/01 18:03:48 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 18:28:13 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

t_param	*ft_new_param(void)
{
	t_param *new;

	new = (t_param *)ft_memalloc(sizeof(t_param));
	new->val = NULL;
	new->label = NULL;
	new->next = NULL;
	return (new);
}
