/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptf_isflag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 15:07:55 by opicher           #+#    #+#             */
/*   Updated: 2016/04/01 18:33:06 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ptf_isflag(char c)
{
	if (ptf_isindic(c) == 1)
		return (1);
	if (c >= '0' && c <= '9')
		return (1);
	if (ptf_ismodif(c) == 1)
		return (1);
	if (c == '.')
		return (1);
	if (c == '*')
		return (1);
	return (0);
}
