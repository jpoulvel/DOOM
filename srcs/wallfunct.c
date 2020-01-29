/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallfunct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 17:29:36 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/24 19:32:01 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fdf.h"

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
