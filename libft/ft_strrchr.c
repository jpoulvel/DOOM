/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 20:06:50 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/12 20:05:53 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int n)
{
	int	i;

	i = (int)ft_strlen(str) - 1;
	if (n == '\0')
		return ((char *)str + i + 1);
	while (i >= 0 && str[i] != n)
		i--;
	if (str[i] == n)
		return ((char *)str + i);
	return (NULL);
}
