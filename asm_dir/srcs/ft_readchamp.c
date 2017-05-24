/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readchamp.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:35:05 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 19:36:57 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
** ft_readline fonction recupere un fd venant des parametre fournit en argument
** du programme afin de lire le fichier et de placer le contenu dans une liste
** chainee de chaine de charactere (ligne par ligne).
*/

static t_champ	*ft_readline(int fd, t_champ *back, int i)
{
	char	*tmp;
	t_champ	*new;

	tmp = NULL;
	new = NULL;
	if (get_next_line(fd, &tmp) != 0)
	{
		new = (t_champ *)ft_memalloc(sizeof(t_champ));
		new->l = ft_strdup(tmp);
		new->nb_line = i;
		new->label = NULL;
		new->opcode = 0;
		new->size = 0;
		new->oct_crypt = 0;
		new->back = back;
		new->param = NULL;
		free(tmp);
		new->next = ft_readline(fd, new, ++i);
	}
	else
		free(tmp);
	return (new);
}

t_champ			*ft_readchamp(char *s)
{
	t_champ	*champ;
	int		fd;

	fd = open(s, O_RDONLY);
	if (fd == -1)
	{
		perror("Failed to read champion file ");
		exit(EXIT_FAILURE);
	}
	champ = ft_readline(fd, NULL, 1);
	return (champ);
}
