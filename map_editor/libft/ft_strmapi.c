/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 19:05:56 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/12 20:03:49 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*dest;

	if (!(s && f))
		return (0);
	i = -1;
	if (!(dest = malloc(sizeof(char) * ((int)ft_strlen(s) + 1))))
		return (NULL);
	while (++i < (int)ft_strlen(s))
		dest[i] = f(i, s[i]);
	dest[i] = '\0';
	return (dest);
}
