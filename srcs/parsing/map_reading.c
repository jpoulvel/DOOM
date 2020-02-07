/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reading.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:32:10 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/07 14:55:31 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
** Will send the line to the first line (= map dimensions) checking or to the objects coordinates checking
*/

char			**ft_check_line(char *line, int count)
{
	int			valid;
	char		**tab;

	ft_putstr("count dans ft_check_line: ");//DEBUG
	ft_putnbr(count);
	ft_putstr("\n");
	if (count == 0)
		tab = ft_check_first_line(line);
	else
		if (!(tab = ft_check_elements(line)))
			return (NULL);
	return (tab);
}

/*
** Reads the map line by line.
** If the line has the good format (checked by ft_check_line), it will copy the coordinates in the linked list.
** If not, it will continue but trash the filthy wall.
*/

t_wlist			*ft_list_alloc(int fd)
{
	char		*linetmp;
	char		**split_line;
	t_wlist		*line_list;
	int			count;

	count = 0;
	linetmp = NULL;
	while (get_next_line(fd, &linetmp) > 0)
	{
		if ((split_line = ft_check_line(linetmp, count)) != NULL)
		{
			ft_print_tab(split_line);//DEBUG
			free(linetmp);
			if (line_list == NULL)
			{
				if (!(line_list = ft_store_first_line(split_line)))
					return (NULL);
			}
			else
			{
				if (!ft_store_elements(&line_list, split_line, count))
					ft_putendl("ft_store_elements = NULL");
//					free the entire list;
			}
		count++;
		}
		else
		{
			free(linetmp);
//			free the entire list;if we want that one error = no game at all. If we leave it like this, we just remove the wrong wall and keep the others.
		}
	}
	return (line_list);
}
