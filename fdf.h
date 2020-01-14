/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:04:25 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/06 12:50:18 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft/libft.h"
# include <SDL.h>
# include <SDL_ttf.h>
# include "libft/get_next_line.h"
# include <stdio.h>//DEBUG
# include <math.h>

# define WIDTH 1600
# define HEIGHT 1200
# define NAME "MAP EDITOR"
# define OCRE 0xffa700
# define WHITE 0xf0f8ff
# define BROWN 0xcd7f32
# define GREEN 0x87a96b
# define SAND 0xfad6a5
# define LIGHT_BLUE 0xb2ffff
# define BLUE 0x21abcd
# define DEEP_BLUE 0x002fa7
# define RED 0xe32636

typedef	struct		s_mouse
{
	int				posx;
	int				posy;
	int				click1[2];
	int				click2[2];
	int				click;
}					t_mouse;

typedef	struct		s_color
{
	int				blue;
	int				green;
	int				red;
	int				alpha;
}					t_color;

typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
	SDL_Color		col;
}					t_point;

typedef struct		s_map
{
	t_point			**map;
	int				x;
	int				y;
	int				ox;
	int				oy;
	float			base_gap;
	float			base_h;
	char			proj;
	int				zmax;
}					t_map;

typedef struct		s_txt
{
	SDL_Surface		*txt_main;
	SDL_Surface		*txt_sub;
	TTF_Font		*font;
	SDL_Texture		*txt_tex_main;
	SDL_Texture		*txt_tex_sub;
	SDL_Rect		txt_rect_main;
	SDL_Rect		txt_rect_sub;
	SDL_Rect		txt_through;
	SDL_Color		txt_color;
}					t_txt;

typedef struct		s_fdf
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	//SDL_Surface		*surface;
	//TTF_Font		*font;
	t_txt			*txt;
	t_map			*map;
	int				height;
	Uint8			*pixels;
	char			*str;
	int				bpp;
	int				s_l;
	int				endian;
	int				*point_color;
	int				base_gap;
	SDL_Color		color;
}					t_fdf;

typedef	struct		s_line
{
	char			*str;
	int				x;
	int				y;
	struct s_line	*next;
	struct s_line	*prev;
}					t_line;

typedef	struct		s_bres
{
	int				dx;
	int				dy;
	int				dz;
	int				i;
	int				xinc;
	int				yinc;
	int				error;
	int				x;
	int				y;
	int				z;
	int				color;
}					t_bres;

t_map				*ft_parser(int fd);
t_line				*ft_list_alloc(int fd);
char				*ft_conform_line(char *str);
void				ft_fill_image(t_fdf *img, t_map *map);
void				ft_free_map(t_map *map);
void				ft_free_line(t_line *list);
void				ft_free_fdf(t_fdf *fdf);
void				ft_fdf(t_map *map);
t_fdf				*ft_ptr_init(char *name);
void				ft_print_lines(t_fdf *img, t_map *map);
void				ft_print_menu(t_fdf *img);
void				ft_light_up_pixel(t_bres *bres, t_fdf *img);
void				ft_origin(t_map *map);
int					ft_gap(t_map *map);
void				ft_get_controls(t_fdf *ptr);
float				ft_height(t_map *map);
int					ft_color(t_bres *bres, int color);
void				ft_modify_height(int key, t_fdf *ptr);
void				ft_zoom(int key, t_fdf *ptr);
void				ft_move(int key, t_fdf *ptr);
void				ft_iso_or_cart(int key, t_fdf *ptr);
void				ft_positive_or_negative(int key, t_fdf *ptr);
int					ft_color_positive(t_bres *bres);
int					ft_color_negative(t_bres *bres);
void				ft_cart_to_iso(t_map *map);
SDL_Color			ft_color_of_lower_element(t_point a, t_point b);
void				ft_attribute_color_to_points(t_map *map);
int					ft_height_to_color(int height);
SDL_Color			ft_hexa_to_ratio(int color);
void				ft_mouse_event(t_fdf *img, t_map *map, t_mouse *mous, SDL_Event e);
#endif
