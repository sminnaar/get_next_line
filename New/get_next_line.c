/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:17:34 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/28 11:47:48 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

	char	*readit(const int fd, char *str)
	{
		char	buf[BUFF_SIZE + 1];
		int		i2;

		if (fd < 0 || read(fd, buf, 0) < 0 || BUFF_SIZE < 1)
			return (0);
		str = (str == NULL) ? ft_strnew(1) : str;
		while (!(ft_strchr(str, '\n')))
		{
			if ((i2 = read(fd, buf, BUFF_SIZE)) < 0)
				return (0);
			buf[i2] = '\0';
			str = ft_strxjoin(str, buf, 1);
			if (str[0] == '\0' || i2 == 0)
				break ;
		}
		return (str);
	}

	int		get_next_line(const int fd, char **line)
	{
		static char *str;
		t_line		magic;

		if (!(str = readit(fd, str)) || !line)
			return (-1);
		if ((magic.temp = ft_strchr(str, '\n')) > 0)
		{
			magic.i = magic.temp - str;
			if (!(*line = ft_strndup(str, magic.i)))
				return (-1);
			str = ft_strdup(magic.temp + 1);
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
