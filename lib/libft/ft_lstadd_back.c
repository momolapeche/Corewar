/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/21 16:19:35 by opicher           #+#    #+#             */
/*   Updated: 2016/04/18 18:26:11 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **mail, t_list *new)
{
	if (*mail == NULL && new != NULL)
		*mail = new;
	else if (&((*mail)->next) != NULL)
		ft_lstadd_back(&((*mail)->next), new);
	else
		(*mail)->next = new;
}
