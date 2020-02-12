/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rem_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/04 12:54:02 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/12 12:32:34 by aruiz-ba         ###   ########.fr       */
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
	if (mous->n_id > 0)
	{
		if(!(mous->lsid = (int *)malloc(sizeof(int) * mous->n_id)))
			exit(0);
	}
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
}
//SEGFAULTS BETWEEN HERE
/*void	ft_remove_list_element(t_wlist *wlst, int id)
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
	if (wlst->next == NULL && wlst->prev == NULL) //que cohone e esto
		wlst = NULL;
	else
		free(wlst);
	//necesita hacer wlst == NULL si nos quedamos sin paredes
}*/

void ft_remove_list_element(t_wlist **list, int id)
{
	t_wlist *tmp;
	t_wlist *p_stock;
	t_wlist *n_stock;

	printf("Id being removed: %i\n", id);
	if (*list)
	        while ((*list)->prev)
	    	    (*list) = (*list)->prev; //is crashing here
	tmp = *list;
	if (tmp->id == id)
	{
	    *list = tmp->next;
	    free(tmp);
	    return ;
	}
	while (tmp != NULL && tmp->id != id)
	    tmp = tmp->next;
	if (tmp == NULL)
	    return ;
	p_stock = tmp->prev;
	n_stock = tmp->next;
	if (p_stock)
	        p_stock->next = n_stock;
	if (n_stock)
	        n_stock->prev = p_stock;
	free(tmp);
}

void	rem_common_point(t_wlist **wlst, t_mouse *mous)
{
	int	i;

	i = -1;
	if(wlst != NULL)
	{
		while (wlst)
		{
			if (((*wlst)->wall.start.x == mous->click2[0] && (*wlst)->wall.start.y == mous->click2[1]) 
				|| ((*wlst)->wall.end.x == mous->click2[0] && (*wlst)->wall.end.y == mous->click2[1]))
			{
				i = -1;
				while (++i <= mous->n_id)
				{
					if ((*wlst)->id == mous->lsid[i])
						break ;
				}
				if ((*wlst)->id == mous->lsid[i])
					break ;
			}
			*wlst = (*wlst)->next;
		}
		ft_remove_list_element(wlst, (*wlst)->id);
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
		printf("Id es: %i\n", mous->n_id);
		if (mous->n_id > 0)
		{
			SDL_GetMouseState(&mous->click2[0], &mous->click2[1]);
			map->endx = map->ox + ((map->x - 1) * map->base_gap);
			map->endy = map->oy + ((map->y - 1) * map->base_gap);
			ft_fix_coords(map, &mous->click2[0], &mous->click2[1]);
			rem_common_point(wlst, mous);
		}
	}
	mous->click++;
}
//AND HERE SEGFAULTS
