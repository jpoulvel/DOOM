/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:09:34 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/02/03 16:17:04 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

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
}

int			write_coords(t_wlist *wlst, int fd)
{
	ft_putstr_fd("w:", fd);
	ft_putstr_fd(ft_itoa(wlst->wall.start.x), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_itoa(wlst->wall.start.y), fd);
	ft_putstr_fd(";", fd);
	ft_putstr_fd(ft_itoa(wlst->wall.end.x), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_itoa(wlst->wall.end.y), fd);
	ft_putstr_fd(";", fd);
	ft_putstr_fd(ft_itoa(wlst->wall.normal.x), fd);
	ft_putstr_fd(",", fd);
	ft_putstr_fd(ft_itoa(wlst->wall.normal.y), fd);
	ft_putendl_fd(";", fd);
	return (1);
}

void		ft_save_map(t_wlist *wlst, t_olist *olst, int nwalls)
{
	int		fd;

	if ((fd = open("saved_map", O_RDWR /*| O_CREAT*/ | O_APPEND, 0666)) <= 0)
		ft_error("Unable to write in the map file", 1);
	if (wlst != NULL)
	{
		while (wlst)
		{
			write_coords(wlst, fd);
			wlst = wlst->next;
		}
	}
	ft_putstr("Map updated succesfully\n");
	exit(0);
}
