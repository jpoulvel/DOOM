/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_wlist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmoucach <jmoucach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/02 13:51:48 by jmoucach          #+#    #+#             */
/*   Updated: 2020/02/13 16:10:48 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

t_wlist		*new_wlist(t_wall wall)
{
	t_wlist	*new;

	if (!(new = (t_wlist*)malloc(sizeof(t_wlist))))
		return (NULL);
	new->wall = wall;
	new->id = 1;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		add_wlist(t_wlist **list, t_wlist *new)
{
	t_wlist	*tmp;

	if (!new || !*list)
		return ;
	tmp = *list;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
	new->next = NULL;
	new->id = new->prev->id + 1;
	ft_putstr("cree le wlist id : ");//DEBUG
	ft_putnbr(new->id);//DEBUG
	ft_putstr("\n");//DEBUG
}

t_olist		*new_olist(t_vertex obj, int id)
{
	t_olist	*new;

	if (!(new = (t_olist*)malloc(sizeof(t_olist))))
		return (NULL);
	//new->id = id;
	new->obj = obj;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void		add_olist(t_olist **list, t_olist *new)
{
	new->next = *list;
	if (*list)
		(*list)->prev = new;
	(*list) = new;
}
