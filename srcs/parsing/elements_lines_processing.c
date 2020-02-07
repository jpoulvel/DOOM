/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements_lines_processing.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:35:13 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/07 15:06:09 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

/*
** ft_atoi sends 0 if NaN or if the value was 0.
** so if the value was 0, sends 1 to say OK, if not, sends 0 to say we hd NaN.
*/

int				ft_value_is_a_number(char *number)
{
	if (ft_atoi(number) == 0 && ft_strcmp(number, "0"))
		return (0);
	return (1);
}
/*
** Checks that we have only numbers (or numbers followd by letters, in which case the letter will nt be taken into account)
** If not, sends 0.
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
** Store the values as vertexes in a t_wall structure.
** Then adds the wall at the end of the t_wlist
*/

int				ft_store_elements(t_wlist **list, char **tab, int count)
{
	t_wlist		*element;
	t_wall		wall;
	t_vertex	start;
	t_vertex	end;
	t_vertex	normal;

	start = create_vertex(ft_atoi(tab[1]), ft_atoi(tab[2]));
	end = create_vertex(ft_atoi(tab[3]), ft_atoi(tab[4]));
	normal = create_vertex(ft_atoi(tab[5]), ft_atoi(tab[6]));
	wall = create_wall(start, end, normal);
	wall.type = *tab[0];//do I need to make a dup instead?
	if (!(element = new_wlist(wall, count)))
		return (0);
	add_wlist(list, element);
	free_tab(tab);
	return (1);
}
