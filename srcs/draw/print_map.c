/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:40:41 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/18 13:02:56 by jpoulvel         ###   ########.fr       */
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

void			ft_trace_line(t_point a, t_point b, t_fdf *img, int col)
{
	int			gap;
	int			ox;
	int			oy;
	SDL_Color	color;

	gap = img->map->base_gap;
	ox = img->map->ox;
	oy = img->map->oy;
	//color = ft_color_of_lower_element(a, b);
	color = ft_hexa_to_ratio(col);//fixed color until we adjust it
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
				ft_trace_line(start, end, img, LIGHT_BLUE);
			}
			if (y < map->height - 1)
			{
				end.x = x;
				end.y = y + 1;
				ft_trace_line(start, end, img, LIGHT_BLUE);
			}
		}
	}
}

void			ft_infinite_loop(t_fdf *img, t_mouse *mous)
{
	int			isquit;
	SDL_Event	event;
	t_olist 	*olst;
	t_keys		key;

	ft_key_init(&key);
	isquit = 0;
	olst = NULL;
	while (isquit == 0)
	{
		SDL_PollEvent(&event);
		while (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_KEYDOWN)
		{
			if (event.type == SDL_QUIT)
				exit (0);
			if (mous->loop == 2)
				ft_save_map(img, olst/*, mous.nwalls*/);
			ft_menu_event(img->map, mous, event);
			ft_print_pressed_button(img, mous->loop);
			ft_clear_and_render(img/*, wlst, olst*/);
			ft_keys_event(img->map, event, &key);
			ft_mouse_event(img, mous, event/*, &wlst*/, &olst);
		}
	}
}

void			ft_fdf(t_map *map, char *map_name)
{
	t_fdf		*img;
	t_mouse		mous;

	if (!(img = ft_ptr_init(map_name)))
		return ;
	ft_mouse_init(&mous);
	img->map = map;
	ft_clear_and_render(img);
	//ft_cart_to_iso(map);
	ft_infinite_loop(img, &mous);
}
