/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 11:47:46 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/02 18:12:07 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	line_copy(const int fd, char **buf, char **line, int r)
{
	size_t	i;
	char	*temp;

	temp = buf[fd];
	i = 0;
	if ((ft_strchr(buf[fd], '\n')) == NULL && r == 0)
	{
		*line = ft_strdup(buf[fd]);
		return (0);
	}
	while (buf[fd][i] != '\n' && buf[fd][i])
		i++;
	if (ft_strlen(buf[fd]) > i + 1)
	{
		*line = ft_strndup(buf[fd], i);
		buf[fd] = ft_strdup(buf[fd] + (i + 1));
	}
	if (temp)
		ft_strdel(&temp);
	return (1);
}

static int	reader(const int fd, char **buf, char **line)
{
	int		r;
	char	*store;
	char	buffer[BUFF_SIZE + 1];

	if (!buf[fd])
		buf[fd] = ft_strnew(0);
	while (!(ft_strchr(buf[fd], '\n')) && (r = read(fd, buffer, BUFF_SIZE)) >= 0)
	{
		buffer[r] = '\0';
		store = ft_strjoin(buf[fd], buffer);
		ft_strdel(&buf[fd]);
		buf[fd] = store; 
		//ft_memdel((void**)&store);
	}
	if (r == 0)
	{
		*line = ft_strdup(buf[fd]);
		return (0);
	}
	if (r >= 0 && buf[fd])
		return (line_copy(fd, buf, line, r));
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*buf[FD_MAX];

	if (fd < 0 || fd > FD_MAX || read(fd, NULL, 0) < 0 || !line)
		return (-1);
	return (reader(fd, buf, line));
}
