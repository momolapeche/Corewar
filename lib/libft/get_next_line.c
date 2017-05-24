/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 14:05:56 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 22:55:06 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*aboveendl(char *s)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	new = ft_strnew(BUFF_SIZE);
	if (ft_strchr(s, '\n') != NULL)
	{
		while (s[j] != '\n')
			j++;
		j++;
	}
	while (s[j] != 0)
	{
		new[i] = s[j];
		i++;
		j++;
	}
	free(s);
	return (new);
}

static char		*joinndel(char *s, char *c)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	j = 0;
	new = ft_strnew(ft_strlen(s) + ft_strlen(c));
	while (s[i] != 0)
	{
		new[i] = s[i];
		i++;
	}
	while (c[j] != 0 && c[j] != '\n')
	{
		new[i] = c[j];
		i++;
		j++;
	}
	free(s);
	return (new);
}

static t_list	*gnl_chckfd(int const fd, t_list **chain)
{
	t_list	*new;

	new = NULL;
	if (*chain == NULL)
	{
		(*chain) = ft_lstnew(NULL, 0);
		(*chain)->content_size = fd;
		return (*chain);
	}
	else if ((int)((*chain)->content_size) != fd)
	{
		if ((*chain)->next == NULL)
		{
			(*chain)->next = gnl_chckfd(fd, &new);
		}
		return (gnl_chckfd(fd, &(*chain)->next));
	}
	return (*chain);
}

static int		gnl_algo(char **s1, char **s2, void **tmp)
{
	*s1 = joinndel(*s1, *s2);
	if (ft_strchr(*s2, '\n') != NULL)
	{
		*tmp = aboveendl(*s2);
		return (1);
	}
	free(*s2);
	*s2 = NULL;
	return (0);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	char			*buff;
	t_list			*tmp;
	static t_list	*stat = NULL;

	ret = BUFF_SIZE;
	tmp = (gnl_chckfd(fd, &stat));
	if (fd < 0 || BUFF_SIZE < 1)
		return (-1);
	*line = ft_strnew(BUFF_SIZE);
	if (tmp->content != NULL)
		if (gnl_algo(line, (char**)(&(tmp->content)), &(tmp->content)) == 1)
			return (1);
	while (ret == BUFF_SIZE)
	{
		buff = ft_strnew(BUFF_SIZE);
		ret = read(fd, buff, BUFF_SIZE);
		if (buff[0] != 0 && ret > 0)
			if (gnl_algo(line, &buff, &(tmp->content)) == 1)
				return (1);
		free(buff);
		if (ret < 0)
			return (-1);
	}
	return (*line[0] == 0 && ret == 0 ? 0 : 1);
}
