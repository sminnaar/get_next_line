/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:38:26 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/25 15:14:50 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int	main(int argc,char **argv)
{
	int fd;
	int fd1;
	char *line;
	int i;
	unsigned int cnt;

	cnt = 1;
	fd	= open(argv[1], O_RDONLY);
	fd1 = open(argv[2], O_RDONLY);
	ft_putstr("File discriptor: ");
	ft_putnbr(fd);
	ft_putchar('\n');
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		ft_putstr("[");
		ft_putnbr(cnt);
		ft_putstr("] ");
		ft_putendl(line);
		i = get_next_line(fd, &line);
		cnt++;
	}
	ft_putchar('\n');
	ft_putstr("File discriptor: ");
	ft_putnbr(fd1);
	ft_putchar('\n');
	i = get_next_line(fd1, &line);
	cnt = 1;
	while (i > 0)
	{
		ft_putstr("[");
		ft_putnbr(cnt);
		ft_putstr("] ");
		ft_putendl(line);
		i = get_next_line(fd1, &line);
		cnt++;
	}
	return (0);
}
	/*ft_putstr("[1]");
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putstr("[2]");
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putstr("[3]");
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putstr("[4]");
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putstr("[5]");
	ft_putendl(line);
	get_next_line(fd, &line);
	ft_putstr("[6]");
	ft_putendl(line);
	i = get_next_line(fd1, &line);
	ft_putstr("[1]");
	ft_putendl(line);
	get_next_line(fd1, &line);
	ft_putstr("[2]");
	ft_putendl(line);
	get_next_line(fd1, &line);
	ft_putstr("[3]");
	ft_putendl(line);
	get_next_line(fd1, &line);
	ft_putstr("[4]");
	ft_putendl(line);
}*/
