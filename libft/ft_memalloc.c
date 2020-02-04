/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:22:24 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/04 14:52:35 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*dest;

	if (!(dest = ((void*)malloc(sizeof(void *) * size))))
		return (0);
	ft_bzero(dest, size);
	return (dest);
}
