/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 14:13:02 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/29 12:48:29 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_freejoin(char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strjoin(s1, s2);
	free(s1);
	return (tmp);
}

static int	reader(char **store, const int fd, char **line)
{
	char	buf[BUFF_SIZE];
	char 	*mem;
	char 	*tail;
	int		rret;

	if (!line || fd < 0 || BUFF_SIZE < 1 || (read(fd, buf, 0) < 0))
		return (-1);
	while(!(ft_strchr(*store, '\n')) && (rret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[rret] = '\0';
		*store = ft_freejoin(*store, buf);
	}
	if ((mem = ft_strchr(*store, '\n')) != NULL)
	{
		ft_memset(mem, '\0', 1);
		*line = ft_strdup(*store);
		tail = *store;
		*store = ft_strdup(mem + 1);
		free(tail);
	}
	else
	{
		*line = *store;
		*store = ft_strnew(1);
		return (0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char *store[1024];
	int			ret;

	if (store[fd] == NULL)
		store[fd] = ft_strnew(0);
	if ((ret = reader(&store[fd], fd, line)) < 0)
			return (-1);
	if (ret < BUFF_SIZE && (!(ft_strlen(store[fd]))))
			return (0);
	return (1);
}
