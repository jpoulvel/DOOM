/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:55:41 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/01/30 15:19:11 by aruiz-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!(dest = ((char*)malloc(sizeof(char) * (size + 1)))))
		return (0);
	while (i <= size)
		dest[i++] = '\0';
	return (dest);
}
