/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 11:38:26 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/14 13:17:09 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft/libft.h"

int	get_next(const int fd, char **line);

int	main(argc, **argv)
{
	int fd;
	int fd1;
	char *line;
	int i;

	fd	= read("Test.txt", buff, BUFF_SIZE);
	fd1 = read("Test1.txt", buff, BUFF_SIZE);
	i = get_next(fd, &line);
	ft_putendl(*line);
	i = get_next(fd1, &line);
	ft_putendl(*line);
}
