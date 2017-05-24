/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_fcts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 10:15:28 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/01 21:27:40 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

const t_op	g_op_tab_sdl[17] =
{
	{"live", 1, {T_DIR}, 1, 10, "alive", 0, 0, 4, live},
	{"ld", 2, {T_DIR | T_IND, T_REG}, 2, 5, "load", 1, 0, 4, ld},
	{"st", 2, {T_REG, T_IND | T_REG}, 3, 5, "store", 1, 0, 4, st},
	{"add", 3, {T_REG, T_REG, T_REG}, 4, 10, "addition", 1, 0, 4, add},
	{"sub", 3, {T_REG, T_REG, T_REG}, 5, 10, "soustraction", 1, 0, 4, sub},
	{"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND | T_DIR, T_REG},
		6, 6, "et (and  r1, r2, r3   r1&r2 -> r3", 1, 0, 4, and},
	{"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		7, 6, "ou  (or   r1, r2, r3   r1 | r2 -> r3", 1, 0, 4, or},
	{"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND | T_DIR, T_REG},
		8, 6, "ou (xor  r1, r2, r3   r1^r2 -> r3", 1, 0, 4, xor},
	{"zjmp", 1, {T_DIR}, 9, 20, "jump if zero", 0, 1, 2, zjmp},
	{"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		10, 25, "load index", 1, 1, 2, ldi},
	{"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR | T_REG},
		11, 25, "store index", 1, 1, 2, sti},
	{"fork", 1, {T_DIR}, 12, 800, "fork", 0, 1, 2, cor_fork},
	{"lld", 2, {T_DIR | T_IND, T_REG}, 13, 10, "long load", 1, 0, 4, lld},
	{"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, T_REG},
		14, 50, "long load index", 1, 1, 2, lldi},
	{"lfork", 1, {T_DIR}, 15, 1000, "long fork", 0, 1, 2, cor_lfork},
	{"aff", 1, {T_REG}, 16, 2, "aff", 1, 0, 4, aff},
	{0, 0, {0}, 0, 0, 0, 0, 0, 0, NULL}
};

void		add_champ_name(t_info *info)
{
	SDL_Surface		*font;
	SDL_Texture		*texture;

	font = TTF_RenderText_Solid(info->police, info->win_name,
			info->champ_env[info->winner].textcolor);
	texture = SDL_CreateTextureFromSurface(info->renderer, font);
	info->position.w = ft_strlen(info->win_name) * CHAR_W;
	info->position.h = CHAR_H;
	info->position.x = (W / 2) - info->position.w / 2;
	info->position.y = H / 2 - info->position.h / 2;
	SDL_RenderCopy(info->renderer, texture, NULL, &info->position);
	SDL_RenderPresent(info->renderer);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(font);
}

void		maj_buffer(t_info *info, t_proc *proc)
{
	t_igchamp	*tmp;
	int			i;
	int			pc;
	int			sum;

	i = 0;
	tmp = info->igchamp;
	sum = proc->pc + 1 + info->param[0].size
		+ g_op_tab_sdl[proc->preview - 1].octet;
	sum += info->param[1].size == -1 ? 0 : info->param[1].size;
	sum += info->param[2].size == -1 ? 0 : info->param[2].size;
	while (tmp && tmp->id != proc->reg[0] && (++i))
		tmp = tmp->next;
	if (i == info->n_champ)
		i = -1;
	pc = proc->pc;
	while (pc < sum)
	{
		info->buffer[pc % MEM_SIZE] = i;
		pc++;
	}
}

void		create_new_struct(t_info *info, int index)
{
	int					i;
	static const int	*buf = L"0123456789ABCDEF";
	static const int	*buf3 = L"NBCDEFGHIJKLMAOP";
	int					buf2[2];

	buf2[1] = '\0';
	info->position.x = 0;
	info->position.y = 0;
	i = -1;
	if (!buf)
		return ;
	while (++i < 16)
	{
		buf2[0] = info->rune ? buf3[i] : buf[i];
		info->font = TTF_RenderGlyph_Solid(info->police,
				(unsigned short)*buf2, info->champ_env[index].textcolor);
		info->champ_env[index].texture[i] = SDL_CreateTextureFromSurface(
				info->renderer, info->font);
		SDL_FreeSurface(info->font);
	}
	info->font = NULL;
}

void		init_sdl(t_info *info)
{
	int i;

	i = -1;
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	info->window = SDL_CreateWindow("Corewar", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_SHOWN);
	info->renderer = SDL_CreateRenderer(info->window,
			-1, SDL_RENDERER_TARGETTEXTURE);
	SDL_RenderClear(info->renderer);
	info->police = TTF_OpenFont(info->rune ? PATH_RUNI : PATH_BEBAS, 16);
	info->position.w = CHAR_W;
	info->position.h = CHAR_H;
	while (++i < info->n_champ)
	{
		info->champ_env[i].textcolor.r = !(i & 1) * 255;
		info->champ_env[i].textcolor.g = (i >> 1) * 255;
		info->champ_env[i].textcolor.b = (i == 1) * 255;
		create_new_struct(info, i);
	}
}
