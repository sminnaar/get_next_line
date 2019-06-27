# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sminnaar <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/19 15:17:25 by sminnaar          #+#    #+#              #
#    Updated: 2019/06/27 15:11:39 by sminnaar         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAG = -Wall -Wextra -Werror

NAME = libft.a

#INC_DIR = ./includes

OBJ_DIR = objs/

SRC = get_next_lines.c \

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ)
	@echo "Object files created"
	@ar rc $(NAME) $(OBJ)
	@echo "$(NAME) Compiled"
	@ranlib $(NAME)
	@echo "$(NAME) Indexed"

$(OBJ_DIR) :
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(dir $(OBJ))

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@gcc $(FLAG) -c $< -o $@ -I. 

clean:
	@rm -f $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(OBJ) Cleaned"

fclean: clean
	@rm -f $(NAME)
	@echo "$(NAME) Cleaned"

re: fclean all

del: fclean
	@rm -f libft.h.gch
	@rm -f *.out

c:
	@gcc $(FLAG) main.c get_next_line.c -L./libft/ -lft -I. 

.PHONY: all, clean, fclean, re, del, c

