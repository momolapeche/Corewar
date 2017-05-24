/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 19:23:58 by opicher           #+#    #+#             */
/*   Updated: 2015/12/02 12:54:14 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *res;

	if (lst != NULL && f != NULL)
	{
		res = ft_lstnew(lst->content, lst->content_size);
		res = f(res);
		if (lst->next != NULL)
		{
			lst = lst->next;
			res->next = ft_lstmap(lst, f);
		}
		else
			lst = NULL;
		return (res);
	}
	return (NULL);
}
