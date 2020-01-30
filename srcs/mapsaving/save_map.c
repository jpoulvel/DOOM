/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aruiz-ba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 17:09:34 by aruiz-ba          #+#    #+#             */
/*   Updated: 2020/01/30 15:59:43 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	digit_num(int	a)
{
	int i;

	i = 1;
	while (a >= 10)
	{
		a /= 10;
		i++;
	}
	return (i);
}

int	count_digits(t_wlist *wlst)
{
	int	n;

	n = 0;
	if(wlst != NULL)
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
	return(n);
}

//char	*write_coords(t_wlist *wlst, char **data) { } 


void	ft_save_map(t_wlist *wlst, t_olist *olst, int nwalls)
{
	FILE *file = NULL;
	char *data;
	int data_size;
	t_wlist *tm;

	file = fopen("DOOM-map", "w");

	if (file == NULL)
	{
		ft_putstr("Unable to create file.\n");
		exit(0); 
	} 
//	data = ft_strnew(nwalls); 
	data_size = count_digits(wlst); 
	printf("data_size: %i\n", data_size);
	//w1x.1y.2x.2y.2x.2y.3x.3y.3x.3y
	//9 digitos extras por wall
/*	if(wlst != NULL)
	{
		while (wlst)
		{
			//write_coords(wlst, &data);
			wlst = wlst->next;
		}
	}
	fputs(data, file);*/
	fclose(file);
	ft_putstr("File created succesfully\n");
	exit(0);
}

