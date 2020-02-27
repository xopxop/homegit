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

SRCS_CODES = srcs/ft_ls.c

SRCS_OBJ = ft_ls.o

all: $(NAME)

$(NAME):
	@make -s -C libft/ fclean && make -s -C libft/
	@echo "\033[32mCreated My Library\033[0m"
	@gcc $(CFLAGS) $(SRCS_CODES) -I$(INCLUDES) -L./libft -lft -o $(NAME)
	@echo "\033[32mCreated ft_ls Program\033[0m"

clean:
	@make clean -s -C libft/
	@rm -f $(SRCS_OBJ)
	@echo "\033[32mRemoved Object files\033[0m"

fclean:
	@make fclean -s -C libft/
	@rm -f $(NAME)
	@echo "\033[32mRemoved Object files and ft_ls Program\033[0m"

re: fclean all
