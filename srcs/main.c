/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:58:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/20 16:09:44 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

void			ft_infinite_loop(t_fdf *img, t_mouse mous)
{
	int			isquit;
	SDL_Event	event;

	mous.click = 1;
	mous.nwalls = 1;
	isquit = 0;
	while (isquit == 0)
	{
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
				exit (0);
			ft_keys_event(img->map, &mous, event);
			ft_mouse_event(img->map, &mous, event);
				//isquit = 1;
		}
		ft_print_lines(img, img->map);
		if (ft_even_odd(mous.click) == 0)
			ft_fill_image_line(img, img->map, &mous);
		SDL_RenderPresent(img->renderer);
		bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));
		SDL_SetRenderDrawColor(img->renderer, 0, 0, 0, 0);
		SDL_RenderClear(img->renderer);
	}
}

void			ft_fdf(t_map *map)
{
	t_fdf		*img;
	t_mouse		mouse;

	if (!(img = ft_ptr_init(NAME)))
		return ;
	img->map = map;
	//ft_cart_to_iso(map);
	ft_fill_image(img);
	//SDL_UpdateTexture(img->texture, NULL, img->pixels, WIDTH * 4);
	SDL_RenderCopy(img->renderer, img->texture, NULL, NULL);
	SDL_RenderPresent(img->renderer);
	bzero(img->pixels, WIDTH * HEIGHT * sizeof(Uint8));
	ft_infinite_loop(img, mouse);
//	SDL_Delay(500);
//	mlx_put_image_to_window(img->mlx_ptr, img->win_ptr, img->img_ptr, 0, 0);
//	ft_print_menu(img->mlx_ptr, img->win_ptr);
//	ft_get_controls(img);
//	mlx_loop(img->mlx_ptr);
}

int		ft_check_file(char *file)
{
	int	fd;

	fd = 0;
//	if (ft_strcmp(&file[ft_strlen(file) - 4], ".fdf") == 0) // no need to chareck that file is in ".fdf"
//	{
		if ((fd = open(file, O_DIRECTORY) > 0))
		{
			close(fd);
			fd = 0;
		}
		else
			fd = open(file, O_RDONLY | O_NOFOLLOW);
//	}
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
