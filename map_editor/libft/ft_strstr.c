/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:20:38 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/12 20:06:31 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	if (ft_strlen(haystack) < ft_strlen(needle))
		return (NULL);
	while (i <= ft_strlen(haystack))
	{
		while (haystack[i + j] && needle[j] && haystack[i + j] != needle[j])
			i++;
		while (haystack[i + j] && needle[j] && haystack[i + j] == needle[j])
			j++;
		if (needle[j] == '\0')
			return ((char *)haystack + i);
		i = i + 1;
		j = 0;
	}
	return (0);
}
