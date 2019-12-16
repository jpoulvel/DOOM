/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:40:41 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/12/16 12:09:45 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_trace_line(t_point a, t_point b, t_fdf *img)
{
	int			gap;
	int			ox;
	int			oy;
	SDL_Color	color;

	gap = img->map->base_gap;
	ox = img->map->ox;
	oy = img->map->oy;
	color = ft_color_of_lower_element(a, b);
	SDL_SetRenderDrawColor(img->renderer, color.r, color.g, color.b, 
			color.a);
	SDL_RenderDrawLine(img->renderer, ox + a.x * gap,
			oy + a.y * gap, ox + b.x * gap, oy + b.y * gap);
}

void		ft_print_lines(t_fdf *img, t_map *map)
{
	int		x;
	int		y;

	y = -1;
	while (++y < map->y)
	{
		x = -1;
		while (++x < map->x)
		{
			if (x < map->x - 1)
				ft_trace_line(map->map[y][x], map->map[y][x + 1], img);
			if (y < map->y - 1)
				ft_trace_line(map->map[y][x], map->map[y + 1][x], img);
		}
	}
}

void		ft_fill_image(t_fdf *img, t_map *map)
{
	map->base_gap = ft_gap(map);
	map->base_h = ft_height(map);
	ft_origin(map);
	ft_print_lines(img, map);
	ft_print_menu(img);
}

void		ft_fdf(t_map *map)
{
	t_fdf	*img;
	t_mouse	mouse;
	int		isquit;
	SDL_Event event;

	isquit = 0;
	if (!(img = ft_ptr_init(NAME)))
		return ;
	img->map = map;
	//ft_cart_to_iso(map);
	ft_fill_image(img, map);
	//SDL_UpdateTexture(img->texture, NULL, img->pixels, WIDTH * 4);
	SDL_RenderCopy(img->renderer, img->texture, NULL, NULL);
	SDL_RenderPresent(img->renderer);
	bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));

	//replace with infinite loop?
	while (isquit == 0) 
	{
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				isquit = 1;
			ft_mouse_event(img, map, &mouse, event);
		}
	//Replace with infinite loop?
	}
//	SDL_Delay(500);
//	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
//	ft_print_menu(img->mlx_ptr, img->win_ptr);
//	ft_get_controls(img);
//	mlx_loop(img->mlx_ptr);
}
