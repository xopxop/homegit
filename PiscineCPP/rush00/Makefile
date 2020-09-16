# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/02 12:13:01 by dthan             #+#    #+#              #
#    Updated: 2020/09/02 12:21:38 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_retro

COMPILER = clang++

FLAGS = -Wall -Wextra -Werror -g

SRCS =	srcs/main.cpp \
		#srcs/theme \
		#srcs/spaceship \
		#srcs/enemies \

OBJS = 

all: $(NAME)

$(NAME):
	$(COMPILER) $(FLAGS) -c $(SRCS)
	$(COMPILER) $(FLAGS) -o $(NAME) $(OBJS) -lncurses

clean:
	/bin/rm -f $(OBJS)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
