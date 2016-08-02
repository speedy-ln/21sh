# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kcowle <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/10 14:10:25 by kcowle            #+#    #+#              #
#    Updated: 2016/08/02 15:45:18 by lnkadime         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRC =  	ft_c2da.c			\
	    ft_strccut.c		\
		ft_strbcut.c		\
		ft_putnbr_base.c	\
		ft_strnshift.c		\
		ft_getfo.c			\
		ft_itoa_base.c		\
		ft_strrw.c			\
	  ft_strfcut.c			\
	 ft_memset.c			\
	  ft_itoa.c				\
	  ft_bzero.c			\
	  ft_memcpy.c			\
	  ft_memccpy.c			\
	  ft_memmove.c			\
	  ft_memchr.c			\
	  ft_memcmp.c			\
	  ft_strlen.c			\
	  ft_strdup.c			\
	  ft_strcpy.c			\
	  ft_strncpy.c			\
	  ft_strcat.c			\
	  ft_strncat.c			\
	  ft_strlcat.c			\
	  ft_strchr.c			\
	  ft_strstr.c			\
	  ft_strrchr.c			\
	  ft_strnstr.c			\
	  ft_strcmp.c			\
	  ft_strncmp.c			\
	  ft_atoi.c				\
	  ft_isalpha.c			\
	  ft_isdigit.c			\
	  ft_isascii.c			\
	  ft_isalnum.c			\
	  ft_isprint.c			\
	  ft_toupper.c			\
	  ft_tolower.c			\
	  ft_putchar.c			\
	  ft_putchar_fd.c		\
	  ft_putstr.c			\
	  ft_putstr_fd.c		\
	  ft_putendl.c			\
	  ft_putendl_fd.c		\
	  ft_strequ.c			\
	  ft_strnequ.c			\
	  ft_strclr.c			\
	  ft_memalloc.c			\
	  ft_memdel.c			\
	  ft_strnew.c			\
	  ft_strdel.c			\
	  ft_strtrim.c			\
	  ft_strsub.c			\
	  ft_striter.c			\
	  ft_striteri.c			\
	  ft_strmap.c			\
	  ft_strmapi.c			\
	  ft_putnbr.c			\
	  ft_putnbr_fd.c		\
	  ft_strjoin.c			\
	  ft_strsplit.c			\
	  ft_iswhitespace.c		\
	  ft_abs.c				\
	  ft_lstadd.c			\
	  ft_lstnew.c			\
	  ft_strmerge.c			\
	  get_next_line.c		\
	  ft_findstr.c

SRCO = ft_c2da.o			\
	   ft_findstr.o			\
	   ft_strccut.o			\
	   ft_strbcut.o			\
	   ft_strnshift.o		\
	   ft_itoa_base.o		\
	   ft_getfo.o			\
	   ft_strrw.o            \
	   ft_strfcut.o          \
	   ft_memset.o			\
	   ft_itoa.o			\
	   ft_bzero.o			\
	   ft_memcpy.o			\
	   ft_memccpy.o			\
	   ft_memmove.o			\
	   ft_memchr.o			\
	   ft_memcmp.o			\
	   ft_strlen.o			\
	   ft_strdup.o			\
	ft_putnbr_base.o			\
	   ft_strcpy.o			\
	   ft_strncpy.o			\
	   ft_strcat.o			\
	   ft_strncat.o			\
	   ft_strlcat.o			\
	   ft_strchr.o			\
	   ft_strstr.o			\
	   ft_strrchr.o			\
	   ft_strnstr.o			\
	   ft_strcmp.o			\
	   ft_strncmp.o			\
	   ft_atoi.o			\
	   ft_isalpha.o			\
	   ft_isdigit.o			\
	   ft_isascii.o			\
	   ft_isalnum.o			\
	   ft_isprint.o			\
	   ft_toupper.o			\
	   ft_tolower.o			\
	   ft_putchar.o			\
	   ft_putchar_fd.o		\
	   ft_putstr.o			\
	   ft_putstr_fd.o		\
	   ft_putendl.o			\
	   ft_putendl_fd.o		\
	   ft_strequ.o			\
	   ft_strnequ.o			\
	   ft_strclr.o			\
	   ft_memalloc.o		\
	   ft_memdel.o			\
	   ft_strnew.o			\
	   ft_strdel.o			\
	   ft_strtrim.o			\
	   ft_strsub.o			\
	   ft_striter.o			\
	   ft_striteri.o		\
	   ft_strmap.o			\
	   ft_strmapi.o			\
	   ft_putnbr.o			\
	   ft_putnbr_fd.o		\
	   ft_strjoin.o			\
	   ft_strsplit.o		\
	   ft_iswhitespace.o	\
	   ft_abs.o				\
	   ft_lstadd.o			\
	   ft_lstnew.o			\
	   ft_strmerge.o		\
	   get_next_line.o		\

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc -c $(CFLAGS) $(SRC)
	ar ruv $(NAME) $(SRCO)
	ranlib $(NAME)
clean:
	rm -f $(SRCO)

fclean: clean
	rm -f $(NAME)

re: fclean all
