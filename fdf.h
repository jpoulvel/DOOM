/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 19:04:25 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/17 15:13:20 by jpoulvel         ###   ########.fr       */
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
# define ZOOM_IN 1073741911
# define ZOOM_OUT 1073741910

typedef struct		s_vertex
{
	/*double*/int			x;
	/*double*/int			y;
}					t_vertex;


typedef struct		s_point
{
	float			x;
	float			y;
	float			z;
	int				color;
	SDL_Color		col;
}					t_point;

typedef struct		s_wall
{
	char			type;
	t_point			start;
	t_point			end;
	t_vertex		normal;
	int				height;
}					t_wall;
/*
typedef	struct		s_walls
{
	int				point1[2];
	int				point2[2];
	struct s_walls	*next;
}					t_walls;
*/
typedef struct		s_wlist
{
	int				id;
	t_wall			wall;
	struct s_wlist	*next;
	struct s_wlist	*prev;
}					t_wlist;

typedef struct		s_olist
{
	int				id;
	t_vertex		obj;
	struct s_olist	*next;
	struct s_olist	*prev;
}					t_olist;

typedef	struct		s_keys
{
	int				up;
	int				down;
	int				left;
	int				right;
	int				zoom_in;
	int				zoom_out;
}					t_keys;

typedef	struct		s_mouse
{
	int				posx;
	int				posy;
	int				click1[2];
	int				click2[2];
	int				click;
//	int				nwalls;
	int				nobj;
	int				loop;
	t_wall			walls;
	t_wall			prev;
}					t_mouse;

typedef	struct		s_color
{
	int				blue;
	int				green;
	int				red;
	int				alpha;
}					t_color;

typedef struct		s_map
{
	//t_point			**map;
	t_wlist 		*wlst;
	int				height;
	int				width;
	int				ox;
	int				oy;
	float			base_gap;
	float			base_h;
	char			proj;
	int				zmax;
	int				endx;
	int				endy;
}					t_map;

typedef struct		s_item
{
	SDL_Rect		rect;
	SDL_Surface		*surface;
	SDL_Texture		*texture;
}					t_item;

typedef struct		s_txt
{
	t_item			*menu;
	t_item			*item;
	//SDL_Surface		*txt_menu;
	//SDL_Surface		*txt_sub;
	TTF_Font		*font;
	//SDL_Texture		*txt_tex_menu;
	//SDL_Texture		*txt_tex_sub;
	//SDL_Rect		txt_rect_menu;
	//SDL_Rect		txt_rect_sub;
	SDL_Rect		txt_through;
	SDL_Color		color;
}					t_txt;

typedef struct		s_fdf
{
	SDL_Window		*window;
	SDL_Renderer	*renderer;
	SDL_Texture		*map_texture;
	SDL_Texture		*text_texture;
	char			*map_name;
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

/*
**			PARSING
*/
t_map				*ft_parser(int fd);
t_map				*ft_map_init(int fd);
t_wlist				*ft_list_alloc(int fd, int *height, int *width);
char				**ft_check_first_line(char *line);
//t_wlist				*ft_store_first_line(char **tab);
int					ft_value_is_a_number(char *number);
char				**ft_check_elements(char *line);
int					ft_store_elements(t_wlist **list, char **tab/*, int count*/);

/*
**			WALLS and W_LIST
*/
t_vertex			create_vertex(double x, double y);
t_point				create_point(float x, float y);
t_wall				create_emptywall(void);
t_wall 				create_wall(t_point start, t_point end, t_vertex normal);
void				ft_fix_coords(t_map *map, int *x, int *y);
void				ft_sub_fix_coords(t_map *map, int *x, int *y);
t_wlist 			*new_wlist(t_wall wall);
void				add_wlist(t_wlist **list, t_wlist *new);
void				ft_save_map(t_fdf *img, t_olist *olst);
void				click_to_wall(t_map *map, t_mouse *mous, SDL_Event e);
void				set_object(t_map *map, t_mouse *mous, SDL_Event e, t_olist **olst);

/*
**			CALCULATION HELPS
*/
void				ft_origin(t_map *map);
int					ft_gap(t_map *map);
float				ft_height(t_map *map);

/*
**			DRAWING
*/
void				ft_fdf(t_map *map, char *map_name);
t_fdf				*ft_ptr_init(char *name);
SDL_Color			ft_hexa_to_ratio(int color);
void				ft_clear_and_render(t_fdf *img);
void				ft_print_grid(t_fdf *img, t_map *map);
void				ft_print_walls(t_fdf *img, t_wlist *wlst);
void				ft_print_obj(t_fdf *img, t_olist *olst);
void				ft_print_buttons(t_fdf *img);
void				print_point_box(t_fdf *img, t_wlist *wlst);
//void				ft_infinite_loop(t_fdf *img, t_mouse mous);
void				ft_trace_line(t_point a, t_point b, t_fdf *img);

/*
**			EVENT
*/
void				ft_menu_event(t_map *map, t_mouse *mous, SDL_Event e);
void				ft_print_pressed_button(t_fdf *img, int i);
void				ft_keys_event(t_map *map, SDL_Event e, t_keys *key);
void				ft_mouse_event(t_map *map, t_mouse *mous, SDL_Event e/*, t_wlist **wlst*/, t_olist **olst);
void				ft_zoom(t_keys *key, t_map *map);
void				ft_move(t_keys *key, t_map *map);
int					ft_even_odd(int i);
void				loop_til_release();

/*
**			TEXT
*/
t_txt				*ft_txt_init(t_fdf *img);
void				ft_render_text(t_fdf *img);

/*
**			FREE_FUNCTIONS
*/
void				ft_free_map(t_map *map);
void				ft_free_line(t_line *list);
void				ft_free_fdf(t_fdf *fdf);

//void				ft_fill_image(t_fdf *img);
void				ft_light_up_pixel(t_bres *bres, t_fdf *img);
void				ft_get_controls(t_fdf *ptr);
int					ft_color(t_bres *bres, int color);
void				ft_modify_height(int key, t_fdf *ptr);
void				ft_iso_or_cart(int key, t_fdf *ptr);
void				ft_positive_or_negative(int key, t_fdf *ptr);
int					ft_color_positive(t_bres *bres);
int					ft_color_negative(t_bres *bres);
void				ft_cart_to_iso(t_map *map);
SDL_Color			ft_color_of_lower_element(t_point a, t_point b);
void				ft_attribute_color_to_points(t_map *map);
int					ft_height_to_color(int height);
//void				ft_fill_image_line(t_fdf *img, t_map *map, t_mouse *mous);
void				ft_clear_and_render_menu(t_fdf *img);
t_olist				*new_olist(t_vertex obj, int id);
void				add_olist(t_olist **list, t_olist *new);
#endif
