/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keys_event.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 12:04:10 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/20 16:45:24 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_keys_event(t_map *map, t_mouse *mous, SDL_Event e)
{
	if (e.type == SDL_KEYDOWN)
	{ 
		if (e.key.keysym.sym == SDLK_UP)
		{
			map->oy -= 10;
			printf("oy:%i\n", map->oy);
		}
		if (e.key.keysym.sym == SDLK_DOWN)
			map->oy += 10;
		if (e.key.keysym.sym == SDLK_LEFT)
			map->ox -= 10;
		if (e.key.keysym.sym == SDLK_RIGHT)
			map->ox += 10;
		if (e.key.keysym.sym == 27)
			exit(0);
	}
}
