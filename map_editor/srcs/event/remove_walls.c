/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/14 15:21:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/21 11:27:48 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

int				points_are_same(t_point a, t_point b)
{
	if (a.x == b.x && a.y == b.y)
		return (1);
	return (0);
}

int				walls_are_same(t_wall a, t_wall b)
{
		if ((points_are_same(a.start, b.start) &&
					points_are_same(a.end, b.end))
				|| (points_are_same(a.start, b.end) &&
				 points_are_same(a.end, b.start)))
			return (1);
		return (0);
}

void			remove_element_from_list(t_wlist **wlist)
{
	if ((*wlist)->prev != NULL)
	{
		if ((*wlist)->next != NULL)
		{
			ft_putendl("Entree if 1 if 1");
			(*wlist)->prev->next = (*wlist)->next;
			(*wlist)->next->prev = (*wlist)->prev;
		}
		else
		{
			ft_putendl("Entree if 1 else");
			(*wlist)->prev->next = NULL;
		}
	}
	else
	{
		ft_putendl("Entree else 1");
		if ((*wlist)->next != NULL)
		{
			ft_putendl("Entree else 1 if 1");
			(*wlist)->next->prev = NULL;
		}
	}
	free(*wlist);
}

int				ft_remove_wall(t_wall wall, t_wlist **wlist)
{
	t_wlist		*tmp;

	ft_putendl("Entree dans ft_remove_walls");
	if (*wlist == NULL)
	{
		ft_putendl("wlist == null");
		return (0);
	}
	tmp = *wlist;
	while (*wlist != NULL)
	{
		ft_putendl("wlist != null");
		if (walls_are_same((*wlist)->wall, wall))
		{
			ft_putendl("Walls are same");
			remove_element_from_list(wlist);
			ft_putendl("apres remove_from_list");
			*wlist = tmp;
			return (1);
		}
		*wlist = (*wlist)->next;
	}
	*wlist = tmp;
	return (0);
}

int					click_to_remove_wall(t_map *map, t_mouse *mous, SDL_Event e)
{
	static t_wall	wall;

	ft_putendl("Entree dans click_to_remove_walls");
	click_to_wall_coord(&wall,map, mous, e);
//	printf("wall.start = [%f, %f], wall.end = [%f, %f]", wall.start.x, wall.start.y, wall.end.x, wall.end.y);
	if (ft_even_odd(mous->click) == 1)
	{
		ft_putendl("ft_even_Odd = 1");
		ft_remove_wall(wall, &map->wlst);
	}
	mous->click++;
	return (0);
}
