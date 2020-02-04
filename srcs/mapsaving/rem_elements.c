/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:54:02 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/04 19:27:32 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	ft_filter_walls(t_wlist *wlst, t_mouse *mous)
{
	
	t_wlist *tmwlst;
	int 	i;

	i = -1;

	mous->n_id = 0;
	tmwlst = wlst;
	if (wlst != NULL)
	{
		while (wlst)
		{
			if ((wlst->wall.start.x == mous->click1[0] && wlst->wall.start.y == mous->click1[1]) || (wlst->wall.end.x == mous->click1[0] && wlst->wall.end.y == mous->click1[1]))
				mous->n_id++;
			wlst = wlst->next;
		}
	}
	wlst = tmwlst;
	if(!(mous->lsid = (int *)malloc(sizeof(int) * mous->n_id)))
		exit(0);
	mous->n_id = 0;
	if(wlst != NULL)
	{
		while (wlst)
		{
			if ((wlst->wall.start.x == mous->click1[0] && wlst->wall.start.y == mous->click1[1]) || (wlst->wall.end.x == mous->click1[0] && wlst->wall.end.y == mous->click1[1]))
			{
				mous->lsid[mous->n_id] = wlst->id;
				mous->n_id++;
			}
			wlst = wlst->next;
		}
	}
	printf("ID's: %i\n", mous->lsid[0]);
}
//SEGFAULTS BETWEEN HERE
void	ft_remove_list_element(t_wlist *wlst, int id)
{
	while (id != wlst->id)
	{
		wlst = wlst->next;
	}
	if (wlst->next != NULL)
	{
		if (wlst->prev != NULL)
		{
			wlst->next->prev = wlst->prev;
			wlst->prev->next = wlst->next;
		}
		wlst->next->prev = NULL;
	}
	free(wlst);
}

void	rem_common_point(t_wlist *wlst, t_mouse *mous)
{
	int	i;

	i = -1;
	if(wlst != NULL)
	{
		while (wlst)
		{
			if ((wlst->wall.start.x == mous->click2[0] && wlst->wall.start.y == mous->click2[1]) 
				|| (wlst->wall.end.x == mous->click2[0] && wlst->wall.end.y == mous->click2[1]))
			{
				while (++i <= mous->n_id)
				{
					if (wlst->id == mous->lsid[i])
						ft_remove_list_element(wlst, wlst->id);
				}
			}
			wlst = wlst->next;
		}
	}
	free(mous->lsid);
}

void	rem_walls(t_map *map, t_mouse *mous, SDL_Event e, t_wlist **wlst)
{
	t_vertex 		tma;
	t_vertex 		tmb;
	t_wall	 		wall;
	int			i;

	i = -1;

	if ((ft_even_odd(mous->click) == 0))
	{
		loop_til_release();
		SDL_GetMouseState(&mous->click1[0], &mous->click1[1]);
		ft_fix_coords(map, &mous->click1[0], &mous->click1[1]);
		//filter wall id's with this coords in one of their two points
		ft_filter_walls(*wlst, mous);
	}
	else
	{
		loop_til_release();
		SDL_GetMouseState(&mous->click2[0], &mous->click2[1]);
		map->endx = map->ox + ((map->x - 1) * map->base_gap);
		map->endy = map->oy + ((map->y - 1) * map->base_gap);
		ft_fix_coords(map, &mous->click2[0], &mous->click2[1]);
		rem_common_point(*wlst, mous);
	}
	mous->click++;
}
//AND HERE SEGFAULTS
