/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map_elements.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 10:30:04 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/18 11:36:40 by jpoulvel         ###   ########.fr       */
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

	new.type = 'w';
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
