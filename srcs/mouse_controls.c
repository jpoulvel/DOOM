/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 14:38:23 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/28 14:26:34 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_put_point(t_fdf *img, t_map *map, t_mouse *mous)
{
	SDL_SetRenderDrawColor(img->renderer, 0, 255, 0, 255);
	SDL_RenderDrawLine(img->renderer, mous->click1[0], mous->click1[1], mous->click2[0], mous->click2[1]);
}

void			ft_fill_image_line(t_fdf *img, t_map *map, t_mouse *mous)
{
	map->base_gap = ft_gap(map);
	map->base_h = ft_height(map);
	//ft_origin(map);
	//ft_attibute_color(map->map);
	ft_put_point(img, map, mous);
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

void			ft_mouse_event(t_map *map, t_mouse *mous, SDL_Event e, t_wlist **wlst, t_olist **olst) {

	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			if (mous->loop == 1)
				set_walls(map, mous, e, wlst);
			if (mous->loop == 0)
			{
				printf("test\n");
				set_object(map, mous, e, olst);
			}
		}
	}
}
