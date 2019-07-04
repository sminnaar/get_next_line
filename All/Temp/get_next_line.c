/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:58:42 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/28 10:29:03 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	line_finder(int fd, char **file)
{
	char	buffer[BUFF_SIZE + 1];
	int		readret;
	char	*store;

	if (!file[fd])
	{
		file[fd] = ft_strnew(0);
	}
	while (ft_strchr(file[fd], '\n') == NULL)
	{
		if ((readret = read(fd, buffer, BUFF_SIZE)) == 0)
		{
			break ;
		}
		if (readret < 0)
			return (-1);
		buffer[readret] = '\0';
		store = ft_strjoin(file[fd], buffer);
		ft_strdel(&file[fd]);
		file[fd] = ft_strdup(store);
		ft_strdel(&store);
	}
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*file[255];
	char		*head;
	char		*tail;

	if (!(line) || fd < 0 || line_finder(fd, file) < 0)
		return (-1);
	if (ft_strchr(file[fd], '\n') != NULL && *file[fd])
	{
		head = ft_strdup(file[fd]);
		ft_strdel(&file[fd]);
		tail = ft_memset(ft_strchr(head, '\n'), '\0', 1) + 1;
		*line = ft_strdup(head);
		file[fd] = ft_strdup(tail);
		ft_strdel(&head);
	}
	else if (ft_strlen(file[fd]) > 0)
	{
		head = ft_strdup(file[fd]);
		*line = ft_strdup(file[fd]);
		ft_strdel(&file[fd]);
	}
	else
		return (0);
	return (1);
}
