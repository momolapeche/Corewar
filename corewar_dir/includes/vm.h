/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 13:27:00 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/02 20:04:44 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "libft.h"
# include "op.h"
# include "ft_printf.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

# include "SDL.h"
# include "SDL_ttf.h"
# define PATH_RUNI "fonts/RUNI.ttf"
# define PATH_BEBAS "fonts/BEBAS___.ttf"
# define Y_IDX_MOD 1
# define N_IDX_MOD 0
# define CHAR_W 10
# define CHAR_H 18
# define WHITE MAX_PLAYERS

# define W_ARENA ((64 * 2 + 63) * CHAR_W)
# define H_ARENA (CHAR_H * 64)

# define W W_ARENA
# define H H_ARENA

typedef struct	s_param
{
	int				size;
	int				value;
	unsigned		type;

}				t_param;

typedef struct	s_champ
{
	struct s_header		header;
	int					fd;
	int					id_champ;
	unsigned char		code[CHAMP_MAX_SIZE];
	unsigned			*tab_proc;
	struct s_instruc	*command;
	struct s_champ		*next;

}				t_champ;

typedef struct	s_igchamp
{
	int					id;
	int					current_cycle;
	struct s_igchamp	*next;
}				t_igchamp;

typedef struct	s_proc
{
	int				preview;
	int				live;
	int				carry;
	int				reg[REG_NUMBER];
	int				pc;
	int				nb_cycle;
	struct s_proc	*next;
	t_igchamp		*igchamp;
}				t_proc;

typedef struct	s_env
{
	int				id;
	SDL_Texture		*texture[16];
	SDL_Color		textcolor;
}				t_env;

typedef struct	s_info
{
	unsigned char	arena[MEM_SIZE];
	t_param			param[3];

	t_champ			*champs;
	t_igchamp		*igchamp;
	t_proc			*proc;
	int				nb_live;
	int				nb_cycle;
	int				n_champ;
	int				winner;
	int				nb_checks;

	int				dump;
	int				limit_dump;
	int				f_number;
	int				sdl;
	int				limit_sdl;
	int				end;
	int				rune;
	char			*win_name;

	SDL_Window		*window;
	SDL_Renderer	*renderer;
	TTF_Font		*police;
	SDL_Rect		position;
	SDL_Event		event;
	SDL_Texture		*text;
	SDL_Surface		*font;

	struct s_env	champ_env[MAX_PLAYERS + 1];
	int				buffer[MEM_SIZE];

}				t_info;

int				add_champ(t_info *info, char *champion, int id);
int				write_help(void);
t_champ			*get_add_end(t_champ *champs);
void			cor_error(char *str);
void			vm_launch(t_info *info);
t_proc			*create_proc(int pos, int count, t_igchamp *champ);
void			give_begin(t_proc *begin, t_proc *current);
void			fill_arena(unsigned char *arena, t_info *info);
t_igchamp		*create_champ_tab(t_champ *champs, t_info *info);
void			check_args(t_info *info, char **argv, int argc);
int				get_mem_value(unsigned char *arena, int pc, int size);
void			print_mem_value(t_info *info, int pos, unsigned value);
void			clear_param(t_param *param);
int				get_value(t_info *info, t_proc *proc, t_param param, int boul);
void			increase_pc(t_info *info, t_proc *proc);
int				apply_idx_mod(short value);
int				apply_idx_mod_int(int value);
void			put_new_at_end(t_proc *new, t_proc **begin);
void			virtual_machine(unsigned char *arena, t_info *info);
void			increase_pc(t_info *info, t_proc *proc);
int				kill_reinit(t_proc **beg_proc, t_info *info);

void			choose_winner(t_info *info);
void			deal_mult_param(unsigned char *arena,
		t_param *param, t_proc *proc);
void			get_param_value(t_param *param, unsigned char *arena, int pc);
int				pars_param(t_info *info, t_proc *proc);
int				check_proto(t_info *info, t_proc *proc);

void			live(t_info *info, t_proc *proc, t_param *param);
void			add(t_info *info, t_proc *proc, t_param *param);
void			ld(t_info *info, t_proc *proc, t_param *param);
void			lld(t_info *info, t_proc *proc, t_param *param);
void			ldi(t_info *info, t_proc *proc, t_param *param);
void			lldi(t_info *info, t_proc *proc, t_param *param);
void			st(t_info *info, t_proc *proc, t_param *param);
void			sub(t_info *info, t_proc *proc, t_param *param);
void			and(t_info *info, t_proc *proc, t_param *param);
void			or(t_info *info, t_proc *proc, t_param *param);
void			xor(t_info *info, t_proc *proc, t_param *param);
void			zjmp(t_info *info, t_proc *proc, t_param *param);
void			sti(t_info *info, t_proc *proc, t_param *param);
void			aff(t_info *info, t_proc *proc, t_param *param);
void			cor_fork(t_info *info, t_proc *proc, t_param *param);
void			cor_lfork(t_info *info, t_proc *proc, t_param *param);

void			print_arena(unsigned char *arena, t_info *info);
void			launch_sdl(t_info *info);
void			maj_buffer(t_info *info, t_proc *proc);
void			init_sdl(t_info *info);
void			set_winner_sdl(t_info *info);
void			add_champ_name(t_info *info);
void			deal_sdl(t_info *info);
void			check_event(t_info *info);

void			cot(t_info *info, char *str);
#endif
