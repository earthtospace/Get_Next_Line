/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwidaha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 12:30:16 by nwidaha           #+#    #+#             */
/*   Updated: 2019/02/15 17:44:37 by nwidaha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	int		endline(char *buffer)
{
	int	count;

	count = 0;
	while (buffer[count] != ENDL && buffer[count])
		count++;
	if (buffer[count] == ENDL)
	{
		buffer[count] = END;
		return (count);
	}
	else
		return (-1);
}

static	char	*conjoin(char *buffer, char *tab)
{
	size_t	i;
	size_t	j;
	char	*pointer;

	i = 0;
	j = 0;
	if (buffer)
		i = ft_strlen(buffer);
	if (tab)
		j = ft_strlen(tab);
	pointer = (char *)malloc(sizeof(*pointer) * (i + j + 1));
	ft_memcpy(pointer, buffer, i);
	ft_memcpy(pointer + i, tab, j);
	pointer[i + j] = '\0';
	free(buffer);
	ft_bzero(tab, BUFF_SIZE + 1);
	return (pointer);
}

static	int		check(char **buffer, char **tab, char **line)
{
	char	*ptr;
	int		final;

	*buffer = conjoin(*buffer, *tab);
	final = endline(*buffer);
	if (final > -1)
	{
		*line = ft_strdup(*buffer);
		ptr = *buffer;
		*buffer = ft_strdup(*buffer + final + 1);
		free(ptr);
		return (1);
	}
	return (0);
}

int				get_next_line(const int fd, char **line)
{
	static char	*buff[BUFF_SIZE + 1];
	char		*tmp;
	int			result;
	int			ret;

	tmp = ft_strnew(BUFF_SIZE);
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, tmp, 0)) < 0)
		return (-1);
	while ((ret = read(fd, tmp, BUFF_SIZE)) > 0)
	{
		result = check(&buff[fd], &tmp, line);
		free(tmp);
		if (result == 1)
			return (1);
		tmp = ft_strnew(BUFF_SIZE);
	}
	if ((result = check(&buff[fd], &tmp, line)))
		return (1);
	else if (ft_strlen(buff[fd]) > 0)
	{
		*line = ft_strdup(buff[fd]);
		ft_strdel(&buff[fd]);
		return (1);
	}
	return (result);
}
