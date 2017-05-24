/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/28 16:31:13 by opicher           #+#    #+#             */
/*   Updated: 2016/04/28 16:41:33 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstchr(t_list *lst, char *s)
{
	if (lst == NULL)
		return (NULL);
	if (ft_strcmp(lst->content, s) == 0)
		return (lst);
	return (ft_lstchr(lst->next, s));
}
