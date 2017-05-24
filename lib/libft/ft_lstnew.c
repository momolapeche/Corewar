/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 16:06:29 by opicher           #+#    #+#             */
/*   Updated: 2016/04/05 15:56:28 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *mail;

	mail = (t_list *)malloc(sizeof(t_list));
	if (content != NULL)
	{
		mail->content = ft_memalloc(sizeof(void *) * content_size);
		ft_memcpy(mail->content, content, content_size);
		mail->content_size = content_size;
		mail->next = NULL;
	}
	else
	{
		mail->content = NULL;
		mail->content_size = 0;
		mail->next = NULL;
	}
	return (mail);
}
