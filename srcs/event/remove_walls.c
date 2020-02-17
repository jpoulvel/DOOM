/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:21:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/14 20:01:54 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int			points_are_same(t_point a, t_point b)
{
	if (a.x == b.x && a.y == b.y)
		return (1);
	return (0);
}

int			walls_are_same(t_wall a, t_wall b)
{
		if ((points_are_same(a.start, b.end) &&
					points_are_same(a.end, b.end))
				|| (points_are_same(a.start, b.end) &&
				 points_are_same(a.end, b.start)))
			return (1);
		return (0);
}

void		remove_element_from_list(t_wlist **wlist)
{
	if ((*wlist)->prev != NULL)
	{
		if ((*wlist)->next != NULL)
		{
			(*wlist)->prev->next = (*wlist)->next;
			(*wlist)->next->prev = (*wlist)->prev;
		}
		else
			(*wlist)->prev->next = NULL;
	}
	else
	{
		if ((*wlist)->next != NULL)
			(*wlist)->next->prev = NULL;
	}
	free(*wlist);
}

int			ft_remove_wall(t_wall wall, t_wlist **wlist)
{
	t_wlist	*tmp;

	if (*wlist == NULL)
		return (0);
	tmp = *wlist;
	while (*wlist != NULL)
	{
		if (walls_are_same((*wlist)->wall, wall))
		{
			remove_element_from_list(wlist);
			return (1);
		}
		*wlist = (*wlist)->next;
	}
	*wlist = tmp;
	return (0);
}

int				click_to_remove_wall(t_map *map, t_mouse *mous, SDL_Event e)
{
	t_point 	start;
	t_point 	end;
	t_wall		wall;

	wall = click_to_wall_coord(map, mous, e);
	ft_remove_wall(wall, &map->wlst);
	return (0);
}
