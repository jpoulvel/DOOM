/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallfunct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:29:36 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/13 17:57:54 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

t_point			create_point(float x, float y)
{
	t_point		new;

	new.x = x;
	new.y = y;
	new.z = 1;//while we can give wanted altitudes
	new.color = RED;//while we change it
	new.col = ft_hexa_to_ratio(new.color);
	return (new);
}

t_vertex		create_vertex(double x, double y)
{
	t_vertex		new;

	new.x = x;
	new.y = y;
	return (new);
}

t_wall			create_wall(t_point start, t_point end, t_vertex normal)
{
	t_wall		new;

	new.type = 'w';
	new.start = start;
	new.end = end;
	new.normal = normal;
	new.height = 1;//will change later when we add the possibility to change it
	return (new);
}

t_wall			create_emptywall(void)
{
	t_wall		new;

	new.start = create_point(0,0);
	new.end = create_point(0,0);
	new.normal = create_vertex(0,0);
	new.height = 0;//will change later when we add the possibility to change it
	return (new);
}

void	click_to_wall(t_map *map, t_mouse *mous, SDL_Event e)
{
	t_point 		tma;
	t_point 		tmb;
	t_vertex 		tmn;
	t_wall	 		wall;
	t_wlist 		*new;

	if ((ft_even_odd(mous->click) == 0))
	{
		ft_putendl("ft_even_odd(mouse->click = 0");
		loop_til_release();
		SDL_GetMouseState(&mous->click1[0], &mous->click1[1]);
		ft_fix_coords(map, &mous->click1[0], &mous->click1[1]);
	}
	else
	{
		ft_putendl("ft_even_odd(mouse->click = 1");
		loop_til_release();
		SDL_GetMouseState(&mous->click2[0], &mous->click2[1]);
		ft_fix_coords(map, &mous->click2[0], &mous->click2[1]);
		tma = create_point(mous->click1[0], mous->click1[1]);
		tmb = create_point(mous->click2[0], mous->click2[1]); 
		tmn.x = tma.y - tmb.y;
		tmn.y = -(tma.x - tmb.x);
		wall = create_wall(tma, tmb, tmn);
		if (map->wlst == NULL)
			map->wlst = new_wlist(wall);
		else
		{
		new = new_wlist(wall);
		add_wlist(&map->wlst, new);
		}
	}
	mous->click++;
}
