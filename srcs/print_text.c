/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:19 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/06 13:54:36 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_print_menu(t_fdf *img)
{
	TTF_Font	*testfont;
	SDL_Color	testcolor;
	int			txt_w;
	int			txt_h;

	//img->font = TTF_OpenFont("Fonts/snowballs/Snowballs.ttf", 25);//already done in ft_txt_init
	ft_putstr("ok1");//DEBUG
	testfont = img->font;
	ft_putstr("ok2");//DEBUG
	ft_putstr("ok3");//DEBUG
	testcolor = img->color;
	ft_putstr("ok4");//DEBUG
	TTF_SizeText(img->font, "Menu", &txt_w, &txt_h);
	if (!(img->surface = TTF_RenderText_Solid(img->font, "Menu", img->color)))
		ft_error((char *)TTF_GetError(), 2);
	ft_putstr("ok5");//DEBUG
	//img->texture = SDL_CreateTexture(ptr->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 500, 300);
	//else not needed
	img->texture = SDL_CreateTextureFromSurface(img->renderer, img->surface);
	SDL_FreeSurface(img->surface);
	ft_putstr("ok6");//DEBUG
}
