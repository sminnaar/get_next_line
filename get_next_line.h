/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:32:59 by sminnaar          #+#    #+#             */
/*   Updated: 2019/06/25 14:51:33 by sminnaar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 320 
# define FD_MAX 255
# define RET_VAL(readret) readret > 0 ? 1 : readret

# include "libft/libft.h"
# include <unistd.h>
# include <fcntl.h>

int	get_next_line(const int fd, char **line);

#endif
