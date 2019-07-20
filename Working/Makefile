# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/19 15:17:25 by sminnaar          #+#    #+#              #
#    Updated: 2019/07/09 14:13:04 by sminnaar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = get_next_line.a


SRC = get_next_line.c

all: $(NAME)

$(NAME): 
	@make -C libft/ fclean && make -C libft/
	@gcc $(FLAG) main.c get_next_line.c libft/libft.a

clean:
	@rm -f a.out
	@make -C libft/ clean
fclean: clean
	@make -C libft/ fclean
re: fclean all

.PHONY: all, clean, fclean, re, del, c
