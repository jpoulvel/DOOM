/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphic_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:04:41 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/17 19:08:25 by jpoulvel         ###   ########.fr       */
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
	if (!(ptr->renderer = SDL_CreateRenderer(ptr->window, -1, 0)))
		ft_error((char *)SDL_GetError(), 2);
//		ptr->texture = SDL_CreateTexture(ptr->renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 500, 300);
	//}
	return (1);
}

t_item			*ft_sub_init(TTF_Font *font, SDL_Color color)
{
	t_item	*sub;

	if (!(sub = malloc(sizeof(t_item))))
		return (0);
	TTF_SizeText(font, "Sous-menu", &sub->rect.w, &sub->rect.h);
	sub->rect.x = 10;
	sub->rect.y = 10;
	if (!(sub->surface = malloc(sizeof(SDL_Surface))))
		return (NULL);
	if (!(sub->surface = TTF_RenderText_Solid(font, "Sous-menu", color)))
		ft_error((char *)TTF_GetError(), 2);
		return (sub);
}

t_item			*ft_menu_init(TTF_Font *font, SDL_Color color)
{
	t_item		*menu;

	if (!(menu = malloc(sizeof(t_item))))
		return (NULL);
	TTF_SizeText(font, "Menu", &menu->rect.w, &menu->rect.h);
	menu->rect.x = 10;
	menu->rect.y = 10;
	if (!(menu->surface = malloc(sizeof(SDL_Surface))))
		return (NULL);
	if (!(menu->surface = TTF_RenderText_Solid(font, "Menu", color)))
		ft_error((char *)TTF_GetError(), 2);
	return (menu);
}

t_txt			*ft_txt_init(t_fdf *img)
{
	t_txt		*txt_ptr;

	if (!(txt_ptr = malloc(sizeof(t_txt))))
		return (NULL);
	if (!(txt_ptr->font = TTF_OpenFont("Fonts/antika/Antika.ttf", 32)))
		ft_error((char *)TTF_GetError(), 2);
	txt_ptr->color = ft_hexa_to_ratio(SAND);
	if (!(txt_ptr->menu = ft_menu_init(txt_ptr->font, txt_ptr->color)))
// address  - type     -        valeur      nom
// 0x99qqqqq : ***txt    : 0x776767    | &txt_ptr2 == txt_ptr3 == ...
// 0x776767 :  **txt     : 0x432934    | &txt_ptr == txt_ptr2 == *txt_ptr3
// 0x432934 :  *txt      : 0x3428483   | &txt == txt_ptr == *txt_ptr2
// 0x3428483 : txt       : { struct }  | txt == *txt_ptr
		return (NULL);
	if (!(txt_ptr->item = ft_sub_init(txt_ptr->font, txt_ptr->color)))
		return (NULL);
	return (txt_ptr);
//	if (!(ft_through_init(txt->font, txt->through))
	//	return (NULL);
}

t_fdf			*ft_ptr_init(char *name)
{
	t_fdf		*ptr;

	if (!(ptr = malloc(sizeof(t_fdf))))
		return (NULL);
	if (!(ft_sdl_init(ptr, name)))
		return (NULL);
	if (!(ptr->txt = ft_txt_init(ptr)))
		return (NULL);
	ptr->bpp = 32;
	ptr->s_l = WIDTH * 4;
	ptr->height = HEIGHT;
	ptr->endian = 0;
	ptr->color = ft_hexa_to_ratio(RED);
	ptr->pixels = (Uint8*)malloc(sizeof(Uint8) * (WIDTH * HEIGHT));
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
