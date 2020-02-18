/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_text.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/13 15:58:19 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/18 12:49:49 by jpoulvel         ###   ########.fr       */
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
