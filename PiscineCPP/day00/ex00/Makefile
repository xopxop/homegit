# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/04/23 10:21:22 by dthan             #+#    #+#              #
#    Updated: 2020/04/23 10:21:23 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

FLAGS = -Wall -Wextra -Werror

SRCS = megaphone.cpp

OBJS = megaphone.o

COMPILE = clang++

all: $(NAME)

$(NAME):
	$(COMPILE) $(FLAGS) -c $(SRCS)
	$(COMPILE) $(FLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
