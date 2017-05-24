/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 18:36:54 by opicher           #+#    #+#             */
/*   Updated: 2016/04/05 15:54:32 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	if (alst != NULL && del != NULL && alst[0] != NULL)
	{
		if (alst[0]->next != NULL)
			ft_lstdel(&((*alst)->next), del);
		ft_lstdelone(alst, del);
	}
}
