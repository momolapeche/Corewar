/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   SDL_fcts_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguttin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/29 18:09:43 by tguttin           #+#    #+#             */
/*   Updated: 2017/04/01 21:27:57 by tguttin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

void	end_sdl(t_info *info)
{
	SDL_DestroyWindow(info->window);
	SDL_DestroyRenderer(info->renderer);
	TTF_Quit();
	SDL_Quit();
	exit(0);
}

void	check_event(t_info *info)
{
	while (SDL_PollEvent(&info->event))
	{
		if (info->event.type == SDL_QUIT)
			end_sdl(info);
		if (info->event.type == SDL_KEYDOWN)
		{
			if (info->event.key.keysym.sym == 32)
				while (SDL_WaitEvent(&info->event))
				{
					if (info->event.type == SDL_QUIT || (info->event.type ==
						SDL_KEYDOWN && info->event.key.keysym.sym == 27))
						end_sdl(info);
					if ((info->event.type == SDL_KEYDOWN &&
						info->event.key.keysym.sym == 32))
						break ;
				}
			else if (info->event.key.keysym.sym == 1073741911)
				info->limit_sdl++;
			else if (info->event.key.keysym.sym == 1073741910)
				info->limit_sdl -= (info->limit_sdl > 1);
			else if (info->event.type == SDL_QUIT || (info->event.type ==
				SDL_KEYDOWN && info->event.key.keysym.sym == 27))
				end_sdl(info);
		}
	}
}

void	launch_sdl(t_info *info)
{
	int	i;

	i = -1;
	info->position.x = 0;
	info->position.y = 0;
	SDL_RenderClear(info->renderer);
	while (++i < MEM_SIZE)
	{
		if (info->buffer[i] >= 0 && info->buffer[i] < info->n_champ)
			SDL_RenderCopy(info->renderer, info->champ_env[info->buffer[i]].
					texture[(info->arena[i] >> 4) & 0xf],
					NULL, &info->position);
		info->position.x += CHAR_W;
		if (info->buffer[i] >= 0 && info->buffer[i] < info->n_champ)
			SDL_RenderCopy(info->renderer, info->champ_env[info->buffer[i]].
					texture[(info->arena[i] >> 0) & 0xf],
					NULL, &info->position);
		info->position.x += CHAR_W * 2;
		if (info->position.x > W_ARENA)
		{
			info->position.x = 0;
			info->position.y += CHAR_H;
		}
	}
}

void	deal_sdl(t_info *info)
{
	int y;
	int x;

	y = -1;
	set_winner_sdl(info);
	while (SDL_WaitEvent(&info->event))
		if (info->event.type == SDL_QUIT || (info->event.type == SDL_KEYDOWN &&
			info->event.key.keysym.sym == 27))
			break ;
	while (++y < info->n_champ && (x = -1))
		while (++x < 16)
			if (info->champ_env[y].texture[x])
				SDL_DestroyTexture(info->champ_env[y].texture[x]);
	end_sdl(info);
}

void	set_winner_sdl(t_info *info)
{
	SDL_RenderPresent(info->renderer);
	info->police = TTF_OpenFont(PATH_BEBAS, 16);
	info->position.w = CHAR_W * (ft_strlen(info->win_name) + 4);
	info->position.h = 4 * CHAR_H;
	info->position.x = (W / 2) - info->position.w / 2;
	info->position.y = H / 2 - info->position.h / 2;
	info->text = SDL_CreateTexture(info->renderer, SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_TARGET, info->position.y, info->position.x);
	SDL_SetRenderTarget(info->renderer, info->text);
	SDL_SetRenderDrawColor(info->renderer, 0, 0, 0, 255);
	SDL_RenderClear(info->renderer);
	SDL_SetRenderTarget(info->renderer, NULL);
	SDL_RenderCopy(info->renderer, info->text, NULL, &info->position);
	add_champ_name(info);
}
