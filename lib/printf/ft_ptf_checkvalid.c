/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_checkvalid.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/07 12:55:43 by opicher           #+#    #+#             */
/*   Updated: 2016/04/07 13:43:52 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ptf_checkvalid(t_list *def)
{
	if (def->content == NULL)
		return (-1);
	if (def->next != NULL)
		return (ptf_checkvalid(def->next));
	return (0);
}
