/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/02 10:47:00 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/02 12:46:43 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrev(char *s)
{
	int		i;
	int		j;
	char	*new;

	if (!s || !(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
		return (NULL);
	i = 0;
	j = (int)ft_strlen(s) - 1;
	while (s[i])
	{
		new[i] = s[j];
		i++;
		j--;
	}
	new[i] = '\0';
	return (new);
}
