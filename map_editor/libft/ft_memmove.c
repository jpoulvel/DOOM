/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 17:32:05 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/04 15:17:43 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	if (dst < src)
	{
		i = -1;
		while (++i < len)
			((char *)dst)[i] = ((char *)src)[i];
	}
	else
	{
		i = len;
		while ((int)--i >= 0)
			((char *)dst)[i] = ((char *)src)[i];
	}
	return (dst);
}
