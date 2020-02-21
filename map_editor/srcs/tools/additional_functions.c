/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additional_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 14:22:49 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/18 13:33:12 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

/*
** Replaces all other char than number, - or space into spaces
*/
/*
char		*ft_conform_line(char *str)
{
	int		i;

	i = 2;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 1 || str[i] == ' ' ||
				(str[i] == '-' && ft_isdigit(str[i + 1]) == 1))
			i++;
		else
		{
			str[i] = ' ';
			i++;
		}
	}
	str[i] = '\0';
	return (str);
}

void		ft_cart_to_iso(t_map *map)
{
	t_point	cart;
	int		i;
	int		j;

	i = -1;
	map->zmax = 0;
	while (++i < map->y)
	{
		j = -1;
		while (++j < map->x)
		{
			cart = map->map[i][j];
			map->map[i][j].x = cart.x - cart.y;
			map->map[i][j].y = (cart.x + cart.y) / 2;
			if (map->map[i][j].z > map->zmax)
				map->zmax = map->map[i][j].z;
		}
	}
	map->proj = 'I';
}

int			ft_color_positive(t_bres *bres)
{
	float	height;
	int		color;

	height = bres->z;
	if (height > 160)
		color = WHITE;
	else if (height > 100)
		color = BROWN;
	else if (height > 15)
		color = SAND;
	else if (height > 0)
		color = GREEN;
	else if (height > -7)
		color = LIGHT_BLUE;
	else if (height > -100)
		color = BLUE;
	else if (height <= -100)
		color = DEEP_BLUE;
	return (color);
}

int			ft_color_negative(t_bres *bres)
{
	float	height;
	int		color;

	height = bres->z;
	if (height > 160)
		color = DEEP_BLUE;
	else if (height > 100)
		color = BLUE;
	else if (height > 15)
		color = LIGHT_BLUE;
	else if (height > 0)
		color = GREEN;
	else if (height > -7)
		color = SAND;
	else if (height > -100)
		color = BROWN;
	else if (height <= -100)
		color = WHITE;
	return (color);
}*/
