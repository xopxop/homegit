# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/10 14:35:13 by dthan             #+#    #+#              #
#    Updated: 2020/05/10 14:35:14 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = replace

FLAGS = -g

SRCS = main.cpp

OBJS = main.o

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
