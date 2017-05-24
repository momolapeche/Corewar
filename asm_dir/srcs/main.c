/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/12 10:16:20 by opicher           #+#    #+#             */
/*   Updated: 2017/04/02 20:26:30 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

/*
 *** fonction du creation du nom du fichier .cor
*/

static char	*title(char *s)
{
	char *t;

	t = ft_memalloc(ft_strlen(s) + 3);
	ft_strncpy(t, s, ft_strlen(s) - 2);
	t = ft_strjoinndel(t, ft_strdup(".cor\0"));
	return (t);
}

/*
 *** fonction d'initialisation du char **bin (cf asm.h pour detail)
*/

static void	ft_createcor(t_env *env, char *t)
{
	int fd;

	fd = open(t, O_CREAT | O_TRUNC | O_WRONLY, 0600);
	ft_writechamp(fd, env);
	ft_printf("Writing output program to %s\n", t);
	close(fd);
}

int			ft_asm(char *s)
{
	t_champ		*champ;
	t_env		*env;
	char		*t;

	t = NULL;
	champ = ft_readchamp(s);
	if (check_champ(champ) == -1)
	{
		ft_freechamp(champ);
		return (-1);
	}
	else
		env = ft_trad(champ);
	if (env->bin != NULL)
	{
		t = title(s);
		if (env->size < CHAMP_MAX_SIZE)
			ft_createcor(env, t);
		else
			ft_printf("ERROR: Champion %s too long\n", s);
		ft_free4all(env, champ);
		free(t);
	}
	return (1);
}

void		run_asm(int i, char **argv, int argc)
{
	if (argc > 2)
		ft_printf("Compile file : %s\n", argv[i]);
	if (ft_strstr(argv[i], ".s\0") == NULL)
		ft_printf("ERROR: asm requier a .s file to run\n");
	else
		ft_asm(argv[i]);
}

int			main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc > 1)
	{
		while (i < argc)
		{
			run_asm(i, argv, argc);
			i++;
		}
	}
	else
		ft_printf("Usage : ./asm [champion]\n");
	return (0);
}
