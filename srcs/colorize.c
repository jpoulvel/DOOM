/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/12 12:56:35 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/23 12:41:16 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

SDL_Color	ft_hexa_to_ratio(int color)
{
	SDL_Color	col;

	col.b = (color & 0xff);
	col.g = (color & 0xff00) >> 8;
	col.r = (color & 0xff0000) >> 16;
	col.a = 255;
	return (col);
}

int			ft_height_to_color(int height)
{
	int		color;

	if (height == 0)
		color = DEEP_BLUE;
	else if (height == 1)
		color = RED;
	else if (height == 2)
		color = OCRE;
	else if (height == 3)
		color = WHITE;
	else if (height == 4)
		color = GREEN;
	return (color);
}

void			ft_attribute_color_to_points(t_map *map)
{
	int			x;
	int			y;

	y = -1;
	while (++y < map->x)
	{
		x = -1;
		while (++x < map->y)
		{
			map->map[x][y].color = ft_height_to_color(map->map[x][y].z);
			map->map[x][y].col = ft_hexa_to_ratio(map->map[x][y].color);
		}
	}
}
/*
int			ft_color(t_bres *bres, int sign)
{
	if (sign == 'P')
		return (ft_color_positive(bres));
	if (sign == 'N')
		return (ft_color_negative(bres));
	return (0);
}
*/
SDL_Color		ft_color_of_lower_element(t_point a, t_point b)
{
	if (a.z > b.z)
		return (b.col);
	else
		return (a.col);
}

