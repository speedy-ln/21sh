# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcowle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/10 14:07:55 by kcowle            #+#    #+#              #
#    Updated: 2016/07/18 10:55:44 by kcowle           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= 21sh

LIB= libft/libft.a

CC=clang -Wall -Werror -Wextra

SRC= new.c main.c extras.c func.c help.c echo.c

OBJ= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft/
	@$(CC) -o $(NAME) $(SRC) libft/libft.a

clean:
	@make clean -C libft/
	@rm $(OBJ)

fclean: clean
	@make fclean -C libft/
	@rm $(NAME)

re: fclean all
