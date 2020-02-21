/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numberlength.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/17 12:16:07 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/17 12:19:11 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_numberlength(int n)
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
