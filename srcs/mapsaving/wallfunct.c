/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallfunct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:29:36 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/17 11:59:00 by jpoulvel         ###   ########.fr       */
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

t_point			click_to_point(t_map *map, int *x, int *y)
{
	t_point		point;

	printf("avant x = %d, \ny = %d,\n", *x, *y);
	SDL_GetMouseState(x, y);
	ft_fix_coords(map, x, y);
	point = create_point(*x, *y);
	printf("apres \nx = %f, \ny = %f,\n", point.x, point.y);
	return (point);
}

t_wall			click_to_wall_coord(t_map *map, t_mouse **mous, SDL_Event e)
{
	t_point 	start;
	t_point 	end;
	t_vertex 	normal;
	t_wall	 	wall;
	t_wlist 	*new;

	if ((ft_even_odd((*mous)->click) == 0))
	{
		ft_putendl("ft_even_odd(mouse->click = 0");
		loop_til_release();
		(*mous)->walls.start = click_to_point(map, &((*mous)->click1[0]), &((*mous)->click1[1]));
	}
	else
	{
		ft_putendl("ft_even_odd(mouse->click = 1");
		loop_til_release();
		end = click_to_point(map, &((*mous)->click2[0]), &((*mous)->click2[1]));
		normal.x = start.y - end.y;
		normal.y = -(start.x - end.x);
		wall = create_wall((*mous)->walls.start, end, normal);
	//	start = (t_point){0, 0};
	}
	return (wall);
}


void			click_to_create_new_wall(t_map *map, t_mouse *mous, SDL_Event e)
{
	t_point 	start;
	t_point 	end;
	t_vertex 	normal;
	t_wall	 	wall;
	t_wlist 	*new;

	wall = click_to_wall_coord(map, &mous, e);
	if (!(new = new_wlist(wall)))
		return /*(4)*/;
	add_wlist(&map->wlst, new);
	mous->click++;
	return/* (1)*/;
}
