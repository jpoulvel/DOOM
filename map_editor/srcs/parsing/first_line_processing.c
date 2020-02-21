/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_line_processing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:33:11 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/18 13:32:08 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

/*
** The fisrt line must just contain the id = 0 and the dimensions of the map, ie HEIGHT and WIDTH. Here, we store HEIGHT in start.x and WIDTH in start.y So this is not a wall but I store it a a wall to be able tomake it the first eelement of the linked list.
*/

t_wlist			*ft_store_first_line(char **tab)
{
	t_wlist		*first_line;
	t_wall		fake_wall;

	fake_wall = create_emptywall();
	fake_wall.type = 'w';
	fake_wall.start.x = ft_atoi(tab[0]);
	fake_wall.start.y = ft_atoi(tab[1]);
	if ((first_line = new_wlist(fake_wall)) != NULL)
	{
		first_line->next = NULL;
		first_line->prev = NULL;
	}
	free_tab(tab);
	return (first_line);
}

/*
** Will check that the first line is only two numbers which represent the map dimensions. 
If there is a letter or other char, t will just not take it into account
*/

char			**ft_check_first_line(char *line)
{
	char		**tab;

	tab = ft_strsplit(line, 32);
	if (ft_value_is_a_number(tab[0]) && ft_value_is_a_number(tab[1]) && !tab[2])
		return (tab);
	else
	{
		free_tab(tab);
		return (NULL);
	}
}

