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
SOURCE_CODE = srcs/main.c srcs/read.c
INCLUDES = includes/
FRAMEWORK = -framework OpenGL -framework Appkit
LIB_DIR = /usr/local/lib/
LIBFT_DIR = libft/

all: $(NAME)

$(NAME):
		gcc $(SOURCE_CODE) -I libft/includes -L libft/ -lft -g
#cc $(SOURCE_CODE) $(C_FLAGS) -I$(INCLUDES) -L $(LIB_DIR) -lmlx -L libft/ -lft $(FRAMEWORK)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
