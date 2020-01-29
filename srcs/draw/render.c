/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/23 12:49:15 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/23 12:52:34 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void			ft_clear_and_render(t_fdf *img)
{
	ft_render_text(img);
	SDL_RenderPresent(img->renderer);
	bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));
	SDL_SetRenderDrawColor(img->renderer, 0, 0, 0, 0);
	SDL_RenderClear(img->renderer);
}
