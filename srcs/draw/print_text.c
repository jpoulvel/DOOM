/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:19 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/24 19:13:29 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void			ft_render_text(t_fdf *img)
{
	SDL_RenderCopy(img->renderer, img->txt->menu->texture, NULL,
			&img->txt->menu->rect);
/*	SDL_RenderCopy(img->renderer, img->txt->item->texture, NULL,
			&img->txt->item->rect);*/
}

t_item			*ft_sub_init(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
{
	t_item	*sub;

	if (!(sub = malloc(sizeof(t_item))))
		return (0);
	TTF_SizeText(font, "Sous-menu", &sub->rect.w, &sub->rect.h);
	sub->rect.x = 10;
	sub->rect.y = 10;
	if (!(sub->surface = TTF_RenderText_Solid(font, "Sous-menu", color)))
		ft_error((char *)TTF_GetError(), 2);
	if (!(sub->texture = SDL_CreateTextureFromSurface(renderer,
					sub->surface)))
		ft_error((char *)SDL_GetError(), 2);
	SDL_FreeSurface(sub->surface);
	return (sub);
}

t_item			*ft_menu_init(TTF_Font *font, SDL_Color color, SDL_Renderer *renderer)
{
	t_item		*menu;

	if (!(menu = malloc(sizeof(t_item))))
		return (NULL);
	TTF_SizeText(font, "Menu", &menu->rect.w, &menu->rect.h);
	menu->rect.x = 10;
	menu->rect.y = 10;
	if (!(menu->surface = TTF_RenderText_Solid(font, "Menu", color)))
		ft_error((char *)TTF_GetError(), 2);
	if (!(menu->texture = SDL_CreateTextureFromSurface(renderer,
					menu->surface)))
		ft_error((char *)SDL_GetError(), 2);
	SDL_FreeSurface(menu->surface);
	return (menu);
}

t_txt			*ft_txt_init(t_fdf *img)
{
	t_txt		*txt_ptr;

	if (!(txt_ptr = malloc(sizeof(t_txt))))
		return (NULL);
	if (!(txt_ptr->font = TTF_OpenFont("Fonts/BaroneysTextured.ttf", 32)))
		ft_error((char *)TTF_GetError(), 2);
	txt_ptr->color = ft_hexa_to_ratio(SAND);
	if (!(txt_ptr->menu = ft_menu_init(txt_ptr->font, txt_ptr->color, img->renderer)))
		return (NULL);
/*	if (!(txt_ptr->item = ft_sub_init(txt_ptr->font, txt_ptr->color, img->renderer)))
		return (NULL);*/
	return (txt_ptr);
//	if (!(ft_through_init(txt->font, txt->through))
	//	return (NULL);
}
