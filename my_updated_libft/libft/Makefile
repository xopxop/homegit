# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dthan <dthan@student.hive.fi>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/24 16:34:34 by dthan             #+#    #+#              #
#    Updated: 2021/02/04 14:54:14 by dthan            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#-----------------------------Updated: 4/2/2021--------------------------------#

CC			:= clang
CFLAGS		:= -Wall -Wextra -Werror
INCLUDES	:= -Iincludes/
LIBRARY		:= libft.a

#<<<<<<<<<<CTYPE.H>>>>>>>>>>#

CTYPE_DIR := ctype
CTYPE_FILES += ft_isalpha.c
CTYPE_FILES += ft_isdigit.c
CTYPE_FILES += ft_isalnum.c
CTYPE_FILES += ft_isascii.c
CTYPE_FILES += ft_isprint.c
CTYPE_FILES += ft_isspace.c
CTYPE_FILES += ft_islower.c
CTYPE_FILES += ft_isupper.c
CTYPE_FILES += ft_toupper.c
CTYPE_FILES += ft_tolower.c
CTYPE := $(addprefix $(CTYPE_DIR)/,$(CTYPE_FILES))

#<<<<<<<<<<LIST.H>>>>>>>>>># NOTE: Optional

LIST_DIR := list
LIST_FILES += ft_lstnew.c
LIST_FILES += ft_lstdelone.c
LIST_FILES += ft_lstdel.c
LIST_FILES += ft_lstadd.c
LIST_FILES += ft_lstiter.c
LIST_FILES += ft_lstmap.c
LIST := $(addprefix $(LIST_DIR)/,$(LIST_FILES))

#<<<<<<<<<<PRINT.H>>>>>>>>>># NOTE: Optional

PRINT_DIR := print
PRINT_FILES += ft_putchar.c
PRINT_FILES += ft_putstr.c
PRINT_FILES += ft_putendl.c
PRINT_FILES += ft_putnbr.c
PRINT_FILES += ft_putchar_fd.c
PRINT_FILES += ft_putstr_fd.c
PRINT_FILES += ft_putendl_fd.c
PRINT_FILES += ft_putnbr_fd.c
PRINT := $(addprefix $(PRINT_DIR)/,$(PRINT_FILES))

#<<<<<<<<<<PRINTF_H>>>>>>>>>># not yet

STDIO_DIR := stdio
PRINTF_DIR := ft_printf
PRINTF_FILES += core.c
PRINTF_FILES += parsing.c
PRINTF_FILES += printing.c
PRINTF_FILES += parsing/fill_struct.c
PRINTF_FILES += parsing/parsing_helper.c
PRINTF_FILES += printing/nbr_to_str.c
PRINTF_FILES += printing/width_control.c
PRINTF_FILES += printing/percision_control.c
PRINTF_FILES += printing/flag_control.c
PRINTF_FILES += printing/printing_helper.c
PRINTF_FILES += printing/type_c.c
PRINTF_FILES += printing/type_di.c
PRINTF_FILES += printing/type_f.c
PRINTF_FILES += printing/type_o.c
PRINTF_FILES += printing/type_p.c
PRINTF_FILES += printing/type_s.c
PRINTF_FILES += printing/type_u.c
PRINTF_FILES += printing/type_hex.c
PRINTF_FILES += printing/type_percent.c
PRINTF := $(addprefix $(STDIO_DIR)/$(PRINTF_DIR)/,$(PRINTF_FILES))

#<<<<<<<<<<STDLIB.H>>>>>>>>>>#

STDLIB_DIR := stdlib
STDLIB_FILES += ft_atoi.c
STDLIB = $(addprefix $(STDLIB_DIR)/,$(STDLIB_FILES))

#<<<<<<<<<<STRING.H>>>>>>>>>>#

STRING_DIR := string
STRING_FILES += ft_memset.c
STRING_FILES += ft_bzero.c
STRING_FILES += ft_memcpy.c
STRING_FILES += ft_memccpy.c
STRING_FILES += ft_memmove.c
STRING_FILES += ft_memchr.c
STRING_FILES += ft_memcmp.c
STRING_FILES += ft_strlen.c
STRING_FILES += ft_strdup.c
STRING_FILES += ft_strndup.c
STRING_FILES += ft_strcpy.c
STRING_FILES += ft_strncpy.c
STRING_FILES += ft_strcat.c
STRING_FILES += ft_strncat.c
STRING_FILES += ft_strlcat.c
STRING_FILES += ft_strchr.c
STRING_FILES += ft_strrchr.c
STRING_FILES += ft_strstr.c
STRING_FILES += ft_strnstr.c
STRING_FILES += ft_strcmp.c
STRING_FILES += ft_strncmp.c
STRING := $(addprefix $(STRING_DIR)/,$(STRING_FILES))

#<<<<<<<<<<UTILITY.H>>>>>>>>>># NOTE: Optional

UTILITY_DIR := utility
UTILITY_FILES += ft_memalloc.c
UTILITY_FILES += ft_memdel.c
UTILITY_FILES += ft_strnew.c
UTILITY_FILES += ft_strdel.c
UTILITY_FILES += ft_strclr.c
UTILITY_FILES += ft_striter.c
UTILITY_FILES += ft_striteri.c
UTILITY_FILES += ft_strmap.c
UTILITY_FILES += ft_strmapi.c
UTILITY_FILES += ft_strequ.c
UTILITY_FILES += ft_strnequ.c
UTILITY_FILES += ft_strsub.c
UTILITY_FILES += ft_strjoin.c
UTILITY_FILES += ft_strtrim.c
UTILITY_FILES += ft_strsplit.c
UTILITY_FILES += ft_swap.c
UTILITY_FILES += ft_ctwords.c
UTILITY_FILES += ft_itoa.c
UTILITY_FILES += ft_strjoin_and_free.c
UTILITY_FILES += ft_itoa_signed_and_unsigned_long_long.c
UTILITY_FILES += ft_strrev.c
UTILITY_FILES += ft_arrayct.c
UTILITY_FILES += ft_arraydel.c
UTILITY := $(addprefix $(UTILITY_DIR)/,$(UTILITY_FILES))

#<<<<<<<<<<GET_NEXT_LINE_PROJECT>>>>>>>>>#

GNL_DIR := get_next_line
GNL_FILES += get_next_line.c
GNL := $(addprefix $(GNL_DIR)/,$(GNL_FILES))

###### SUM-UP #####
SRC += $(CTYPE)
SRC += $(LIST)
SRC += $(PRINT)
SRC += $(PRINTF)
SRC += $(STDLIB)
SRC += $(STRING)
SRC += $(UTILITY)
SRC += $(GNL)

OBJ_DIR := objects
OBJ_FILES := $(addprefix $(OBJ_DIR)/,$(SRC:%.c=%.o))


all: mkdirs libft

mkdirs:
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $(OBJ_DIR)/$(notdir $@)

libft: $(OBJ_FILES)
	@ar rc $(LIBRARY) $(addprefix $(OBJ_DIR)/,$(notdir $(OBJ_FILES)))
	@ranlib $(LIBRARY)

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(LIBRARY)

re: fclean all

.PHONY: all mkdirs libft clean fclean re
