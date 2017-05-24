/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writechamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 14:55:41 by opicher           #+#    #+#             */
/*   Updated: 2017/03/27 19:31:29 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void	ft_writechamp(int fd, t_env *env)
{
	char	*tmp;

	tmp = ft_strnew(4);
	write(fd, env->bin[0], sizeof(unsigned int));
	write(fd, env->bin[1], PROG_NAME_LENGTH);
	write(fd, env->bin[2], sizeof(long));
	write(fd, env->bin[3], COMMENT_LENGTH);
	write(fd, tmp, 4);
	write(fd, env->bin[4], env->size);
	free(tmp);
}
