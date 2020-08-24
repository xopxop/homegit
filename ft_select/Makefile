# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 00:21:06 by dthan             #+#    #+#              #
#    Updated: 2020/07/15 23:44:47 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
INCLUDES = includes/
LIBFT = libft/libft.a
FLAG = -g -Wall -Wextra -Werror
SRCS = srcs/main.c srcs/arrows.c srcs/display.c srcs/elements.c srcs/other_keys.c
OBJS = main.o arrows.o display.o elements.o other_keys.o

all: $(NAME)
$(NAME):
	@make -s -C libft/ fclean && make -s -C libft/
	@gcc $(FLAG) -I$(INCLUDES) -c $(SRCS)
	@gcc $(FLAG) $(SRCS) $(LIBFT) -o $(NAME) -ltermcap
	@echo "\033[32mCreated ft_select\033[0m"

clean:
	@make clean -s -C libft/
	@rm -f $(OBJS)
	@echo "\033[32mRemoved ft_select Object files\033[0m"

fclean: clean
	@make fclean -s -C libft/
	@rm -f $(NAME)
	@echo "\033[32mRemoved ft_select\033[0m"

re: fclean all

.PHONY: all clean fclean re