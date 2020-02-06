/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_mgmt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:37:15 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/06 17:53:16 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

char			**ft_check_elements(char *line)
{
	char		**element;

	element = ft_strsplit(line, 32 );
	if (!ft_strcmp(element[0], "w") || ft_strcmp(element[0], "o") /*|| element[0] == "w" ||
			element[0] == "w" || element[0] == "w" || element[0] == "w"*/)
	{
		if (ft_isdigit((int)element[1]) && ft_isdigit((int)element[2]) &&
			ft_isdigit((int)element[3]) && ft_isdigit((int)element[4]) &&
			ft_isdigit((int)element[5]) && ft_isdigit((int)element[6]) &&
			!element[7])
				return (element);
	}
	free_tab(element);
	return (NULL);
}

char			**ft_check_first_line(char *line)
{
	char		**tab;

	tab = ft_strsplit(line, 32);
	ft_print_tab(tab);//DEBUG
	if (ft_isdigit(ft_atoi(tab[0])) && ft_isdigit(ft_atoi(tab[1])) && !tab[2])
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

char			**ft_check_line(char *line, int count)
{
	//static int	first_line = 1;
	int			valid;
	char		**tab;

	if (count == 0)
		tab = ft_check_first_line(line);
	else
		tab = ft_check_elements(line);
	return (tab);
}

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

t_wlist			*ft_list_alloc(int fd)
{
	//t_wall		element;
	char		*linetmp;
	char		**split_line;
	t_wlist		*line_list;
	int			count;
	//t_wlist		*tmp;
	//t_wlist		*new;

	count = 0;
	linetmp = NULL;
	while (get_next_line(fd, &linetmp) > 0)
	{
		if ((split_line = ft_check_line(linetmp, count)) != NULL)
		{
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
		}
		else
		{
			free(linetmp);
//			free the entire list;
		}
		count++;
	}
	return (line_list);
}
