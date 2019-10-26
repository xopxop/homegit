# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:34:34 by dthan             #+#    #+#              #
#*   Updated: 2019/10/26 06:20:54 by dthan            ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

NAME=libft.a

SRCS= ./*.c 

OBJECTS= *.o
INCLUDES=./

all: $(NAME)

$(NAME): $(SRCS)  ./libft.h
	@gcc -Wall -Wextra -Werror -I$(INCLUDES) -c $(SRCS)
	@ar rc $(NAME) $(OBJECTS)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJECTS)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
