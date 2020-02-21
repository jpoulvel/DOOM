/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 13:43:22 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/14 13:49:59 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*dest;

	dest = s;
	i = -1;
	while (++i < n)
		dest[i] = (unsigned char)c;
	return (s);
}
