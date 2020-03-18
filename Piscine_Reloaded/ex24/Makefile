# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/15 17:43:52 by dthan             #+#    #+#              #
#    Updated: 2019/10/15 17:44:44 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
HEADER = ./includes
SRC = ./srcs/ft_putchar.c ./srcs/ft_putstr.c ./srcs/ft_strcmp.c ./srcs/ft_strlen.c ./srcs/ft_swap.c
FILES_O = ft_putchar.o ft_putstr.o ft_strcmp.o ft_strlen.o ft_swap.o
all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
	ar rc $(NAME) $(FILES_O)
	ranlib $(NAME)
clean:
	/bin/rm -f $(FILES_O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
