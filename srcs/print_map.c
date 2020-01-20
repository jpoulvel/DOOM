/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 14:40:41 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/20 16:10:01 by jpoulvel         ###   ########.fr       */
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

void			ft_print_lines(t_fdf *img, t_map *map)
{
	int			x;
	int			y;

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

void			ft_fill_image(t_fdf *img)
{
	ft_print_lines(img, img->map);
	ft_print_menu(img);
}
