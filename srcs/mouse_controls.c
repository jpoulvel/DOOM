/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_controls.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:10:42 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/12/13 15:10:49 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_put_point(t_fdf *img, t_map *map, t_mouse *mous)
{
	SDL_SetRenderDrawColor(img->renderer, 255, 0, 0, 255);
	//SDL_RenderDrawLine(img->renderer, img->map->ox + mous->click1[0], img->map->oy + mous->click1[1], img->map->ox + mous->click2[0], img->map->oy + mous->click2[1]);
	SDL_RenderDrawLine(img->renderer, mous->click1[0], mous->click1[1], mous->click2[0], mous->click2[1]);
}

void		ft_fill_image_line(t_fdf *img, t_map *map, t_mouse *mous)
{
	map->base_gap = ft_gap(map);
	map->base_h = ft_height(map);
	ft_origin(map);
	//ft_attibute_color(map->map);
	ft_print_lines(img, map);
	ft_put_point(img, map, mous);
}

void		ft_mouse_event(t_fdf *img, t_map *map, t_mouse *mous, SDL_Event e)
{
	if (e.type == SDL_MOUSEBUTTONDOWN)
	{
		if (e.button.button == SDL_BUTTON_LEFT)
		{
			if (mous->click == 0)
				SDL_GetMouseState(&mous->click1[0], &mous->click1[1]);
			else
			{
				SDL_GetMouseState(&mous->click2[0], &mous->click2[1]);
				ft_fill_image_line(img, map, mous);
				SDL_RenderPresent(img->renderer);
				bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));
				SDL_SetRenderDrawColor(img->renderer, 0, 0, 0, 0);
				SDL_RenderClear(img->renderer);
			}
		}
		mous->click = 0;
	}
	if (e.type == SDL_MOUSEBUTTONUP)
	{
		mous->click = 1;
	}
}
