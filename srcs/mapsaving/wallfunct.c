/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallfunct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:29:36 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/04 19:16:13 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

t_vertex		create_vertex(double x, double y)
{
	t_vertex	new;

	new.x = x;
	new.y = y;
	return (new);
}

t_wall			create_wall(t_vertex start, t_vertex end, t_vertex normal)
{
	t_wall		new;

	new.start = create_vertex(start.x, start.y);
	new.end = create_vertex(end.x, end.y);
	new.normal = create_vertex(normal.x, normal.y);
	return (new);
}

t_wall			create_emptywall(void)
{
	t_wall		new;
	
	new.start = create_vertex(0,0);
	new.end = create_vertex(0,0);
	new.normal = create_vertex(0,0);
	return (new);
}

void	set_walls(t_map *map, t_mouse *mous, SDL_Event e, t_wlist **wlst)
{
	t_vertex 		tma;
	t_vertex 		tmb;
	t_vertex 		tmn;
	t_wall	 		wall;
	t_wlist 		*tmwlst;

	if ((ft_even_odd(mous->click) == 0))
	{
		loop_til_release();
		SDL_GetMouseState(&mous->click1[0], &mous->click1[1]);
		ft_fix_coords(map, &mous->click1[0], &mous->click1[1]);
	}
	else
	{
		loop_til_release();
		SDL_GetMouseState(&mous->click2[0], &mous->click2[1]);
		map->endx = map->ox + ((map->x - 1) * map->base_gap);
		map->endy = map->oy + ((map->y - 1) * map->base_gap);
		ft_fix_coords(map, &mous->click2[0], &mous->click2[1]);
		tma = create_vertex(mous->click1[0], mous->click1[1]);
		tmb = create_vertex(mous->click2[0], mous->click2[1]); 
		tmn.x = tma.y - tmb.y;
		tmn.y = -(tma.x - tmb.x);
		mous->nwalls++;
		if (*wlst == NULL)
		{
			wall = create_wall(tma, tmb, tmn);
			*wlst = new_wlist(wall, mous->nwalls);
		}
		else
		{
			wall = create_wall(tma, tmb, tmn);
			tmwlst = new_wlist(wall, mous->nwalls);
			add_wlist(wlst, tmwlst);
		}
	}
	mous->click++;
}
