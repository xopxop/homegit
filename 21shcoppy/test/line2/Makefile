NAME = line_edition

INCLUDES = includes/

CFLAGS = -Wall -Wextra -Werror -g

SRCS_CODES = main.c \
buffer.c \
cursor_info.c cursor_motion.c \
check_cursor_pos.c \
getinfo.c \
helper.c \
init.c \
input.c \
output.c \
insert_and_delete.c\
terminal.c \
locate_cursor.c \

SRCS_OBJ = main.o buffer.o cursor_info.o cursor_motion.o check_cursor_pos.o \
getinfo.o helper.o init.o input.o output.o insert_and_delete.o terminal.o \
locate_cursor.o

all: $(NAME)

$(NAME):
	@make -s -C libft/ fclean && make -s -C libft/
	@gcc $(CFLAGS) -I$(INCLUDES) -c $(SRCS_CODES) 
	@gcc $(CFLAGS) $(SRCS_OBJ) libft/libft.a -o $(NAME) -ltermcap
	@echo "\033[32mCreated line_edition\033[0m"

clean:
	@make clean -s -C libft/
	@rm -f $(SRCS_OBJ)
	@echo "\033[32mRemoved Object files\033[0m"

fclean: clean
	@make fclean -s -C libft/
	@rm -f $(SRCS_OBJ)
	@rm -f $(NAME)
	@echo "\033[32mRemoved and line_edition\033[0m"

re: fclean all
