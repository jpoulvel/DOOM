/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 17:44:21 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/12 20:04:38 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s1;
	char	*s2;

	s1 = (char *)haystack;
	s2 = (char *)needle;
	i = 0;
	j = 0;
	if (s2[0] == '\0')
		return (s1);
	while (i <= ft_strlen(s1) && (i + j) < len)
	{
		while (s1[i] && s2[j] && s1[i] != s2[j] && i < len)
			i++;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && (i + j) < len)
			j++;
		if (s2[j] == '\0')
			return (s1 + i);
		i = i + 1;
		j = 0;
	}
	return (NULL);
}
