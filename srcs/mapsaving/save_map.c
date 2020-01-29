/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:09:34 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/29 18:08:01 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void	ft_save_map(t_wlist **wlst, t_olist **olst)
{
	FILE *file = NULL;
	char *data;

	file = fopen("DOOM-map", "w");

	if (file == NULL)
	{
		ft_putstr("Unable to create file.\n");
		exit(0);
	}
	data = "W9.8.10.15W8.7.20.21";
	fputs(data, file);
	fclose(file);
	ft_putstr("File created succesfully\n");
	exit(0);
}
