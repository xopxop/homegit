# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/03/25 09:14:51 by dthan             #+#    #+#              #
#    Updated: 2020/03/25 09:14:54 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror -g

SRCS_CODES = srcs/main.c srcs/error.c \
srcs/environ/tool_for_env.c \
srcs/lexer/lexical_analyzer.c srcs/lexer/spliting_args.c \
srcs/lexer/spliting_cmds.c \
srcs/parser/syntax_analyzer.c srcs/parser/parse_tree.c srcs/parser/lstpush.c \
srcs/executor/executor.c srcs/executor/replace_args.c \
srcs/executor/internal_cmd/cd_cmd.c srcs/executor/internal_cmd/echo_cmd.c \
srcs/executor/internal_cmd/env_cmd.c srcs/executor/internal_cmd/exit_cmd.c \
srcs/executor/internal_cmd/setenv_cmd.c \
srcs/executor/internal_cmd/unsetenv_cmd.c \
srcs/utilities/tool_for_checking.c


SRCS_OBJ = main.o error.o \
tool_for_env.o lexical_analyzer.o spliting_args.o spliting_cmds.o \
syntax_analyzer.o parse_tree.o lstpush.o \
executor.o replace_args.o \
cd_cmd.o echo_cmd.o env_cmd.o exit_cmd.o setenv_cmd.o unsetenv_cmd.o \
tool_for_checking.o

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
