/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:28:17 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/03 15:25:27 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../../fdf.h"

void	ft_sub_fix_coords(t_map *map, int *x, int *y)
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

void	ft_fix_coords(t_map *map, int *x, int *y)
{
	if (*x < map->ox)
		*x = map->ox;
	if (*y < map->oy)
		*y = map->oy;
	if (*x > map->endx)
		*x = map->endx;
	if (*y > map->endy)
		*y = map->endy;

	ft_sub_fix_coords(map, x, y);
}
