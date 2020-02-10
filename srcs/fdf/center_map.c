/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   center_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:22:59 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/07 19:02:36 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void		ft_origin(t_map *map)
{
	map->ox = (WIDTH - ((map->width - 1) * map->base_gap)) / 2;
	map->oy = (HEIGHT - ((map->height - 1)* map->base_gap)) / 2;
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

	gap_H = (HEIGHT * 0.9) / map->width;
	gap_W = (WIDTH * 0.9) / map->height;
	if (gap_H > gap_W)
		return (gap_W);
	else
		return (gap_H);
}
