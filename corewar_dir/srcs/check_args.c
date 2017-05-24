/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/21 19:44:36 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/02 16:44:09 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		check_number(char *arg)
{
	int i;

	i = -1 + (arg[0] == '-');
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			return (0);
	if (arg[0] == '-' && i == 1)
		return (0);
	return (1);
}

void	if_dump(t_info *info, char *arg)
{
	int i;

	i = -1;
	if (info->dump == 1 || info->end == 1)
		cor_error("invalid options in arguments line");
	while (arg[++i])
		if (!ft_isdigit(arg[i]))
			cor_error("bad argument(s)");
	if (arg[0] == '0')
		cor_error("bad argument(s)");
	info->limit_dump = ft_atoi(arg);
	info->dump = 1;
}

void	if_number(t_info *info, char **argv, int y)
{
	if (ft_strlen(argv[y - 1]) > 10)
		cor_error("ID OF ARGUMENT TOO HIGH");
	if ((ft_strstr(argv[y], ".cor")))
	{
		if (!add_champ(info, argv[y], ft_atoi(argv[y - 1])))
			cor_error("bad argument(s)");
	}
	else
		cor_error("bad argument(s)");
}

int		check_case(t_info *info, char **argv, int argc, int y)
{
	static int	id = 0;

	if (!ft_strcmp(argv[y], "-end") && info->sdl == 0 && (info->end = 1))
		info->dump = 0;
	else if (info->f_number == 1 && check_number(argv[y])
			&& y + 1 <= argc && (y += 1))
		if_number(info, argv, y);
	else if ((ft_strstr(argv[y], ".cor")))
	{
		if (!add_champ(info, argv[y], --id))
			cor_error("bad argument(s)");
	}
	else
		cor_error("bad argument(s)");
	return (y);
}

void	check_args(t_info *info, char **argv, int argc)
{
	int y;

	y = 0;
	while (++y <= argc)
	{
		if (!ft_strcmp(argv[y], "-dump") && y + 1 <= argc && (y += 1))
			if_dump(info, argv[y]);
		else if (!ft_strcmp(argv[y], "-n"))
			info->f_number = 1;
		else if (!ft_strcmp(argv[y], "-sdl"))
		{
			info->sdl = 1;
			info->dump = 0;
			if (y + 1 <= argc && !ft_strcmp(argv[y + 1], "-rune"))
			{
				y++;
				info->rune = 1;
			}
		}
		else
			y = check_case(info, argv, argc, y);
	}
}
