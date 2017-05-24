/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_isindic.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 14:33:17 by opicher           #+#    #+#             */
/*   Updated: 2016/04/01 14:35:30 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ptf_isindic(char a)
{
	if (a == '+')
		return (1);
	if (a == '-')
		return (1);
	if (a == '#')
		return (1);
	if (a == ' ')
		return (1);
	return (0);
}
