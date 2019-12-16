/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:35:46 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/12 20:02:46 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*dest;

	if (!(s && f))
		return (NULL);
	i = -1;
	if (!(dest = malloc(sizeof(char) * ((int)ft_strlen(s) + 1))))
		return (NULL);
	while (++i < (int)ft_strlen(s))
		dest[i] = f(s[i]);
	dest[i] = '\0';
	return (dest);
}
