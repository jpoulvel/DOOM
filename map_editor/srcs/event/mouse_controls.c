/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:38:23 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/18 13:30:20 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

void			ft_put_point(t_fdf *img, t_map *map, t_mouse *mous)
{
	SDL_SetRenderDrawColor(img->renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(img->renderer, mous->click1[0], mous->click1[1], mous->click2[0], mous->click2[1]);
}

int				ft_even_odd(int i)
{
	if (i % 2 == 0)
		return (0);
	return (1);
}

void			loop_til_release()
{
	int			isquit;
	SDL_Event	e;

	isquit = 0;
	while (isquit == 0)
	{
		if (SDL_PollEvent(&e)) 
		{
			if (e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE)
				exit (0);
			if (e.type == SDL_MOUSEBUTTONUP)
				break;
		}
	}
	
}

/*
** We'll need to change this function to return int and print error messages if an action does not work"
*/
void			ft_mouse_event(t_fdf *img, t_mouse *mous, SDL_Event e, t_olist **olst)
{
	int			error;
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			if (mous->loop == 1)
				/*error = */click_to_create_new_wall(img->map, mous, e);
			if (mous->loop == 0)
				/*error =*/ click_to_remove_wall(img->map, mous, e);
	//		if (mous->loop == 0)
	//			/*error = */set_object(img->map, mous, e, olst);
		}
	}
//	return (ft_error(error));
}
