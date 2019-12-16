/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:20:56 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/17 12:21:59 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_countwords(char const *s, char c)
{
	int	i;
	int	j;
	int	words;

	i = 0;
	j = 0;
	words = 0;
	if (!s)
		return (0);
	while (s[i] && s[i + j])
	{
		while (s[i] && s[j] && s[i + j] == c)
			i++;
		if (s[i] && s[j] && s[i + j] != '\0')
			words++;
		while (s[i] && s[j] && s[i + j] != c && s[i + j] != '\0')
			j++;
	}
	return (words);
}
