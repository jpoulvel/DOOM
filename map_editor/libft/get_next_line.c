/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpoulvel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 12:08:33 by jpoulvel          #+#    #+#             */
/*   Updated: 2019/03/08 14:26:27 by jpoulvel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

char			*ft_strjoin_free(char *s1, char *s2)
{
	int			i;
	char		*dest;

	if ((!s1 && !s2) || !(dest = (char *)malloc(sizeof(char) *
					((ft_strlen(s1) + ft_strlen(s2)) + 1))))
		return (NULL);
	i = -1;
	ft_strcpy(dest, s1);
	ft_strcpy(dest + ft_strlen(s1), s2);
	ft_strdel(&s1);
	return (dest);
}

int				fill_line(char **line, char **stock)
{
	int			i;
	char		*to_free;

	i = -1;
	if (ft_strlen(*stock) == 0)
		return (0);
	if (ft_strchr(*stock, '\n') == NULL)
	{
		if (!(*line = ft_strdup(*stock)))
			return (-1);
		*stock ? ft_strdel(stock) : 1;
		return (1);
	}
	if (!(to_free = ft_strdup(ft_strchr(*stock, '\n'))))
		return (-1);
	if (!(*line = ft_strsub(*stock, 0, (ft_strchr(*stock, '\n') - *stock))))
		return (-1);
	ft_strdel(stock);
	if (ft_strlen(to_free) > 1)
	{
		if (!(*stock = ft_strdup(to_free + 1)))
			return (-1);
	}
	ft_strlen(to_free) > 0 ? ft_strdel(&to_free) : 1;
	return (1);
}

int				get_next_line(int fd, char **line)
{
	static char	*stock[OPEN_MAX + 1];
	int			ret;
	char		buf[BUFF_SIZE + 1];
	int			line_sent;

	if (fd < 0 || fd > OPEN_MAX || !line || BUFF_SIZE <= 0)
		return (-1);
	if (stock[fd] == NULL && !(stock[fd] = ft_strnew(0)))
		return (-1);
	while (ft_strchr(stock[fd], '\n') == NULL &&
			(ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!(stock[fd] = ft_strjoin_free(stock[fd], buf)))
			return (-1);
	}
	if (ret < 0)
		return (-1);
	line_sent = fill_line(line, &stock[fd]);
	if (line_sent == 0 && ret == 0)
		return (0);
	return (line_sent);
}
