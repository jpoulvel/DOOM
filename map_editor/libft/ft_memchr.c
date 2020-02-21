/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:26:53 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/13 10:45:34 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (n == 0)
		return (NULL);
	while (((unsigned char*)s)[i] != (unsigned char)c && i < (n - 1))
		i++;
	if (((unsigned char*)s)[i] == (unsigned char)c)
		return ((unsigned char*)s + i);
	return (0);
}
