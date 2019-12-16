/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 13:58:40 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/12/11 13:30:39 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

int		ft_check_file(char *file)
{
	int	fd;

	fd = 0;
//	if (ft_strcmp(&file[ft_strlen(file) - 4], ".fdf") == 0)
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
