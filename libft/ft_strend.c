/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:19:33 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/03/08 18:20:03 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strend(const char *s1, const char *s2, size_t start)
{
	size_t	i;

	i = 0;
	if (!(s1 && s2))
		return (0);
	while (s1[start + i] != '\0' && s2[i] != '\0' && s1[start + i] == s2[i])
		i++;
	if (s1[start + i] == '\0' && s2[i] == '\0')
		return (1);
	return (0);
}
