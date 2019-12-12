# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 23:35:56 by dthan             #+#    #+#              #
#    Updated: 2019/12/05 23:44:11 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_DIR = srcs

LIBFT_DIR = libft

SRCS_CODES = srcs/ft_printf.c srcs/parsing/parsing.c srcs/parsing/identifier.c \
			srcs/parsing/helper.c srcs/printing/printing.c

LIBFT_CODES = $(addprefix $(LIBFT_DIR)/, ft_putchar.c ft_memalloc.c \
			ft_isdigit.c ft_bzero.c ft_putstr.c ft_itoa.c ft_itoa_unsigned_int.c \
			ft_strlen.c)

#SRCS_OBJ = $(patsubs %.c,%.o, $(SRCS))

#LIBFT_OBJ = $(patsubs %.c,%.o $(LIBFT_CODES))

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	gcc $(FLAGS) -c -I$(INCLUDES) $(SRCS_CODES) $(LIBFT_CODES) -g
	ar rc $(NAME) *.o
	ranlib $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
