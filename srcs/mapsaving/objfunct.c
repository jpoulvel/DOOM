/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:22:03 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/07 18:26:34 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void print_obj_box(t_fdf *img, t_olist *olst)
{
	SDL_SetRenderDrawColor(img->renderer, 153, 51, 255, 0);
	SDL_RenderDrawLine(img->renderer, (img->map->ox + olst->obj.x * img->map->base_gap - 5), (img->map->oy + olst->obj.y * img->map->base_gap - 5), (img->map->ox + olst->obj.x * img->map->base_gap + 5), (img->map->oy + olst->obj.y * img->map->base_gap) - 5);
	SDL_RenderDrawLine(img->renderer, (img->map->ox + olst->obj.x * img->map->base_gap - 5), (img->map->oy + olst->obj.y * img->map->base_gap - 5), (img->map->ox + olst->obj.x * img->map->base_gap - 5), (img->map->oy + olst->obj.y * img->map->base_gap) + 5);
	SDL_RenderDrawLine(img->renderer, (img->map->ox + olst->obj.x * img->map->base_gap + 5), (img->map->oy + olst->obj.y * img->map->base_gap - 5), (img->map->ox + olst->obj.x * img->map->base_gap + 5), (img->map->oy + olst->obj.y * img->map->base_gap) + 5);
	SDL_RenderDrawLine(img->renderer, (img->map->ox + olst->obj.x * img->map->base_gap + 5), (img->map->oy + olst->obj.y * img->map->base_gap + 5), (img->map->ox + olst->obj.x * img->map->base_gap - 5), (img->map->oy + olst->obj.y * img->map->base_gap) + 5);
}

void	ft_sub_fix_obj_coords(int *x, int *y, t_map *map)
{
	int	tempx;
	int	tempy;
	int	crossx;
	int	crossy;
	float	decimalx;
	float	decimaly;

	tempx = *x - map->ox;
	tempy = *y - map->oy;
	crossx = tempx / map->base_gap;
	crossy = tempy / map->base_gap;
	decimalx = tempx % (int)map->base_gap;
	decimaly = tempy % (int)map->base_gap;
	if (decimalx > (map->base_gap/2))
		crossx++;
	if (decimaly > (map->base_gap/2))
		crossy++;
	*x = crossx; 
	*y = crossy; 
}

void	ft_fix_obj_coords(int *x, int *y, t_map *map)
{
	if (*x < map->ox)
		*x = map->ox;
	if (*y < map->oy)
		*y = map->oy;
	if (*x > map->endx)
		*x = map->endx;
	if (*y > map->endy)
		*y = map->endy;
	ft_sub_fix_obj_coords(x, y, map);
}

void	ft_print_obj(t_fdf *img, t_olist *olst)
{
	t_olist *tm;

	if(olst != NULL)
	{
		while (olst)
		{
			SDL_SetRenderDrawColor(img->renderer, 0, 255, 0, 255);
			print_obj_box(img, olst);
			olst = olst->next;
		}
	}
}

void	set_object(t_map *map, t_mouse *mous, SDL_Event e, t_olist **olst)
{
	t_vertex	 		obj;
	t_olist 		*tmolst;
	int			x;
	int			y;
	
	loop_til_release();
	SDL_GetMouseState(&x, &y);
/*	map->endx = map->ox + ((map->x - 1) * map->base_gap);
	map->endy = map->oy + ((map->y - 1) * map->base_gap);*/
	ft_fix_coords(map, &x, &y);
	if (*olst == NULL)
	{
		obj = create_vertex(x, y);
		*olst = new_olist(obj, mous->nobj);
	}
	else
	{
		obj = create_vertex(x, y);
		tmolst = new_olist(obj, mous->nobj);
		add_olist(olst, tmolst);
	}
	mous->nobj++;
}
