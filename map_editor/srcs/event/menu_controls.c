/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:31 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/21 12:09:28 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

void			ft_print_buttons(t_fdf *img)
{
	SDL_SetRenderDrawColor(img->renderer, 255, 0, 0, 0);
	SDL_RenderDrawLine(img->renderer, 1320, 120, 1550, 120);
	SDL_RenderDrawLine(img->renderer, 1320, 170, 1550, 170);
	SDL_RenderDrawLine(img->renderer, 1320, 120, 1320, 170);
	SDL_RenderDrawLine(img->renderer, 1550, 120, 1550, 170);

	SDL_RenderDrawLine(img->renderer, 1320, 180, 1550, 180);
	SDL_RenderDrawLine(img->renderer, 1320, 230, 1550, 230);
	SDL_RenderDrawLine(img->renderer, 1320, 180, 1320, 230);
	SDL_RenderDrawLine(img->renderer, 1550, 180, 1550, 230);

	SDL_SetRenderDrawColor(img->renderer, 255, 255, 0, 0);

	SDL_RenderDrawLine(img->renderer, 1320, 240, 1550, 240);
	SDL_RenderDrawLine(img->renderer, 1320, 290, 1550, 290);
	SDL_RenderDrawLine(img->renderer, 1320, 240, 1320, 290);
	SDL_RenderDrawLine(img->renderer, 1550, 240, 1550, 290);
}

void			ft_print_pressed_button(t_fdf *img, int i)
{
	SDL_SetRenderDrawColor(img->renderer, 255, 0, 0, 0);
	if (i == 2)
	{
		SDL_SetRenderDrawColor(img->renderer, 255, 255, 0, 0);
		SDL_RenderDrawLine(img->renderer, 1320, 240, 1550, 290);
	}
	if (i == 1)
		SDL_RenderDrawLine(img->renderer, 1320, 120, 1550, 170);
	if (i == 0)
		SDL_RenderDrawLine(img->renderer, 1320, 180, 1550, 230);
}

void			set_mous_loop(t_mouse *mous, int i)
{
	mous->loop = i;
	loop_til_release();
}

void			ft_menu_event(t_map *map, t_mouse *mous, SDL_Event e)
{
	int			tmx;
	int			tmy;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&tmx, &tmy);
			if (tmx >= 1320 && tmx <= 1550 && tmy >= 120 && tmy <= 170)
				set_mous_loop(mous, 1);
			if (tmx >= 1320 && tmx <= 1550 && tmy >= 180 && tmy <= 230)
				set_mous_loop(mous, 0);
			if (tmx >= 1320 && tmx <= 1550 && tmy >= 230 && tmy <= 290)
				set_mous_loop(mous, 2);
			//every if checks if you click on every button and if you do it runs wall placing button, objects and enemy placing 
			//or undo/remove/move elements
		}
	}
}
