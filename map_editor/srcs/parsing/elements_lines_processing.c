/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_lines_processing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:35:13 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/18 13:31:57 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../map_editor.h"

/*
** Checks that we only have digits in the lines. If not, returns 0.
*/

int				ft_value_is_a_number(char *number)
{
	int			i;

	if (number == NULL)
		return (0);
	i = -1;
	while (number[++i])
	{
		if (!(ft_isdigit(number[i]) || number[i] == '-'))
			return (0);
	}
	return (1);
}
/*
** Checks that we have only numbers. If not, sends 0.
*/

int				coordinates_are_correct(char **element)
{
	if (ft_value_is_a_number(element[1]) &&
			ft_value_is_a_number(element[2]) &&
			ft_value_is_a_number(element[3]) &&
			ft_value_is_a_number(element[4]) &&
			ft_value_is_a_number(element[5]) &&
			ft_value_is_a_number(element[6]) &&
			!element[7])
		return (1);
	return (0);
}

/*
** Split by spaces, and check that
** - the first element is a known type (w/o/...)
** - we have eight numbers, nothing more.
** If a value is incorrect, the line is incorrect and it will not be saved
*/

char			**ft_check_elements(char *line)
{
	char		**element;

	element = ft_strsplit(line, 32 );
	if (!ft_strcmp(element[0], "w") || !ft_strcmp(element[0], "o"))
	{
		if (coordinates_are_correct(element))
			return (element);
	}
	free_tab(element);
	return (NULL);
}

/*
** Store the values as points and vertex in a t_wall structure.
** Then adds the wall at the end of the t_wlist
*/

int				ft_store_elements(t_wlist **list, char **tab)
{
	t_wlist		*element;
	t_wall		wall;
	t_point		start;
	t_point		end;
	t_vertex	normal;

	start = create_point(ft_atoi(tab[1]), ft_atoi(tab[2]));
	end = create_point(ft_atoi(tab[3]), ft_atoi(tab[4]));
	normal = create_vertex(ft_atoi(tab[5]), ft_atoi(tab[6]));
	wall = create_wall(start, end, normal);
	wall.type = *tab[0];
	if (!(element = new_wlist(wall)))
		return (0);
	if (*list == NULL)
		*list = element;
	else
		add_wlist(list, element);
	free_tab(tab);
	return (1);
}
