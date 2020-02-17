/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_walls.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 19:07:13 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/17 14:08:29 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void			ft_print_walls(t_fdf *img, t_wlist *wlst)
{
	if (wlst != NULL)
	{
		ft_putendl("Ca entre dans wlst != NULL");
		while (wlst)
		{
			printf("walls printed :start (%f, %f)\nend(%f, %f)\n", wlst->wall.start.x, wlst->wall.start.y, wlst->wall.end.x, wlst->wall.end.y);
			ft_trace_line(wlst->wall.start, wlst->wall.end, img);
			/*SDL_SetRenderDrawColor(img->renderer, 0, 255, 0, 255);
			SDL_RenderDrawLine(img->renderer, img->map->ox + wlst->wall.start.x * img->map->base_gap, img->map->oy + wlst->wall.start.y * img->map->base_gap, img->map->ox + wlst->wall.end.x * img->map->base_gap, img->map->oy + wlst->wall.end.y * img->map->base_gap);*///REPLACED BY FT_TRACE_LINE ABOVE
			print_point_box(img, wlst);
			wlst = wlst->next;
		}
	}
}
