/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 17:04:47 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/07 17:26:46 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"
/*
void		ft_free_map(t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->y)
		free(map->map[i]);
	free(map);
}*/

void		ft_free_fdf(t_fdf *fdf)
{
	//mlx_destroy_window(fdf->mlx_ptr, fdf->win_ptr);
	//mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	//ft_free_map(fdf->map);
//	free(fdf->mlx_ptr);
	//Close the TTF and SDL
	SDL_DestroyRenderer(fdf->renderer);
	SDL_DestroyWindow(fdf->window);
	TTF_Quit();
	SDL_Quit();
	//free(fdf->window);
	free(fdf);
}

void		ft_free_line(t_line *list)
{
	t_line	*tmp;

	while (list != NULL)
	{
		tmp = list;
		list = list->next;
		free(tmp->str);
		free(tmp);
	}
	free(list);
}
