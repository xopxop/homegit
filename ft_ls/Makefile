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

CFLAGS = -Wall -Wextra- Werror -g

SRCS_CODES = 

SRCS_OBJ = 

all: $(NAME)
	@gcc $(CFLAGS) $(SRCS_CODES) -I$(INCLUDES) -o $(NAME)
	@echo "\033[32mCreated ft_ls Program\033[0m"

clean:
	@rm -f $(SRCS_OBJ)
	@echo "\033[32mRemoved Object files\033[0m"

fclean:
	@rm -f $(NAME)
	@echo "\033[32mRemoved Object files and ft_ls Program\033[0m"

re: fclean all
