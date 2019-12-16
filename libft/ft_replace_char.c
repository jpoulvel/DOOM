/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/31 16:48:58 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/01/02 10:06:54 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_replace_char(char *s, char c, char n)
{
	int	i;
	int	replace;

	i = 0;
	replace = 0;
	while (s[i])
	{
		if (s[i] == c)
		{
			s[i] = n;
			replace++;
		}
		i++;
	}
	return (replace);
}
