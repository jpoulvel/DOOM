/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:04:41 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/06 13:07:10 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int			ft_sdl_init(t_fdf *ptr, char *name)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		ft_error((char *)SDL_GetError(), 2);
	if (TTF_Init() < 0)
		ft_error((char *)TTF_GetError(), 2);
	if (!(ptr->window = SDL_CreateWindow(name, SDL_WINDOWPOS_CENTERED, 
					SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, 0)))
		ft_error((char *)SDL_GetError(), 2);
	//else
	//{
		if (!(ptr->renderer = SDL_CreateRenderer(ptr->window, -1, 0)))
			ft_error((char *)SDL_GetError(), 2);
		//if (!(ptr->font = TTF_OpenFont("Fonts/antika/Antika.ttf", 175)))
			//ft_error((char *)TTF_GetError(), 2);//MOVED TO t_txt_init
//		ptr->texture = SDL_CreateTexture(ptr->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 500, 300);
	//}
	return (1);
}

int			ft_txt_init(t_txt *txt)
{
	if (!(txt = malloc(sizeof(t_txt))))
		return (NULL);
	txt->txt_main = (surface);
	txt->txt_sub = (surface);
	if (!(txt->font = TTF_OpenFont("Fonts/antika/Antika.ttf", 175)))
		ft_error((char *)TTF_GetError(), 2);
	txt->txt_tex_main = (texture);
	txt->txt_tex_sub = (texture);
	txt->txt_rect_main = (Rect);
	txt->txt_rect_sub = (Rect);
	txt->txt_rect_through = (Rect);
	txt->color = ft_hexa_to_ratio(SAND);
	return (1);
}

t_fdf			*ft_ptr_init(char *name)
{
	t_fdf		*ptr;
	//SDL_Surface *screenSurface; Why a surface?

	if (!(ptr = malloc(sizeof(t_fdf))))
		return (NULL);
	if (!(ft_sdl_init(ptr, name)))
		return (NULL);
	if (!(ft_txt_init(&ptr->txt))
		return (NULL);
//	ptr->win_ptr = mlx_new_window(ptr->mlx_ptr, WIDTH, HEIGHT, name);
//	ptr->img_ptr = mlx_new_image(ptr->mlx_ptr, WIDTH, HEIGHT);
	ptr->bpp = 32;
	ptr->s_l = WIDTH * 4;
	ptr->height = HEIGHT;
	ptr->endian = 0;
	ptr->color = ft_hexa_to_ratio(RED);
	ptr->pixels = (Uint8*)malloc(sizeof(Uint8) * (WIDTH * HEIGHT));
//	ptr->str = mlx_get_data_addr(ptr->img_ptr, &(ptr->bpp), &(ptr->s_l),
//			&(ptr->endian));
//	ft_bzero(ptr->str, (WIDTH * 4 * HEIGHT));
	ft_bzero(ptr->pixels, (WIDTH * HEIGHT * sizeof(Uint8)));
	return (ptr);
}

t_point		*ft_init_coord(int x, int y)
{
	t_point	*p;

	if (!(p = malloc(sizeof(t_point))))
		return (NULL);
	p->x = x;
	p->y = y;
	return (p);
}

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
