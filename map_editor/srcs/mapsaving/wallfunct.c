/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallfunct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:29:36 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/21 11:25:43 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

void			click_to_wall_coord(t_wall *wall, t_map *map, t_mouse *mous, SDL_Event e)	
{
	if ((ft_even_odd(mous->click) == 0))
	{
		loop_til_release();
		ft_putendl("ft_even_odd(mouse->click = 0");
		*wall = create_emptywall();
		wall->start = click_to_point(map, &(mous->click1[0]), &(mous->click1[1]));
	}
	else
	{
		loop_til_release();
		ft_putendl("ft_even_odd(mouse->click = 1");
		wall->end = click_to_point(map, &(mous->click2[0]), &(mous->click2[1]));
		wall->normal.x = wall->start.y - wall->end.y;
		wall->normal.y = -(wall->start.x - wall->end.x);
		wall->height = 1;
	}
	return ;
}


void				click_to_create_new_wall(t_map *map, t_mouse *mous, SDL_Event e)
{
	static t_wall	wall;
	t_wlist			*new;

	click_to_wall_coord(&wall, map, mous, e);
	if (ft_even_odd(mous->click) == 1)
	{
		if (!(new = new_wlist(wall)))
		return /*(4)*/;
		add_wlist(&map->wlst, new);
	}
	mous->click++;
	return/* (1)*/;
}
