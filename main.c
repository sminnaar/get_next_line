/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:38:26 by sminnaar          #+#    #+#             */
/*   Updated: 2019/07/01 17:32:24 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int argc,char **argv)
{
	int fd;
	//int fd1;
	char *line;
	int i;
	unsigned int cnt;

	cnt = 1;
	argc = 1;
	fd	= open(argv[1], O_RDONLY);
	//fd1 = open(argv[2], O_RDONLY);
	ft_putstr("File discriptor: ");
	ft_putnbr(fd);
	ft_putchar('\n');
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		ft_putnbr(i);
		ft_putstr("[");
		ft_putnbr(cnt);
		ft_putstr("] ");
		ft_putendl(line);
		i = get_next_line(fd, &line);
		cnt++;
		ft_putendl("------------------------------------------------");
	}
	ft_putnbr(i);
	ft_putstr("EOF");
	free(line);
	close(fd);
	return (0);
}
