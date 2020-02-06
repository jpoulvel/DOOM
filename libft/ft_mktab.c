/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mktab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pchambon <pchambon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:22:16 by jpoulvel          #+#    #+#             */
/*   Updated: 2020/02/06 17:48:55 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_mktab(char const *s, char c)
{
	int		i;
	int		j;
	char	**tab;
	int		words;

	i = 0;
	j = 0;
	words = ft_countwords(s, c);
	if (!(tab = (char **)malloc(sizeof(char*) * (words + 1))))
		return (NULL);
	words = -1;
	while (s[i + j])
	{
		while (s[i + j] == c)
			i++;
		(s[i + j] != '\0') ? words++ : 0;
		while (s[i + j] != c && s[i + j] != '\0')
			j++;
		if (j != 0)
			tab[words] = ft_strsub(s, i, j);
		i = i + j;
		j = 0;
	}
	tab[words + 1] = NULL;
	return (tab);
}
