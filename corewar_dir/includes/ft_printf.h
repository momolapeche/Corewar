/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 18:02:47 by tguttin           #+#    #+#             */
/*   Updated: 2016/12/14 19:00:30 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>
# include <limits.h>

# define RED ft_putstr("\033[31m")
# define BLANK ft_putstr("\033[0m")
# define YELLOW ft_putstr("\033[33m")
# define GREEN ft_putstr("\033[32m")
# define BLUE ft_putstr("\033[34m")
# define PURPLE ft_putstr("\033[35m")

# define I g_index
# define RET var->ret
# define LIST var->list
# define PIECE var->p_format
# define UMAX var->ap9
# define ULL var->ap2
# define UL var->ap6
# define UI var->ap4
# define UC var->ap5
# define SIZE_T var->zed
# define IMAX var->ap8
# define TMP var->tmp
# define INT var->ap
# define LONG var->ap3
# define WTMP var->tmp2

int		g_first;
int		g_index;

typedef struct	s_bouate
{
	char		*piece;
	char		*final;
	int			buffer;
	int			buf_prec;
	int			size;

	int			b_sharp;
	int			b_minus;
	int			b_null;
	int			b_plus;
	int			b_space;
	int			b_prec;
	int			x_space;

	int			b_red;
	int			b_yellow;
	int			b_blue;
	int			b_purple;
	int			b_green;

	int			ret_size;
}				t_boite;

typedef struct	s_var
{
	int					ret;
	long long			ap7;
	intmax_t			ap8;
	uintmax_t			ap9;
	int					ap;
	unsigned long long	ap2;
	unsigned long		ap6;
	unsigned int		ap4;
	unsigned char		ap5;
	size_t				zed;
	char				*p_format;
	char				*tmp;
	wchar_t				*tmp2;
	long				ap3;
	va_list				list;
}				t_var;

enum	e_values
{
	e_s = 1,
	e_S = 2,

	e_p = 3,

	e_d = 4,
	e_D = 5,
	e_i = 6,

	e_o = 7,
	e_O = 8,

	e_u = 9,
	e_U = 10,

	e_x = 11,
	e_X = 12,

	e_c = 13,
	e_C = 14,

	e_b = 49,

	e_modulo = 15,

	e_hhi = 16,
	e_hho = 17,
	e_hhu = 18,
	e_hhx = 19,
	e_hhX = 20,

	e_hi = 21,
	e_ho = 22,
	e_hu = 23,
	e_hx = 24,
	e_hX = 25,
	e_hU = 48,

	e_li = 26,
	e_lo = 27,
	e_lu = 28,
	e_lx = 29,
	e_lX = 30,

	e_lli = 31,
	e_llo = 32,
	e_llu = 33,
	e_llx = 34,
	e_llX = 35,

	e_ji = 36,
	e_jo = 37,
	e_ju = 38,
	e_jx = 39,
	e_jX = 40,

	e_zi = 41,
	e_zo = 42,
	e_zu = 43,
	e_zx = 44,
	e_zX = 45,

	e_hex = 46,
	e_oct = 47,
};

void			process(t_boite *box, t_var *var);
void			process2(t_boite *box, t_var *var);
void			process3(t_boite *box, t_var *var);
void			process4(t_boite *box, t_var *var);
void			process5(t_boite *box, t_var *var);
void			process6(t_boite *box, t_var *var);
void			process7(t_boite *box, t_var *var);
void			process8(t_boite *box, t_var *var);
void			process9(t_boite *box, t_var *var);
void			process10(t_boite *box, t_var *var);

int				ft_printf2(char *format, t_var **var, t_boite **box, int i);
int				ft_printf3(t_var **var, t_boite **box);
char			*check_format(char *format, char **piece);
char			*check_format2(char *str, char **tmp, int size, char **piece);
int				ft_printf(const char *format, ...);
int				ft_error(void);
int				check_char(char *s);
int				next_len_char(char *str);
void			initialize(t_boite *box);
char			*concat(char *str1, char *str2, int size, t_boite *box);
void			fill_buf(char *str, t_boite *box);
void			fill_buf2(char *str, t_boite *box);

int				analyze(char *str, t_boite *box);
int				analyze2(char *str, t_boite *box);
int				analyze3(char *str, t_boite *box);
int				analyze4(char *str, t_boite *box);
int				analyze5(char *str, t_boite *box);
int				analyze6(char *str, int i);

int				analyze7(char *str, int i);
int				analyze8(char *str, int i);
int				analyze9(char *str, int i);
int				analyze10(char *str, int i);
int				analyze11(char *str, int i);
int				analyze12(char *str, int i);

int				launch_flags_int(intmax_t nb, t_boite *box);
int				launch_flags_str(t_boite *box, int size);

void			prec_int(t_boite *box);
void			prec_str(t_boite *box);

void			deal_minus(t_boite *box);
void			deal_space(t_boite *box);
void			deal_null(t_boite *box);
void			deal_plus(t_boite *box);
void			deal_sharp(t_boite *box, int todo, int min_maj);

/*
** Fonction de traitement des differentes valeurs de retour de va_arg
*/

void			treat_str(char *str, t_boite *box);
void			treat_int(intmax_t ap, t_boite *box);

void			treat_int_hex(uintmax_t ap, t_boite *box, int maj);
void			treat_int_hex2(uintmax_t ap, t_boite *box, char **tmp, int maj);

void			treat_int_oct(uintmax_t ap, t_boite *box);
void			treat_int_oct2(uintmax_t ap,
		t_boite *box, char **tmp, int size);

void			treat_char(unsigned char ap, t_boite *box);
void			treat_void(unsigned long long ap, t_boite *box);
void			treat_modulo(t_boite *box);
void			treat_unsigned_print(unsigned nb, t_boite *box);
void			concat_wchar_t(unsigned nb, t_boite *box);
void			concat_wchar_t2(unsigned nb, t_boite *box, int size);
void			concat_wchar_t3(unsigned nb, t_boite *box, int size);
void			treat_unsigned_str(wchar_t *str, t_boite *box);
void			treat_unsigned_int(uintmax_t nb, t_boite *box);
void			launch_sharp(t_boite *box, int maj);
void			treat_intmax_t(intmax_t ap, t_boite *box);
void			treat_int_neg(intmax_t nb, t_boite *box, int size, char **tmp);
int				launch_flags_hex(intmax_t nb, t_boite *box, int maj);

int				launch_flags_hex2(intmax_t nb, t_boite *box,
		int maj, short boul);
/*
** tools functions.
*/

int				tab(char c);
int				delimitchar(char c);
void			add_minus(t_boite *box);
void			to_low(char *tmp);
void			to_up(char *tmp);
int				amount_bytes(unsigned nb);
int				amount_bytes_str(wchar_t *str);
void			ifneg(t_boite *box, intmax_t *nb);
int				is_activate(t_boite *box);
void			ft_printmem(char *str, int amount);
void			ft_memncat(char *dest, char *src, int d_size, int s_size);
void			ft_printmem_fd(char *str, int amount, int fd);
void			free_struc(t_boite **box, t_var **var);

/*
** bonus function
*/

void			treat_binary(uintmax_t nb, t_boite *box);
int				ft_asprintf(char **ret, const char *format, ...);
int				ft_asprintf2(char *format, t_var **var,
		t_boite **box, char **ret);
int				ft_asprintf3(t_var **var, t_boite **box, char **ret);

int				ft_dprintf(int fd, const char *format, ...);
int				ft_dprintf2(char *format, t_var **var, t_boite **box, int fd);
int				ft_dprintf3(t_var **var, t_boite **box, int fd);
#endif
