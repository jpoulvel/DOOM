/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:49:15 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/15 16:54:27 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void			ft_clear_and_render(t_fdf *img/*, t_wlist *wlst, t_olist *olst*/)
{
	//ft_print_obj(img, olst);
	ft_print_buttons(img);
	ft_print_grid(img, img->map);
	ft_print_walls(img, img->map->wlst);
	ft_render_text(img);
	SDL_RenderPresent(img->renderer);
	bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));
	SDL_SetRenderDrawColor(img->renderer, 0, 0, 0, 0);
	SDL_RenderClear(img->renderer);
}

void			ft_clear_and_render_menu(t_fdf *img/*, t_wlist *wlst, t_olist *olst*/)
{
//	ft_print_obj(img, olst);
	ft_print_buttons(img);
	ft_print_grid(img, img->map);
	ft_print_walls(img, img->map->wlst);
	ft_render_text(img);
	SDL_RenderPresent(img->renderer);
	bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));
	SDL_SetRenderDrawColor(img->renderer, 0, 0, 0, 0);
	SDL_RenderClear(img->renderer);
}
