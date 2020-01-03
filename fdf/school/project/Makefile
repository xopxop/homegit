# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/03 15:13:05 by dthan             #+#    #+#              #
#    Updated: 2020/01/03 15:22:37 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CFLAGS = -Wall -Wextra -Werror
SOURCE_CODE = srcs/
INCLUDES = includes/
FRAMEWORK = -framework OpenGL -framework Appkit
LIB_DIR = /usr/local/lib/

all: $(NAME)

$(NAME):
	cc $(SOURCE_CODE) $(C_FLAGS) -I$(INCLUDES) -L $(LIB_DIR) -lmlx $(FRAMEWORK)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
