/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 16:58:42 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/27 16:09:43 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	line_finder(int fd, char **file)
{
	char	buffer[BUFF_SIZE + 1];
	int		readret;
	char	*store;
	ft_putendl("Call to line_finder");

	if (!file[fd])
	{
		file[fd] = ft_strnew(0);
		ft_putendl("First if of line finder: create new str in file[fd]");
	}
	while (ft_strchr(file[fd], '\n') == NULL)
	{
		ft_putendl("First while of line_finder: if new line exists");
		if ((readret = read(fd, buffer, BUFF_SIZE)) == 0)
		{
			ft_putendl("First while of line_finder: If in While loop: Break");
			break ;
		}
		ft_putendl("Tail end of line_finder: No if's no but's no coconuts");
		if (readret < 0)
			return (-1);
		buffer[readret] = '\0';
		store = ft_strjoin(file[fd], buffer);
		ft_strdel(&file[fd]);
		file[fd] = ft_strdup(store);
		ft_strdel(&store);
	}
	ft_putendl("End of line_finder: return (0)");
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*file[1024];
	char		*head;
	char		*tail;
	ft_putendl("Call to get_next");


	if (!(line) || fd < 0 || line_finder(fd, file) < 0)
	{
		ft_putendl("First if of get_next: return (-1)");
		return (-1);
	}
	if (ft_strchr(file[fd], '\n') != NULL && *file[fd])
	{
		ft_putendl("Second if of get_next: set NULL");
		head = ft_strdup(file[fd]);
		ft_strdel(&file[fd]);
		tail = ft_memset(ft_strchr(head, '\n'), '\0', 1) + 1;
		*line = ft_strdup(head);
		file[fd] = ft_strdup(tail);
		ft_strdel(&head);
	}
	else if (ft_strlen(file[fd]) > 0)
	{
		ft_putendl("Else if of get_next: clear file[fd]");
		head = ft_strdup(file[fd]);
		*line = ft_strdup(file[fd]);
		ft_strdel(&file[fd]);
	}
	else
	{
		ft_putendl("Else of get_next: return (0)");
		return (0);
	}
	ft_putendl("get_next: return (1)");
	return (1);
}
