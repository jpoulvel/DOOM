/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 13:35:42 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/03/08 13:52:13 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strend(const char *s1, const char *s2, size_t start)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1[0] == '\0' || s2[0] == '\0')
		return (0);
	while (i <= ft_strlen(s1) && (i + j) >= start)
	{
		while (s1[i] && s2[j] && s1[i] != s2[j] && i >= start)
			i++;
		while (s1[i + j] && s2[j] && s1[i + j] == s2[j] && (i + j) >= start)
			j++;
		if (s1[i + j] == '\0' && s2[j] == '\0')
			return (1);
		i = i + 1;
		j = 0;
	}
	return (0);
}
