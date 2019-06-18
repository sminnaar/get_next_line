/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:32:47 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/18 15:30:41 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{
	int ret;
	char buff[BUFF_SIZE + 1];

	fd = open("Test.txt", O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("open() error");
		return (1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) && (buf[ret] != '\n'))
	{
		ft_putnbr(ret);
		ft_putchar('\n');
		ft_putendl(buf);
		//free(buf);
	}
	//buf[ret] = '\0';
	//ft_putchar('\n');
	//ft_putnbr(ret);
	//ft_putchar('\n');
	//ft_putendl(buf);
	//ft_putnbr(BUFF_SIZE);
	//ft_putstr(get_next_line(
}
