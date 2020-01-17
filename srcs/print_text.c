/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:19 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/17 19:07:46 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_print_menu(t_fdf *img)
{
	int			txt_w;
	int			txt_h;

	if (!(img->texture = SDL_CreateTextureFromSurface(img->renderer, img->txt->menu->surface)))
		ft_error((char *)SDL_GetError(), 2);
	SDL_FreeSurface(img->txt->menu->surface);
	/*if (!(img->texture = SDL_CreateTextureFromSurface(img->renderer, img->txt->item->surface)))
		ft_error((char *)SDL_GetError(), 2);
	SDL_FreeSurface(img->txt->item->surface);*/
}
