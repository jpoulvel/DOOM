/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:31 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/24 16:21:28 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

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

}

void			ft_print_pressed_button(t_fdf *img, int i)
{
	SDL_SetRenderDrawColor(img->renderer, 255, 0, 0, 0);
	if (i == 0)
	{
		SDL_RenderDrawLine(img->renderer, 1320, 120, 1550, 170);
		SDL_RenderDrawLine(img->renderer, 1320, 120, 1550, 170);
	
	}
	if (i == 1)
	{
		SDL_RenderDrawLine(img->renderer, 1320, 180, 1550, 230);
		SDL_RenderDrawLine(img->renderer, 1320, 180, 1550, 230);
	}
}

void			ft_menu_event(t_map *map, t_mouse *mous, SDL_Event e)
{
	int	tmx;
	int	tmy;

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			SDL_GetMouseState(&tmx, &tmy); // needs to be uncommented once this is fixed
			if (tmx >= 1320 && tmx <= 1550 && tmy >= 120 && tmy <= 170)
			{	
				mous->loop = 1;
				loop_til_release();
			} 
			if (tmx >= 1320 && tmx <= 1550 && tmy >= 180 && tmy <= 230)
			{	
				mous->loop = 0;
				loop_til_release();
			} 
			//every if checks if you click on every button and if you do it runs wall placing button, objects and enemy placing 
			//or undo/remove/move elements
		}
	}
}
