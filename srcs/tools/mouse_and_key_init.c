/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_and_key_init.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/18 12:45:00 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/18 12:48:17 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

void			ft_mouse_init(t_mouse *mous)
{
//	mous->posx = 0;apparently not used
//	mous->posy = 0;apparently not used
/*	mous->click1[0] = 5;
	mous->click1[1] = 5;
	mous->click2[0] = 5;
	mous->click2[1] = 5;*/
	mous->click = 0;
//	mous.nwalls = 0;
	mous->nobj = 0;
	mous->loop = 1;
}

void			ft_key_init(t_keys *key)
{
	key->up = 0;
	key->down = 0;
	key->left = 0;
	key->right = 0;
	key->zoom_in = 0;
	key->zoom_out = 0;
}
