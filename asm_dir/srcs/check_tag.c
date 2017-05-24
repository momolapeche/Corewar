/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tag.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptao <ptao@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 23:20:16 by ptao              #+#    #+#             */
/*   Updated: 2017/03/08 17:30:57 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"
#define INV_COM "Invalid length for command"

int		check_len(char *tag, int numline, int type, int limit)
{
	if (ft_strlen(tag) > (size_t)limit)
	{
		if (type == 1)
			return (print_err(INV_COM, "name type", numline));
		else
			return (print_err(INV_COM, "comment type", numline));
	}
	return (1);
}

/*
*** Verifie que les guillemets sont proteges
*** Retourne 1 si ok et 0 si ko
*** Requis : le chaine a verifier
*/

int		check_tag_char_quote(char *tag)
{
	int	i;
	int	len;

	len = ft_strlen(tag);
	i = 0;
	while (i < len)
	{
		if (tag[i] == '"')
			if (i == 0 || (i > 0 && tag[i - 1] != '\\'))
				return (0);
		i++;
	}
	return (1);
}

int		check_tag(char *tag, int numline, char *tag_type)
{
	int	limit;
	int	type;

	limit = 0;
	type = 0;
	if (ft_strcmp(tag_type, NAME_CMD_STRING) == 0)
	{
		type = 1;
		limit = PROG_NAME_LENGTH;
	}
	else if (ft_strcmp(tag_type, COMMENT_CMD_STRING) == 0)
	{
		type = 2;
		limit = COMMENT_LENGTH;
	}
	if (limit == 0)
		return (print_err("Undefined command string", NULL, numline));
	if (check_len(tag, numline, type, limit) == -1)
		return (-1);
	if (!check_tag_char_quote(tag))
		return (error_tagchar('"', numline));
	return (1);
}
