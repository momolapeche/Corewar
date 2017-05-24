/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algotrad.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:49:23 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 23:07:31 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
*** fonction de calcul de l'octet d'encryptage
*/

static int		cryptoct(char **line, t_champ *c, int i)
{
	int		j;
	char	b;

	j = 0;
	b = 0;
	while (j < g_tab[i].index)
	{
		if ((g_tab[i].param[j] & ft_isparam(line[j])) > 0)
		{
			if (ft_isparam(line[j]) == T_REG)
				b = b | (REG_CODE << (6 - (j * 2)));
			if (ft_isparam(line[j]) == T_DIR)
				b = b | (DIR_CODE << (6 - (j * 2)));
			if (ft_isparam(line[j]) == T_IND)
				b = b | (IND_CODE << (6 - (j * 2)));
		}
		else
		{
			ft_printf("error on param\n");
			exit(3);
		}
		j++;
	}
	c->oct_crypt = b;
	return (1);
}

static t_param	*ft_opcrypt(char **line, t_champ *c, int i)
{
	t_param *param;

	if (line[i] && i < 3)
	{
		param = ft_new_param();
		param->s = 0;
		if (ft_isparam(line[i]) == T_REG)
			c->size += ft_paramreg(line[i], param);
		if (ft_isparam(line[i]) == T_DIR)
		{
			c->size += ft_labelsize(c->opcode);
			param->s = ft_labelsize(c->opcode);
			ft_paramdir(line[i], ft_labelsize(c->opcode), param);
			if (line[i][1] != 0 && line[i][1] == LABEL_CHAR)
				param->lab = 1;
			else
				param->lab = 0;
		}
		if (ft_isparam(line[i]) == T_IND)
			c->size += ft_paramind(line[i], param);
		param->next = ft_opcrypt(line, c, i + 1);
		return (param);
	}
	return (NULL);
}

/*
*** Fonction de recuperation de l'instruction et d'encryptage de l'instruction
*/

static void		foundoploop(t_champ *c, char **line, int j)
{
	int	i;

	i = 0;
	while (i <= 15)
	{
		if (ft_strcmp(line[j], g_tab[i].name) == 0)
		{
			c->opcode = g_tab[i].opcode;
			c->size += 1;
			if (g_tab[i].octet == 1)
				c->size += cryptoct(&line[j + 1], c, i);
			c->param = ft_opcrypt(&line[j + 1], c, 0);
		}
		i++;
	}
}

static void		foundop(t_champ *c)
{
	int		j;
	char	**line;

	j = 0;
	line = ft_strsplit_spacescom(c->l);
	if (c->label != NULL)
		free(c->label);
	c->label = ft_islabel(line[0]);
	while (line[j])
	{
		foundoploop(c, line, j);
		j++;
	}
	ft_freetabchar(line);
}

/*
*** Fonction de traduction du code present dans le .s pour le mettre au format
*** attendu pour le .cor
*** chaque fonction doit etre ecrit en binaire:
*** Premier octect = opcode de la fonction
*** IF (deuxieme octet = Si la fonction doit avoir un octect d'encryptage
*** (op_tab.octet == 1))
*** les octets suivant doivent cntenir les parametre de la fonction
*/

long			ft_algotrad(char *bin, t_champ *c)
{
	long	size;
	t_champ	*tmp;

	size = 0;
	tmp = c;
	while (c != NULL)
	{
		if (c->l != NULL && c->l[0] != COMMENT_CHAR)
		{
			foundop(c);
		}
		size += c->size;
		c = c->next;
	}
	ft_chrlabel(tmp);
	if (size < CHAMP_MAX_SIZE)
		bin = writedefbin(bin, tmp, 0);
	return (size);
}
