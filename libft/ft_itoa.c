/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:12:29 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/30 15:54:49 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_lennum(int n)
{
	int			len;
	long int	m;

	len = 1;
	m = n;
	if (n < 0)
	{
		len++;
		m = -(long int)n;
	}
	while ((m / 10) > 0)
	{
		len++;
		m = m / 10;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char		*dest;
	long int	m;
	int			i;
	int			len;

	len = ft_lennum(n);
	i = len - 1;
	if (!(dest = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (n >= 0)
		m = n;
	if (n < 0)
		m = -(long int)n;
	while (i >= 0)
	{
		dest[i] = (m % 10) + '0';
		m = m / 10;
		i--;
	}
	if (n < 0)
		dest[0] = '-';
	dest[len] = '\0';
	return (dest);
}
