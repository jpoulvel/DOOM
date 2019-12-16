/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:19 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/12/16 12:25:34 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_print_menu(t_fdf *img)
{
	img->font = TTF_OpenFont("calibri.ttf", 25);
	img->surface = TTF_RenderText_Solid(img->font, "MENU", img->color);
	//img->texture = SDL_CreateTexture(ptr->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 500, 300);
	img->texture = SDL_CreateTextureFromSurface(img->renderer, img->surface);
}
