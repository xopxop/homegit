# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/25 09:14:51 by dthan             #+#    #+#              #
#    Updated: 2020/07/13 11:53:52 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror -g

SRCS_CODES = srcs/main.c srcs/error.c srcs/helper.c srcs/helper2.c \
srcs/internal_cmd/cd_cmd.c srcs/internal_cmd/echo_cmd.c srcs/internal_cmd/env_cmd.c \
srcs/internal_cmd/exit_cmd.c srcs/internal_cmd/setenv_cmd.c \
srcs/internal_cmd/unsetenv_cmd.c \
srcs/utilities/change_tokens.c srcs/utilities/tool_for_checking.c \
srcs/utilities/tool_for_env.c \
srcs/utilities/replace_args.c srcs/utilities/spliting_args.c \
srcs/utilities/spliting_cmds.c

SRCS_OBJ = main.o error.o helper.o helper2.o \
cd_cmd.o echo_cmd.o env_cmd.o exit_cmd.o setenv_cmd.o unsetenv_cmd.o \
change_tokens.o tool_for_checking.o tool_for_env.o \
replace_args.o spliting_args.o spliting_cmds.o

all: $(NAME)

$(NAME):
	@make -s -C libft/ fclean && make -s -C libft/
	@gcc $(CFLAGS) -I$(INCLUDES) -c $(SRCS_CODES) 
	@gcc $(CFLAGS) $(SRCS_OBJ) libft/libft.a -o $(NAME)
	@echo "\033[32mCreated Minishell\033[0m"

clean:
	@make clean -s -C libft/
	@rm -f $(SRCS_OBJ)
	@echo "\033[32mRemoved Object files\033[0m"

fclean: clean
	@make fclean -s -C libft/
	@rm -f $(SRCS_OBJ)
	@rm -f $(NAME)
	@echo "\033[32mRemoved and Minishell\033[0m"

re: fclean all
