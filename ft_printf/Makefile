CC = gcc

NAME = libftprintf.a

PATH_SRC = src

ODIRS = obj/

SRC = src/ft_printf.c \
	   src/parse_exp.c \
	   src/ft_printf_fn.c \
	   src/print_uint.c \
	   src/print_char.c \
	   src/print_escape.c \
	   src/print_hex_ptr.c \
	   src/print_int.c \
	   src/print_octal.c \
	   src/print_str.c \
	   src/padding.c \

OBJ = $(patsubst $(PATH_SRC)/%.c, obj/%.o, $(SRC))

FLAGS = -g -Wall -Wextra -Werror

LIBS = -L./libft -lft

H_FILES = includes/libft.h includes/ft_printf.h

HEADERS = -I includes/

.SILENT :

all : $(NAME)

obj/%.o : $(PATH_SRC)/%.c $(H_FILES)
	mkdir -p $(ODIRS)
	$(CC) $(FLAGS) -c $< -o $@ -I includes/
	echo "\033[33mCompiling \033[32m[✔] \033[0m$<"

$(NAME) : $(OBJ)
	make -C libft/
	cp libft/libft.a libftprintf.a
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	make -C libft/ clean
	/bin/rm -rf obj/
	echo "\033[31mRemoving  \033[32m[✔] \033[0mObject files"

fclean : clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)
	echo "\033[31mRemoving  \033[32m[✔] \033[0m$(NAME)"

re : fclean all

valgrind : all
	valgrind --leak-check=full ./21sh

.PHONY : valgrind clean fclean re
