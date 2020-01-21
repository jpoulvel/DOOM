/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:22:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/21 12:23:36 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void		ft_origin(t_map *map)
{
	map->ox = (WIDTH - ((map->map[map->y - 1][map->x - 1].x - map->map[0][0].x)
				* map->base_gap)) / 2;
	map->oy = (HEIGHT - ((map->map[map->y - 1][map->x - 1].y)
			* map->base_gap)) / 2;
}

float		ft_height(t_map *map)
{
	float	height;

	if (map->zmax >= 1)
		height = 50 / map->base_gap;
	if (map->zmax >= 50)
		height = 10 / map->base_gap;
	if (map->zmax >= 100)
		height = 1 / (2 * map->base_gap);
	if (map->zmax >= 500)
		height = 1 / (10 * map->base_gap);
	return (height);
}

int			ft_gap(t_map *map)
{
	int		gap_H;
	int		gap_W;

	gap_H = (HEIGHT * 0.9) / map->x;
	gap_W = (WIDTH * 0.9) / map->y;
	if (gap_H > gap_W)
		return (gap_W);
	else
		return (gap_H);
}
