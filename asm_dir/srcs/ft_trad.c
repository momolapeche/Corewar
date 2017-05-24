/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trad.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 15:55:06 by opicher           #+#    #+#             */
/*   Updated: 2017/03/27 19:16:34 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char	*drawnmagic(char *bin)
{
	int i;
	int m;

	i = 3;
	m = COREWAR_EXEC_MAGIC;
	while (m > 0)
	{
		bin[i] = m % 256;
		m = m / 256;
		i--;
	}
	return (bin);
}

char		**new_bin(void)
{
	char **new;

	new = ft_memalloc(5 * sizeof(char*));
	new[0] = ft_memalloc(sizeof(unsigned int));
	new[1] = (char *)ft_memalloc(sizeof(char) * PROG_NAME_LENGTH);
	new[2] = ft_memalloc(sizeof(long));
	new[3] = (char *)ft_memalloc(sizeof(char) * COMMENT_LENGTH);
	new[4] = ft_memalloc(sizeof(char) * CHAMP_MAX_SIZE);
	return (new);
}

void		ft_programsize(char *bin, int size)
{
	int i;

	i = 7;
	while (size > 0)
	{
		bin[i] = size % 256;
		size = size / 256;
		i--;
	}
}

/*
*** fonction principale de traduction
*** met en place le Header binaire du fichier .cor (magic, nom, taille, comment)
*/

t_env		*ft_trad(t_champ *champ)
{
	long	size;
	t_env	*env;

	size = 0;
	env = (t_env *)ft_memalloc(sizeof(t_env));
	env->bin = new_bin();
	if (champ != NULL)
	{
		env->bin[0] = drawnmagic(env->bin[0]);
		ft_writename(env->bin[1], champ);
		ft_writecom(env->bin[3], champ);
		size = ft_algotrad(env->bin[4], champ);
	}
	else
		ft_printf("ERROR : Champion not read correctly");
	ft_programsize(env->bin[2], size);
	env->size = size;
	return (env);
}
