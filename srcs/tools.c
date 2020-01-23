/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:28:17 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/23 16:01:47 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fdf.h"

void	ft_save_wall(t_mouse *mous)
{
	mous->prev = mous->walls;
}

void	ft_sub_fix_coords_a(t_mouse *mous, t_map *map)
{
	int	tempx;
	int	tempy;
	int	crossx;
	int	crossy;
	float	decimalx;
	float	decimaly;

	tempx = mous->click1[0] - map->ox;
	tempy = mous->click1[1] - map->oy;
	crossx = tempx / map->base_gap;
	crossy = tempy / map->base_gap;
	decimalx = tempx % (int)map->base_gap;
	decimaly = tempy % (int)map->base_gap;
	if (decimalx > (map->base_gap/2))
		crossx++;
	if (decimaly > (map->base_gap/2))
		crossy++;
	mous->click1[0] = crossx; 
	mous->click1[1] = crossy; 
}

void	ft_sub_fix_coords_b(t_mouse *mous, t_map *map)
{
	int	tempx;
	int	tempy;
	int	crossx;
	int	crossy;
	float	decimalx;
	float	decimaly;

	tempx = mous->click2[0] - map->ox;
	tempy = mous->click2[1] - map->oy;
	crossx = tempx / map->base_gap;
	crossy = tempy / map->base_gap;
	decimalx = tempx % (int)map->base_gap;
	decimaly = tempy % (int)map->base_gap;
	if (decimalx > (map->base_gap/2))
		crossx++;
	if (decimaly > (map->base_gap/2))
		crossy++;
	mous->click2[0] = crossx; 
	mous->click2[1] = crossy; 
}

void	ft_fix_coords(t_mouse *mous, t_map *map)
{
	if (mous->click1[0] < map->ox)
		mous->click1[0] = map->ox;
	if (mous->click1[1] < map->oy)
		mous->click1[1] = map->oy;
	if (mous->click1[0] > map->endx)
		mous->click1[0] = map->endx;
	if (mous->click1[1] > map->endy)
		mous->click1[1] = map->endy;

	if (mous->click2[0] < map->ox)
		mous->click2[0] = map->ox;
	if (mous->click2[1] < map->oy)
		mous->click2[1] = map->oy;
	if (mous->click2[0] > map->endx)
		mous->click2[0] = map->endx;
	if (mous->click2[1] > map->endy)
		mous->click2[1] = map->endy;
	ft_sub_fix_coords_a(mous, map);
	ft_sub_fix_coords_b(mous, map);
}
