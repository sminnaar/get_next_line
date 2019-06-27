/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 15:38:00 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/27 18:00:24 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(int fd, char *buffer)
{
	char	*store;
	char 	*tail;
	int		readret;

	while (readret = read(fd, buffer, BUFF_SIZE) > 0)
	{
		buffer[BUFF_SIZE] = '\0';
		store = ft_strdup(buffer);
		if (ft_strchar(store, '\n') != NULL)
		{
			tail = ft_memset(ft_strchr(store, '\n'), '\0', 1) + 1;
			free(buffer);
			*line = store;
			return (line);
		}
		store = ft_strjoin(tail, buffer);

	}
}

int	get_next_line(int const fd, char **line)
{
	char	buffer[BUFF_SIZE + 1];
	int		readret;

	line = reader(fd, buffer);




	if (readret == 0)
		return (0);
	if (readret == -1)
		return (-1);
	return (0);
}
