/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:04:10 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/28 13:23:45 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void		key_press(t_keys *key, SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{ 
		if (e.key.keysym.sym == SDLK_UP)
			key->up = 1;
		if (e.key.keysym.sym == SDLK_DOWN)
			key->down = 1;
		if (e.key.keysym.sym == SDLK_LEFT)
			key->left = 1;
		if (e.key.keysym.sym == SDLK_RIGHT)
			key->right = 1;
		if (e.key.keysym.sym == ZOOM_IN)
			key->zoom_in = 1;
		if (e.key.keysym.sym == ZOOM_OUT)
			key->zoom_out = 1;
		if (e.key.keysym.sym == 27)
			exit(0);
	}
}

void		key_release(t_keys *key, SDL_Event e)
{
	if (e.type == SDL_KEYUP)
	{ 
		if (e.key.keysym.sym == SDLK_UP)
			key->up = 0;
		if (e.key.keysym.sym == SDLK_DOWN)
			key->down = 0;
		if (e.key.keysym.sym == SDLK_LEFT)
			key->left = 0;
		if (e.key.keysym.sym == SDLK_RIGHT)
			key->right = 0;
		if (e.key.keysym.sym == ZOOM_IN)
			key->zoom_in = 0;
		if (e.key.keysym.sym == ZOOM_OUT)
			key->zoom_out = 0;
	}
}

void		ft_keys_event(t_map *map, SDL_Event e, t_keys *key)
{
	key_press(key, e);
	key_release(key, e);
	ft_move(key, map);
	ft_zoom(key, map);
}
