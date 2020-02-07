# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/05 23:35:56 by dthan             #+#    #+#              #
#    Updated: 2020/02/07 23:01:30 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS_DIR = srcs

LIBFT_DIR = libft

SRCS_CODES = $(addprefix $(SRCS_DIR)/, core.c parsing.c printing.c \
parsing/fill_struct.c parsing/parsing_helper.c \
printing/nbr_to_str.c printing/padding.c printing/percision.c \
printing/type_c.c printing/type_di.c printing/type_f.c printing/type_o.c \
printing/type_p.c printing/type_s.c printing/type_u.c printing/type_xX.c \
printing/type_percent.c printing/printing_helper.c)

LIBFT_CODES = $(addprefix $(LIBFT_DIR)/, ft_isdigit.c ft_strlen.c\
ft_strchr.c ft_strdup.c ft_memset.c ft_memalloc.c ft_bzero.c \
ft_itoa.c ft_strjoin.c ft_strcpy.c ft_strcat.c ft_strnew.c ft_strcmp.c ft_strncpy.c\
ft_toupper.c ft_isalnum.c ft_strrev.c)

#SRCS_OBJ = $(patsubs %.c,%.o, $(SRCS))

#LIBFT_OBJ = $(patsubs %.c,%.o $(LIBFT_CODES))

INCLUDES = includes/

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	@gcc $(FLAGS) -c -I$(INCLUDES) $(SRCS_CODES) $(LIBFT_CODES) -g
	@ar rc $(NAME) *.o
	@ranlib $(NAME)
	@echo "\033[32mCreated libftprintf library\033[0m"

clean:
	@rm -f *.o
	@echo "\033[32mRemoved Object Files\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[32mRemoved Object files and library\033[0m"

re: fclean all

.PHONY: all clean fclean re
