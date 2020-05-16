# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/05/16 00:21:06 by dthan             #+#    #+#              #
#    Updated: 2020/05/16 10:46:41 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
INCLUDES = includes/
LIBFT = libft/libft.a
FLAG = -Wall -Wextra -Werror -g -ltermcap
SRCS = srcs/main.c
OBJS = main.o

all: $(NAME)
$(NAME):
	@make -s -C libft/ fclean && make -s -C libft/
	@gcc $(FLAG) -I$(INCLUDES) -c $(SRCS)
	@gcc $(FLAG) $(SRCS) $(LIBFT) -o $(NAME)
	@echo "\033[32mCreated ft_select\033[0m"

clean:
	@make clean -s -C libft/
	@rm -f $(OBJS)
	@echo "\033[32mRemoved Object files\033[0m"

fclean: clean
	@make fclean -s -C libft/
	@rm -f $(NAME)
	@echo "\033[32mRemoved ft_select\033[0m"

re: fclean all

.PHONY: all clean fclean re