/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:40:41 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/13 15:55:09 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void			print_point_box(t_fdf *img, t_wlist *wlst)
{
			SDL_SetRenderDrawColor(img->renderer, 0, 255, 255, 255);
			SDL_RenderDrawLine(img->renderer, (img->map->ox + wlst->wall.start.x * img->map->base_gap - 5), (img->map->oy + wlst->wall.start.y * img->map->base_gap - 5), (img->map->ox + wlst->wall.start.x * img->map->base_gap + 5), (img->map->oy + wlst->wall.start.y * img->map->base_gap) - 5);
			SDL_RenderDrawLine(img->renderer, (img->map->ox + wlst->wall.start.x * img->map->base_gap - 5), (img->map->oy + wlst->wall.start.y * img->map->base_gap - 5), (img->map->ox + wlst->wall.start.x * img->map->base_gap - 5), (img->map->oy + wlst->wall.start.y * img->map->base_gap) + 5);
			SDL_RenderDrawLine(img->renderer, (img->map->ox + wlst->wall.start.x * img->map->base_gap + 5), (img->map->oy + wlst->wall.start.y * img->map->base_gap - 5), (img->map->ox + wlst->wall.start.x * img->map->base_gap + 5), (img->map->oy + wlst->wall.start.y * img->map->base_gap) + 5);
			SDL_RenderDrawLine(img->renderer, (img->map->ox + wlst->wall.start.x * img->map->base_gap + 5), (img->map->oy + wlst->wall.start.y * img->map->base_gap + 5), (img->map->ox + wlst->wall.start.x * img->map->base_gap - 5), (img->map->oy + wlst->wall.start.y * img->map->base_gap) + 5);

			SDL_RenderDrawLine(img->renderer, (img->map->ox + wlst->wall.end.x * img->map->base_gap - 5), (img->map->oy + wlst->wall.end.y * img->map->base_gap - 5), (img->map->ox + wlst->wall.end.x * img->map->base_gap + 5), (img->map->oy + wlst->wall.end.y * img->map->base_gap) - 5);
			SDL_RenderDrawLine(img->renderer, (img->map->ox + wlst->wall.end.x * img->map->base_gap - 5), (img->map->oy + wlst->wall.end.y * img->map->base_gap - 5), (img->map->ox + wlst->wall.end.x * img->map->base_gap - 5), (img->map->oy + wlst->wall.end.y * img->map->base_gap) + 5);
			SDL_RenderDrawLine(img->renderer, (img->map->ox + wlst->wall.end.x * img->map->base_gap + 5), (img->map->oy + wlst->wall.end.y * img->map->base_gap - 5), (img->map->ox + wlst->wall.end.x * img->map->base_gap + 5), (img->map->oy + wlst->wall.end.y * img->map->base_gap) + 5);
			SDL_RenderDrawLine(img->renderer, (img->map->ox + wlst->wall.end.x * img->map->base_gap + 5), (img->map->oy + wlst->wall.end.y * img->map->base_gap + 5), (img->map->ox + wlst->wall.end.x * img->map->base_gap - 5), (img->map->oy + wlst->wall.end.y * img->map->base_gap) + 5);
}

void			ft_trace_line(t_point a, t_point b, t_fdf *img)
{
	int			gap;
	int			ox;
	int			oy;
	SDL_Color	color;

	gap = img->map->base_gap;
	ox = img->map->ox;
	oy = img->map->oy;
	//color = ft_color_of_lower_element(a, b);
	color = ft_hexa_to_ratio(LIGHT_BLUE);//fixed color until we adjust it
	SDL_SetRenderDrawColor(img->renderer, color.r, color.g, color.b, 
			color.a);
	SDL_RenderDrawLine(img->renderer, ox + a.x * gap,
			oy + a.y * gap, ox + b.x * gap, oy + b.y * gap);
}

void			ft_print_grid(t_fdf *img, t_map *map)
{
	int			x;
	int			y;
	t_point		start;
	t_point		end;

	y = -1;
	while (++y < map->height)
	{
		x = -1;
		while (++x < map->width)
		{
			start.x = x;
			start.y = y;
			if (x < map->width - 1)
			{
				end.x = x + 1;
				end.y = y;
				ft_trace_line(start, end, img);
			}
			if (y < map->height - 1)
			{
				end.x = x;
				end.y = y + 1;
				ft_trace_line(start, end, img);
			}
		}
	}
}

void			ft_fdf(t_map *map, char *map_name)
{
	t_fdf		*img;
	t_mouse		mouse;

	if (!(img = ft_ptr_init(map_name)))
		return ;
	mouse.loop = 0;
	img->map = map;
	ft_clear_and_render(img);
	//ft_cart_to_iso(map);
	ft_infinite_loop(img, mouse);
}
