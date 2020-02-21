/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 16:34:28 by jpoulvel          #+#    #+#             */
/*   Updated: 2018/12/13 17:16:42 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countchar(char const *s)
{
	int		i;
	int		j;
	int		len;

	len = (int)ft_strlen(s);
	j = len - 1;
	i = 0;
	while (i < len && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i++;
	if (i == len)
		return (0);
	while (j > 0 && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j--;
	len = j - i + 1;
	return (len);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		len;
	char	*dest;

	if (!s)
		return (NULL);
	len = ft_countchar(s);
	if (!(dest = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0' && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	while (s[i + j] != '\0' && j < len)
	{
		dest[j] = s[i + j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
