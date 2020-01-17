/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/07 18:28:17 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/08 17:21:34 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../fdf.h"

void	ft_save_wall(t_mouse *mous)
{
	mous->prev = mous->walls;
	
}

void	ft_sub_fix_coords_a(t_mouse *mous, t_fdf *img)
{
	int	tempx;
	int	tempy;
	int	crossx;
	int	crossy;
	float	decimalx;
	float	decimaly;

	tempx = mous->click1[0] - img->map->ox;
	tempy = mous->click1[1] - img->map->oy;
	crossx = tempx / img->map->base_gap;
	crossy = tempy / img->map->base_gap;
	decimalx = tempx % (int)img->map->base_gap;
	decimaly = tempy % (int)img->map->base_gap;
	if (decimalx > (img->map->base_gap/2))
		crossx++;
	if (decimaly > (img->map->base_gap/2))
		crossy++;
	mous->click1[0] = img->map->ox + crossx * img->map->base_gap; 
	mous->click1[1] = img->map->oy + crossy * img->map->base_gap; 
}

void	ft_sub_fix_coords_b(t_mouse *mous, t_fdf *img)
{
	int	tempx;
	int	tempy;
	int	crossx;
	int	crossy;
	float	decimalx;
	float	decimaly;

	tempx = mous->click2[0] - img->map->ox;
	tempy = mous->click2[1] - img->map->oy;
	crossx = tempx / img->map->base_gap;
	crossy = tempy / img->map->base_gap;
	decimalx = tempx % (int)img->map->base_gap;
	decimaly = tempy % (int)img->map->base_gap;
	if (decimalx > (img->map->base_gap/2))
		crossx++;
	if (decimaly > (img->map->base_gap/2))
		crossy++;
	mous->click2[0] = img->map->ox + crossx * img->map->base_gap; 
	mous->click2[1] = img->map->oy + crossy * img->map->base_gap; 
}

void	ft_fix_coords(t_mouse *mous, t_fdf *img)
{
	if (mous->click1[0] < img->map->ox)
		mous->click1[0] = img->map->ox;
	if (mous->click1[1] < img->map->oy)
		mous->click1[1] = img->map->oy;
	if (mous->click1[0] > img->map->endx)
		mous->click1[0] = img->map->endx;
	if (mous->click1[1] > img->map->endy)
		mous->click1[1] = img->map->endy;

	if (mous->click2[0] < img->map->ox)
		mous->click2[0] = img->map->ox;
	if (mous->click2[1] < img->map->oy)
		mous->click2[1] = img->map->oy;
	if (mous->click2[0] > img->map->endx)
		mous->click2[0] = img->map->endx;
	if (mous->click2[1] > img->map->endy)
		mous->click2[1] = img->map->endy;
	ft_sub_fix_coords_a(mous, img);
	ft_sub_fix_coords_b(mous, img);
}
