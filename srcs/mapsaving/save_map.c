/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:09:34 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/18 13:16:33 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*THE TWO FUNCTIONS BELOW ARE NOT USED ANYMORE
int			digit_num(int a)
{
	int		i;

	i = 1;
	while (a >= 10)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int			count_digits(t_wlist *wlst)
{
	int		n;

	n = 0;
	if (wlst != NULL)
	{
		while (wlst)
		{
			n += digit_num(wlst->wall.start.x);
			n += digit_num(wlst->wall.start.y);
			n += digit_num(wlst->wall.end.x);
			n += digit_num(wlst->wall.end.x);
			n += digit_num(wlst->wall.normal.y);
			n += digit_num(wlst->wall.normal.y);
			wlst = wlst->next;
		}
	}
	return (n);
}*/
/*FOR DEBUGGING PURPOSE ONLY
int			wwrite_coords(t_wlist *wlst, int fd)
{
	ft_putendl("Ok entree write_coords");
	ft_putchar(wlst->wall.type);
	ft_putchar(' ');
	ft_putnbr(wlst->wall.start.x);
	ft_putstr(" ");
	ft_putnbr(wlst->wall.start.y);
	ft_putstr(" ");
	ft_putnbr(wlst->wall.end.x);
	ft_putstr(" ");
	ft_putnbr(wlst->wall.end.y);
	ft_putstr(" ");
	ft_putnbr(wlst->wall.normal.x);
	ft_putstr(" ");
	ft_putnbr(wlst->wall.normal.y);
	ft_putstr(" ");
	return (1);
}*/

int			write_coords(t_wlist *wlst, int fd)
{
	ft_putchar_fd(wlst->wall.type, fd);
	ft_putchar_fd(' ', fd);
	ft_putnbr_fd(wlst->wall.start.x, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(wlst->wall.start.y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(wlst->wall.end.x, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(wlst->wall.end.y, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(wlst->wall.normal.x, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(wlst->wall.normal.y, fd);
	ft_putchar_fd('\n', fd);
	return (1);
}

int			write_size(t_map *map, int fd)
{
	ft_putnbr_fd(map->height, fd);
	ft_putstr_fd(" ", fd);
	ft_putnbr_fd(map->width, fd);
	ft_putendl_fd("", fd);
	return (1);
}

void		ft_save_map(t_fdf *img,  t_olist *olst)
{
	int		fd;
	t_wlist	*list;

	list = img->map->wlst;
	ft_putendl("Ok entree ft_save_map");
	if ((fd = open(img->map_name, O_RDWR /*| O_CREAT*/ | O_TRUNC, 0666)) <= 0)
		ft_error("Unable to write in the map file", 1);
	write_size(img->map, fd);
	if (list != NULL)
	{
		while (list)
		{
			write_coords(list, fd);
			list = list->next;
		}
	ft_putstr("Map updated succesfully\n");
	}
	exit(0);
}
