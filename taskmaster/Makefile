# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:34:34 by dthan             #+#    #+#              #
#    Updated: 2020/09/15 16:52:59 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=taskmasterd
FLAGS = -Wall -Wextra -Werror -g
INCLUDES=includes/
INIPARSER_INCLUDES=iniparser/
LIBFT=libft/libft.a
LIBINIPARSER=iniparser/libiniparser.a
SRCS=srcs/daemon/main.c \
srcs/daemon/init/input/set_default.c \
srcs/daemon/init/input/parse_command_line.c \
srcs/daemon/init/config_file/load_config_file.c \
srcs/daemon/init/config_file/collect_info_from_config_file.c \
srcs/daemon/init/error/error_input.c \
srcs/daemon/init/signal/signal.c \
srcs/daemon/init/daemon/daemon_builder.c \
srcs/daemon/init/log/log.c \
srcs/daemon/init/debug/for_init_input.c \
srcs/daemon/init/debug/for_config_file.c \
srcs/daemon/exit.c

OBJS=main.o \
set_default.o parse_command_line.o \
load_config_file.o collect_info_from_config_file.o \
error_input.o \
signal.o \
daemon_builder.o \
log.o \
for_init_input.o \
for_config_file.o\
exit.o

all: $(NAME)

$(NAME):
	@make -s -C libft/ fclean && make -s -C libft/
	@make -s -C iniparser/ veryclean && make -s -C iniparser/
	@gcc $(FLAGS) -I$(INCLUDES) -c $(SRCS)
	@gcc $(FLAGS) $(SRCS) $(LIBFT) $(LIBINIPARSER) -o $(NAME)
	@echo "\033[032mCreated taskmasterd\033[0m"

clean:
	@make clean -s -C libft/
	@make clean -s -C iniparser/
	@/bin/rm -f $(OBJS)
	@echo "\033[32mRemoved Object files\033[0m"

fclean: clean
	@make fclean -s -C libft/
	@make veryclean -s -C iniparser/
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
