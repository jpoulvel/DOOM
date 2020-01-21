/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 12:02:46 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/20 16:53:30 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

t_point			*ft_str_to_int(char *charline, int len)
{
	int			i;
	int			j;
	t_point		*intline;
	static int	y = 0;

	i = 0;
	j = 0;
	if (!(intline = malloc(sizeof(t_point) * (len))))
		return (NULL);
	while (i < len)
	{
		while (charline[j] != '\0')
		{
			while (charline[j] == ' ')
				j++;
			intline[i].z = ft_atoi(charline + j);
			intline[i].x = i;
			intline[i].y = y;
			i++;
			while (ft_isdigit(charline[j]) == 1 || charline[j] == '-')
				j++;
		}
		y++;
	}
	return (intline);
}

t_point			*ft_fill_map(char *charline, int *len)
{
	int			i;
	t_point		*line;

	i = 0;
	*len = 0;
	while (charline[i] != '\0')
	{
		if (ft_isdigit(charline[i]) == 1 || charline[i] == '-')
		{
			(*len)++;
			i++;
		}
		while (ft_isdigit(charline[i]) == 1)
			i++;
		while (charline[i] == ' ')
			i++;
	}
	line = ft_str_to_int(charline, *len);
	return (line);
}

t_map			*ft_map_copy(t_line *list)
{
	t_line		*tmp;
	t_map		*map;
	int			i;
	char		*conform_line;

	i = -1;
	if (!list || !(map = malloc(sizeof(t_map))))
		return (NULL);
	map->x = 0;
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	map->y = tmp->y + 1;
	if (!(map->map = malloc(sizeof(t_point *) * (map->y + 1))))
		return (NULL);
	tmp = list;
	while (++i < map->y)
	{
		conform_line = ft_conform_line(tmp->str);
		map->map[i] = ft_fill_map(conform_line, &tmp->x);
		map->x = tmp->x;
		tmp = tmp->next;
	}
	return (map);
}

int				ft_check_equal_length(t_line *line)
{
	int			tmp;

	while (line->next)
	{
		tmp = line->x;
		line = line->next;
		if (tmp != line->x)
			return (0);
	}
	return (1);
}

t_map			*ft_parser(int fd)
{
	t_line		*list;
	t_map		*map;

	list = ft_list_alloc(fd);
	map = ft_map_copy(list);
	ft_attribute_color_to_points(map);
	if (map == NULL || ft_check_equal_length(list) == 0)
	{
		map != NULL ? ft_free_map(map) : 0;
		list != NULL ? ft_free_line(list) : 0;
		return (NULL);
	}
	ft_free_line(list);
	map->base_gap = ft_gap(map);
	map->base_h = ft_height(map);
	ft_origin(map);
	map->endx = map->ox + ((map->x - 1) * map->base_gap);
	map->endy = map->oy + ((map->y - 1) * map->base_gap);
	return (map);
}
