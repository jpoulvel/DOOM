/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:58:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/12 18:47:59 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_infinite_loop(t_fdf *img, t_mouse mous)
{
	int			isquit;
	SDL_Event	event;
//	t_wlist 	*wlst;
	t_olist 	*olst;
	t_keys		key;

	mous.click = 0;
//	mous.nwalls = 0;
	mous.nobj = 0;
	key.up = 0;
	key.down = 0;
	key.left = 0;
	key.right = 0;
	key.zoom_in = 0;
	key.zoom_out = 0;
	isquit = 0;
//	wlst = NULL;
	olst = NULL;
	while (isquit == 0)
	{
		SDL_PollEvent(&event);
		while (event.type == SDL_MOUSEBUTTONDOWN || event.type == SDL_KEYDOWN)
		{
			printf("moving");
			if (event.type == SDL_QUIT)
				exit (0);
			ft_menu_event(img->map, &mous, event);
			ft_print_pressed_button(img, mous.loop);
			ft_clear_and_render(img/*, wlst, olst*/);
			ft_keys_event(img->map, event, &key);
			ft_mouse_event(img->map, &mous, event/*, &wlst*/, &olst);
			if (mous.loop == 2)
				ft_save_map(img, olst/*, mous.nwalls*/);
		}
	}
}

int		ft_open_existing_map(char *map_name)
{
	int	fd;

	fd = 0;
	if ((fd = open(map_name, O_DIRECTORY) > 0))
	{
		close(fd);
		fd = 0;
	}
	else
		fd = open(map_name, O_RDWR | O_NOFOLLOW | O_APPEND);
	/*	if (ft_check_first_line(fd) == 0)
			return (0);*/
	return (fd);
}

int		ft_create_map(char *map_name, char *height, char *width)
{
	int	fd;
	int	h;
	int	w;

	if ((fd = open(map_name, O_RDONLY | O_NOFOLLOW)) > 0)
		return (ft_error("Map already exists, remove the size parameters", 2));
	h = ft_atoi(height);
	w = ft_atoi(width);
	if (h >= 1000 || w >= 1000)
		return (ft_error("Map should not exceed 1000 in height or width", 2));
	fd = open(map_name, O_RDWR | O_CREAT | O_APPEND, 0666);
	ft_putstr_fd(height, fd);
	ft_putstr_fd(" ", fd);
	ft_putendl_fd(width, fd);
	ft_putendl("Map created successfully");
	return (fd);
}

int			main(int argc, char **argv)
{
	int		fd;
	t_map	*map;

	if (argc == 2)
	{
		if ((fd = ft_open_existing_map(argv[1])) <= 0)
			return (ft_error("Invalid file", 2));
	}
	else if (argc == 4)
	{
		if ((fd = ft_create_map(argv[1], argv[2], argv[3]) <= 0))
			return (ft_error("Unable to create file", 2));
	}
	else
		return (ft_error("usage for existing map: ./fdf existing_map\nusage for new map: ./fdf new_map height width", 2));
	if (!(map = ft_map_init(fd)))
		return (ft_error("Invalid map or map could not be created", 2));
	ft_fdf(map, argv[1]);
	return (0);
}
