/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opicher <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:25:39 by opicher           #+#    #+#             */
/*   Updated: 2017/04/01 22:58:29 by opicher          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H
# include "libft.h"
# include "libftprintf.h"
# include "op.h"
# include <fcntl.h>

# define NB_OP 16
# define MAX_SIZE_LABEL 30

/*
*** Structure pour ft_checkchamp
*** numero de ligne, parametre
*/

typedef struct	s_pa
{
	int			numline;
	char		*parm;
	struct s_pa	*next;
}				t_pa;

typedef struct	s_op
{
	char	*name;
	int		index;
	int		param[3];
	char	opcode;
	int		cycle;
	char	*use;
	int		octet;
	int		carry;
}				t_op;

static t_op		g_tab[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG}, 6, 6,
		"et (and  r1, r2, r3   r1&r2 -> r3", 1, 0},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 7, 6,
		"ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG}, 8, 6,
		"ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 10, 25,
		"load index", 1, 1},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG}, 11, 25,
		"store index", 1, 1},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG}, 14, 50,
		"long load index", 1, 1},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0},
	{0, 0, {0}, 0, 0, 0, 0, 0}
};

typedef struct	s_param
{
	int				lab;
	char			*val;
	char			*label;
	int				s;
	struct s_param	*next;
}				t_param;

/*
*** structure de recuperation des champions passer en argument (liste chainee de
*** chaine de charactere recuperer par get_next_line
*** sera utile pour la traduction temporaire necessaire pour le calcul des
*** distance relative au label
*/

typedef struct	s_champ
{
	char			*l;
	int				nb_line;
	char			*label;
	char			opcode;
	long			size;
	char			oct_crypt;
	t_param			*param;
	struct s_champ	*next;
	struct s_champ	*back;
}				t_champ;

/*
*** Structure environnement contient la size duprogram au format int
*** un tableau de taille 5 de chaine de charactere
*** bin[0] = code magic
*** bin[1] = prog name
*** bin[2] = prog size format char
*** bin[3] = commentaire programme
*** bin[4] = code du program en binaire
*/

typedef struct	s_env
{
	long	size;
	char	**bin;
}				t_env;

t_champ			*ft_readchamp(char *s);
t_env			*ft_trad(t_champ *champ);
void			ft_writechamp(int fd, t_env *env);
void			ft_writenbr(int n, char **s, int i);
int				ft_writename(char *bin, t_champ *c);
int				ft_writecom(char *bin, t_champ *c);
long			ft_algotrad(char *bin, t_champ *c);
int				ft_isparam(char *l);
int				check_champ(t_champ *champ);
int				ft_labelsize(int opcode);
char			*ft_islabel(char *s);
void			ft_chrlabel(t_champ *c);
int				ft_paramreg(char *l, t_param *param);
int				ft_paramind(char *l, t_param *param);
void			ft_paramdir(char *l, int s, t_param *par);
char			**new_bin(void);
char			*writedefbin(char *bin, t_champ *c, int s);

char			**ft_strsplit_whitespaces(char const *s);
char			**strsplit_separator(char const *s, char c);

int				check_champion_body(t_champ *champ);
int				type_first_word(char *word, int numline);
int				check_opline(char **line, int numline);
int				check_champion_header(t_champ *champ, t_champ **body);
int				ft_is_direct_param(char *par);
int				ft_is_label_param(char *par);
int				valid_numeric_param(char *par);
int				ft_is_register(char *reg);
int				check_misplaced_separator(char *l, int nb_line);
int				ft_isalnum_small_str(char *str);
int				ft_isalnum_small(char c);
int				ft_isnum_str(char *str);
int				ft_isalpha_small_str(char *str);
long long int	ft_atoi_ll(const char *str);
char			**ft_strsplit_whitespaces(char const *s);
char			**ft_strsplit_spacescom(char *s);
char			**strsplit_separator(char const *s, char c);
void			null_first_char(char **str, char c);
int				ft_isnum_str(char *str);
int				print_err(char *str, char *param, int numline);
int				search_missing_data(char *l, int nb_line);
int				chartab_nb_index(char **tab);
void			free_tab2(char **tab, int size);
int				is_label(char *word);
int				is_op(char *word);
int				check_label(char *label, int numline);
int				type_first_word(char *word, int numline);
int				is_label_str(char *str);
int				is_label_char(char c);
int				check_label_characters(t_champ *body);
int				label_exists(char *str, t_champ *body);
int				existing_label(t_champ *body, t_pa *list);
void			save_label(char *str, t_champ *body);
t_pa			*save_parameters(t_champ *body);
int				check_tag(char *tag, int numline, char *tag_type);
t_champ			*ft_skip_empty_champ(t_champ *champ);
int				error_tagchar(char tagchar, int numline);
int				format_tag(char *str, int numline, char *tag_type);
int				mark_header_tag(int nbword, char **line, int *bool,
		int numline);
int				check_header_tag_format(char *tag, int numline, char *tag_type);

void			ft_free4all(t_env *env, t_champ *c);
void			ft_freechamp(t_champ *c);
void			ft_freetabchar(char **bin);
void			ft_freeparam(t_param *par);
t_param			*ft_new_param(void);

#endif
