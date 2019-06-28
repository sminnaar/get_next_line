/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/28 11:49:40 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/28 12:30:32 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft/includes/libft.h"

# define BUFF_SIZE 32

typedef struct	s_line
{
	char		*temp;
	int			i;
}				t_line;
int				get_next_line(const int fd, char **line);

#endif
