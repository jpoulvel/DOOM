/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:58:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/29 17:53:56 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_infinite_loop(t_fdf *img, t_mouse mous)
{
	int			isquit;
	SDL_Event	event;
	t_wlist 	*wlst;
	t_olist 	*olst;
	t_keys		key;

	mous.click = 0;
	mous.nwalls = 0;
	mous.nobj = 0;
	key.up = 0;
	key.down = 0;
	key.left = 0;
	key.right = 0;
	key.zoom_in = 0;
	key.zoom_out = 0;
	isquit = 0;
	wlst = NULL;
	olst = NULL;
	while (isquit == 0)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				exit (0);
			ft_menu_event(img->map, &mous, event);
			ft_print_pressed_button(img, mous.loop);
			ft_clear_and_render_menu(img, wlst, olst);
			ft_keys_event(img->map, event, &key);
			ft_mouse_event(img->map, &mous, event, &wlst, &olst);
			if (mous.loop == 2)
				ft_save_map(&wlst, &olst);
		}
	}
}

void			ft_fdf(t_map *map)
{
	t_fdf		*img;
	t_mouse		mouse;

	if (!(img = ft_ptr_init(NAME)))
		return ;
	mouse.loop = 0;
	img->map = map;
	//ft_cart_to_iso(map);
	ft_fill_image(img);
	SDL_RenderPresent(img->renderer);
	bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));
	ft_infinite_loop(img, mouse);
}

int		ft_check_file(char *file)
{
	int	fd;

	fd = 0;
	if ((fd = open(file, O_DIRECTORY) > 0))
	{
		close(fd);
		fd = 0;
	}
	else
		fd = open(file, O_RDONLY | O_NOFOLLOW);
	return (fd);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc != 2)
		return (ft_error("usage: ./fdf map", 2));
	if ((fd = ft_check_file(argv[1])) <= 0)
		return (ft_error("Invalid file", 2));
	if (!(map = ft_parser(fd)))
	{
		map != NULL ? ft_free_map(map) : 0;
		return (ft_error("Invalid map", 2));
	}
	ft_fdf(map);
	return (0);
}
