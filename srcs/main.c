/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:58:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/13 17:36:08 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

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
		fd = open(map_name, O_RDWR | O_NOFOLLOW /*| O_APPEND*/);
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
	if ((h = ft_atoi(height)) <= 0 || ((w = ft_atoi(width)) <= 0))
//	if (h >= 1000 || w >= 1000)
		return (ft_error("Dimensions should be greater than 0 and lesser than 100", 2));
	if ((fd = open(map_name, O_CREAT | O_NOFOLLOW | O_WRONLY/* | O_APPEND*/, 0666)) <= 0)
			return (ft_error("Unable to create file", 2));
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
			return (0);
	}
	else
		return (ft_error("usage for existing map: ./fdf existing_map\nusage for new map: ./fdf new_map height width", 2));
	if (!(map = ft_map_init(fd)))
		return (ft_error("Invalid map or map could not be created", 2));
	ft_fdf(map, argv[1]);
	return (0);
}
