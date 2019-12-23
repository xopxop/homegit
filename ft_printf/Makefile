# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 23:35:56 by dthan             #+#    #+#              #
#    Updated: 2019/12/15 05:52:05 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_DIR = srcs

LIBFT_DIR = libft

SRCS_CODES = srcs/core.c srcs/parsing/parsing.c srcs/parsing/helper.c \
			srcs/printing/printing.c srcs/printing/str_summary.c \
			srcs/printing/printing_helper.c srcs/printing/nbr_summary.c

LIBFT_CODES = $(addprefix $(LIBFT_DIR)/, ft_isdigit.c ft_strlen.c\
ft_strchr.c ft_strdup.c ft_memset.c ft_memalloc.c ft_bzero.c ft_strnlen.c\
ft_itoa_intmax.c)

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
