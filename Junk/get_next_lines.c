/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_lines.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 14:12:31 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/25 14:46:18 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	line_check(char **line, char **tmp)
{
	ft_putstr("IT WORKS!!!");
	char	*t_tmp;
	char	*chr_tmp;
	size_t	i;

	i = 0;
	chr_tmp = *tmp;
	while (chr_tmp[i] != '\n')
		if (!chr_tmp[i++])
			return (0);
	t_tmp = &chr_tmp[i];
	*t_tmp = '\0';
	ft_strcpy(*line, *tmp);
	ft_strcpy(*tmp, (t_tmp + 1));
	return (1);

	//if cht_tmp = ft_memset(ft_strchr(*tmp, '\n'), '\0', 1);
	
}

static int	reader(int fd, char *buffer, char **store, char **line)
{
	int		readret;
	char	*tmp_s;
	while ((readret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		buffer[readret] = '\0';
		if (*store)
		{
			tmp_s = *store;
			*store = ft_strjoin(tmp_s, buffer);
			free(tmp_s);
			tmp_s = NULL;
		}
		else
			*store = ft_strdup(buffer);
		if (line_check(line, store))
			break ;
	}
	return (RET_VAL(readret));
}

int	get_next_line(int const fd, char **line)
{
	static char	*store[FD_MAX];
	char		*buffer;
	int			readret;
	int			cnt;

	if (!line || (fd < 0 || fd >= FD_MAX) || (read(fd, store[fd], 0) > 0) || !(buffer = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1)))
	{
		free(buffer);
		return (-1);
	}
	if (store[fd])
		if (line_check(line, &store[fd]))
		{
			free(buffer);
			return (1);
		}
	cnt = 0;
	while (cnt < BUFF_SIZE)
		buffer[cnt++] = '\0';
	readret = reader(fd, buffer, &store[fd], line);
	free(buffer);
	if (readret != 0 || store[fd] == NULL || store[fd][0] == '\0')
	{
		if (!readret && *line)
			*line = NULL;
		return (readret);
	}
	*line = store[fd];
	free(store[fd]);
	store[fd] = NULL;
	return (1);
}
