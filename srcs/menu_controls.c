/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 15:53:31 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/23 18:01:09 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_print_buttons(t_fdf *img)
{
			SDL_SetRenderDrawColor(img->renderer, 255, 0, 0, 0);
			SDL_RenderDrawLine(img->renderer, 1320, 120, 1550, 120);
			SDL_RenderDrawLine(img->renderer, 1320, 170, 1550, 170);
			SDL_RenderDrawLine(img->renderer, 1320, 120, 1320, 170);
			SDL_RenderDrawLine(img->renderer, 1550, 120, 1550, 170);

}

void			ft_menu_event(t_map *map, t_mouse *mous, SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			//SDL_GetMouseState(&mous->click1[0], &mous->click1[1]); // needs to be uncommented once this is fixed
			/*
			if (mous->click1[0] >= 1320 && mous->click1[0] <= 1550 && mous->click1[1] >= 120 && mous->click1[1] <= 170)
			{
				place_wall();
				printf("cordsclicked: (%i, %i)\n", mous->click1[0], mous->click1[1]);
			} */
			//every if checks if you click on every button and if you do it runs wall placing button, objects and enemy placing 
			//or undo/remove/move elements
		}
	}
}
