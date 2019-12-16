/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 12:40:24 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/02 12:47:11 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabrev(char **tab)
{
	int		i;
	int		j;
	int		len;
	char	**new;

	if (!tab)
		return (NULL);
	j = 0;
	i = 0;
	while (tab[j][0])
		j++;
	len = j;
	if (!(new = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		if (!(new[i] = ft_strrev(tab[j - 1])))
			return (NULL);
		i++;
		j--;
	}
	new[i][0] = '\0';
	return (new);
}
