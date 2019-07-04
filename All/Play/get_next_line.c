/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:32:47 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/25 10:33:03 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"

int	get_next_line(const int fd, char **line)
{

	char *buffer;
	int readret;
	char *find;
	char *tail;
	static char *tmp;
	size_t i;



	tail = ft_strnew(0);
	buffer = (char *)ft_memalloc(sizeof(char) * BUFF_SIZE + 1);

	while ((readret = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		tmp =  ft_strjoin(tail, buffer);
		find = ft_repnew(tmp, '\n', '\0');
		*line = find;
		tail = (tmp + (ft_strlen(find) + 1));
	
		printf("File Discriptor: %d\n\n", fd);
		printf("Read return: %d\n\n", readret);
		printf("Temp contents: %s\n\n", tmp);
		printf("Buffer: %s\n\n", buffer);
		printf("Find contents: %s\n\n", find);
		printf("Length of find: %zu\n\n", ft_strlen(find));
		printf("Content of line: %s\n\n", *line);
		printf("Tail: %s\n\n", tail);

		ft_putendl("------------------------------------------------");
		*buffer = '\0';
	}
	if (readret == 0)
	{
		free(buffer);
		printf("Last line: %s\n\n", *line);
		*line = ft_repnew(tail, '\n', '\0');
		printf("Last line: %s\n\n", *line);
		tail = (tmp + (ft_strlen(*line)));
		*line = ft_repnew(tail, '\n', '\0');
		printf("Last tail: %s\n\n", tail);
//		tmp =  ft_strjoin(tail, buffer);
	}
		/*i = ft_strlen(find);
		while (i != 0)
		{

			*line = tail;
			printf("Last line: %s\n\n", *line);
			tmp =  ft_strjoin(tail, buffer);
			find = ft_repnew(tmp, '\n', '\0');
		}
	}
*/
	return (0);
}
