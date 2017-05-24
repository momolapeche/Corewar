/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/08 15:20:00 by opicher           #+#    #+#             */
/*   Updated: 2016/05/16 21:33:50 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# define FLAG_S cur->flag_size
# define FLAG_T cur->type.flag
# include "libft.h"
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>

typedef union	u_unknow
{
	int					i;
	unsigned int		ui;
	short				sd;
	unsigned short		usd;
	long long			l;
	unsigned long long	ul;
	char				c;
	unsigned char		uc;
	char				*s;
	wchar_t				wc;
	wchar_t				*ws;
	void				**v;
}				t_unknow;

typedef struct	s_converttab
{
	char	flag;
	char	*(*f)();
	int		base;
}				t_converttab;

typedef struct	s_cur_flag
{
	char			i1;
	char			i2;
	char			i3;
	char			i4;
	int				larg_v;
	char			larg_t;
	int				prec;
	int				prec_p;
	char			*modif;
	t_converttab	type;
	int				flag_size;
	char			unk;
	int				val;
}				t_cur_flag;

int				ft_printf(const char *format, ...);
t_cur_flag		*ptf_analyse_flag(const char *c, va_list ap);
char			*ptf_setprec(char *s, t_cur_flag *cur);
char			*ptf_setprecs(char *s, t_cur_flag *cur);
char			*ptf_setprecw(char *s, t_cur_flag *cur, t_unknow u);
char			*ptf_setlarg(char *s, t_cur_flag *cur);
char			*ptf_int(t_unknow u, t_cur_flag *cur);
char			*ptf_long(t_unknow u, t_cur_flag *cur);
char			*ptf_octal(t_unknow u, t_cur_flag *cur);
char			*ptf_hexadec(t_unknow u, t_cur_flag *cur);
char			*ptf_unsigned(t_unknow u, t_cur_flag *cur);
char			*ptf_point(t_unknow u, t_cur_flag *cur);
char			*ptf_char(t_unknow u, t_cur_flag *cur);
char			*ptf_string(t_unknow u, t_cur_flag *cur);
char			*ptf_wildstr(t_unknow u, t_cur_flag *cur);
char			*ptf_purcent(t_cur_flag *cur);
void			pt_err();
int				ptf_checkvalid(t_list *def);
void			ptf_freecur(t_cur_flag *f);
void			ptf_indic_cplt(char c, t_cur_flag *cur);
int				ptf_isindic(char a);
int				ptf_ismodif(char c);
int				ptf_isflag(char c);
char			*ft_ptf_utf8(unsigned int c);
t_cur_flag		*ptf_curflag_init(void);
int				ft_checkex(int c);
char			*ptf_colorb(t_cur_flag *cur);
char			*ptf_colorr(t_cur_flag *cur);
char			*ptf_colorg(t_cur_flag *cur);
char			*ptf_colory(t_cur_flag *cur);
char			*ptf_colorn(t_cur_flag *cur);
char			*ptf_returnline(t_cur_flag *cur);

#endif
