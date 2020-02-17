/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:40:41 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/17 14:59:05 by jpoulvel         ###   ########.fr       */
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

void			ft_mouse_init(t_mouse *mous)
{
//	mous->posx = 0;apparently not used
//	mous->posy = 0;apparently not used
/*	mous->click1[0] = 5;
	mous->click1[1] = 5;
	mous->click2[0] = 5;
	mous->click2[1] = 5;*/
	mous->click = 0;
//	mous.nwalls = 0;
	mous->nobj = 0;
	mous->loop = -1;
}

void			ft_key_init(t_keys *key)
{
	key->up = 0;
	key->down = 0;
	key->left = 0;
	key->right = 0;
	key->zoom_in = 0;
	key->zoom_out = 0;
}

void			ft_infinite_loop(t_fdf *img, t_mouse mous)
{
	int			isquit;
	SDL_Event	event;
//	t_wlist 	*wlst;
	t_olist 	*olst;
	t_keys		key;

	printf("entree infinite loop\n");
	ft_key_init(&key);
	printf("ok key_init\n");
	isquit = 0;
//	wlst = NULL;
	olst = NULL;
	while (isquit == 0)
	{
		SDL_PollEvent(&event);
		while (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_KEYDOWN)
		{
			printf("moving or click\n");
			if (event.type == SDL_QUIT)
				exit (0);
			ft_menu_event(img->map, &mous, event);
			ft_print_pressed_button(img, mous.loop);
			ft_clear_and_render(img/*, wlst, olst*/);
			ft_keys_event(img->map, event, &key);
			ft_mouse_event(img, &mous, event/*, &wlst*/, &olst);
		//	if (mous.loop == 2)
		//		ft_save_map(img, olst/*, mous.nwalls*/);
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
	printf("ok_mouse_init\n");
	//mouse.loop = -1;
	img->map = map;
	ft_clear_and_render(img);
	//ft_cart_to_iso(map);
	ft_infinite_loop(img, mous);
}
