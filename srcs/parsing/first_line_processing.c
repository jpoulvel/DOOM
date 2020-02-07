/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:33:11 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/07 15:05:30 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
** The fisrt line must just contain the id = 0 and the dimensions of the map, ie HEIGHT and WIDTH. Here, we store HEIGHT in start.x and WIDTH in start.y So this is not a wall but I store it a a wall to be able tomake it the first eelement of the linked list.
*/

t_wlist			*ft_store_first_line(char **tab)
{
	t_wlist		*first_line;
	t_wall		fake_wall;

	fake_wall = create_emptywall();
	fake_wall.start.x = ft_atoi(tab[0]);
	fake_wall.start.y = ft_atoi(tab[1]);
	if ((first_line = new_wlist(fake_wall, 0)) != NULL)
	{
		first_line->next = NULL;
		first_line->prev = NULL;
	}
	free_tab(tab);
	return (first_line);
}

/*
** Will check that the first line is only two numbers which represent the map dimensions. If there is a letter, t will just not take it into account
*/

char			**ft_check_first_line(char *line)
{
	char		**tab;

	tab = ft_strsplit(line, 32);
	if (ft_atoi(tab[0]) && ft_atoi(tab[1]) && !tab[2])
	{
		ft_putendl("ok tab0 et tab1 isdigit");//DEBUG
		return (tab);
	}
	else
	{
		ft_putendl("tab0 et tab1 pas digit");//DEBUG
		free_tab(tab);
		ft_putendl("freetab OK");//DEBUG
		return (NULL);
	}
}

