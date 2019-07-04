/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:19:26 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/28 14:22:45 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*reader(const int fd, char *str)
{
	char	buffer[BUFF_SIZE];
	char	*tmp;
	int		readret;

	if (fd < 0 || read(fd, buffer, 0) < 0 || BUFF_SIZE < 1)
		return (0);
	str = (str == NULL) ? ft_strnew(1) : str;
	while (!(ft_strchr(str, '\n')))
	{
		if (!(readret = read(fd, buffer, BUFF_SIZE) < 0))
			return (0);
		buffer[readret] = '\0';
		tmp = (char *)malloc(sizeof(char) * ft_strlen(str));
		tmp = str;
		str = ft_strjoin(tmp, buffer);
		free(buffer);
		free(tmp);
		tmp = NULL;
		if (str[0] == '\0' || readret == 0)
			break ;
	}
	return (str);
}

int			get_next_line(const int fd, char **line)
{
	static char *str;
	t_line		store;

	if (!(str = reader(fd, str)) || !line)
		return (-1);
	if ((store.temp = ft_strchr(str, '\n')) > 0)
	{
		store.i = store.temp - str;
		if (!(*line = ft_strndup(str, store.i)))
			return (-1);
		str = ft_strdup(store.temp + 1);
		return (1);
	}
	else
	{
		if (!(*line = ft_strdup(str)))
			return (-1);
		free(str);
		str = NULL;
		if (*line[0] == '\0')
			return (0);
		return (1);
	}
}
