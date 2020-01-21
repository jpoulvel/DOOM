/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_wlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:51:48 by jmoucach          #+#    #+#             */
/*   Updated: 2020/01/21 17:24:05 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_wlist *new_wlist(t_wall wall, int id)
{
	t_wlist *new;

	if (!(new = (t_wlist*)malloc(sizeof(t_wlist))))
		return (NULL);
	new->id = id;
	new->wall.start = create_vertex(wall.start.x, wall.start.y);
	new->wall.end = create_vertex(wall.end.x, wall.end.y);
	new->wall.normal = create_vertex(wall.normal.x, wall.normal.y);
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void add_wlist(t_wlist **list, t_wlist *new)
{
	new->next = *list;
	if (*list)
		(*list)->prev = new;
	(*list) = new;
}
