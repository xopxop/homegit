# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:34:34 by dthan             #+#    #+#              #
#    Updated: 2020/08/07 10:44:10 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------Updated: 21/2/202--------------------------------#

NAME=

FLAGS = -Wall -Wextra -Werror

INCLUDES=./

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -I$(INCLUDES) -c
	@ar rc $(NAME)

clean:
	@/bin/rm -f

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
