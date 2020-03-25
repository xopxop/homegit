# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/21 04:50:06 by dthan             #+#    #+#              #
#    Updated: 2020/02/21 04:50:07 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror -g

SRCS_CODES = srcs/main.c srcs/options.c srcs/error_handle.c \
srcs/free.c srcs/display.c srcs/sort.c \
srcs/utility/parser.c srcs/utility/compaser.c srcs/utility/longlist_helper.c \
srcs/utility/shortlist_helper.c srcs/utility/initializer.c \
srcs/utility/info_collecter.c srcs/utility/info_collecter2.c \
srcs/utility/tools.c

SRCS_OBJ = main.o options.o error_handle.o free.o display.o\
sort.o \
parser.o compaser.o longlist_helper.o shortlist_helper.o \
initializer.o info_collecter.o info_collecter2.o tools.o

all: $(NAME)

$(NAME):
	@make -s -C libft/ fclean && make -s -C libft/
	@echo "\033[32mCreated My Library\033[0m"
	@gcc $(CFLAGS) -I$(INCLUDES) -c $(SRCS_CODES) 
	@gcc $(CFLAGS) $(SRCS_OBJ) libft/libft.a -o $(NAME)
	@echo "\033[32mCreated ft_ls Program\033[0m"

clean:
	@make clean -s -C libft/
	@rm -f $(SRCS_OBJ)
	@echo "\033[32mRemoved Object files\033[0m"

fclean: clean
	@make fclean -s -C libft/
	@rm -f $(NAME)
	@echo "\033[32mRemoved Object files and ft_ls Program\033[0m"

re: fclean all
