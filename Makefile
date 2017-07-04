CC = gcc
ODIRS =	push_swap_obj/ checker_obj/
FLAGS = -g -Wall -Wextra -Werror
H_FILES = includes/ft_printf.h includes/libft.h includes/ft_printf.h includes/mixed.h includes/checker.h
HEADERS = -I includes/

#
# push_swap
#

PUSHSWAP_NAME = push_swap
SRC_PUSHSWAP = push_swap_src/en_exec.c \
	push_swap_src/en_fusion.c \
	push_swap_src/en_init.c \
	push_swap_src/main.c \
	push_swap_src/stack.c
PATH_SRC_PUSHSWAP = push_swap_src
OBJ_PUSHSWAP = $(patsubst $(PATH_SRC_PUSHSWAP)/%.c, push_swap_obj/%.o, $(SRC_PUSHSWAP))

#
# checker
#

CHECKER_NAME = checker
SRC_CHECKER = checker_src/exec_str.c \
				checker_src/is_sort.c \
				checker_src/main.c \
				checker_src/stack.c \
				checker_src/en_init.c \
				checker_src/en_exec.c
PATH_SRC_CHECKER = checker_src
OBJ_CHECKER = $(patsubst $(PATH_SRC_CHECKER)/%.c, checker_obj/%.o, $(SRC_CHECKER))

.SILENT :

all : $(CHECKER_NAME) $(PUSHSWAP_NAME)

#
# push_swap rules
#

$(PUSHSWAP_NAME) : $(OBJ_PUSHSWAP)
	make -C ft_printf/
	$(CC) $(FLAGS) $(OBJ_PUSHSWAP) ft_printf/libftprintf.a -o $(PUSHSWAP_NAME) -I includes/
	echo "\033[33mCreating  \033[32m[✔] \033[0m$(PUSHSWAP_NAME)"

push_swap_obj/%.o : $(PATH_SRC_PUSHSWAP)/%.c $(H_FILES)
	mkdir -p $(ODIRS)
	$(CC) $(FLAGS) -c $< -o $@ -I includes/
	echo "\033[33mCompiling \033[32m[✔] \033[0m$<"

#
# checker rules
#

$(CHECKER_NAME) : $(OBJ_CHECKER)
	make -C ft_printf/
	$(CC) $(FLAGS) $(OBJ_CHECKER) ft_printf/libftprintf.a -o $(CHECKER_NAME) -I includes/
	echo "\033[33mCreating  \033[32m[✔] \033[0m$(CHECKER_NAME)"

checker_obj/%.o : $(PATH_SRC_CHECKER)/%.c $(H_FILES)
	mkdir -p $(ODIRS)
	$(CC) $(FLAGS) -c $< -o $@ -I includes/
	echo "\033[33mCompiling \033[32m[✔] \033[0m$<"

#
# Global rules
#

clean :
	make -C ft_printf/ clean
	/bin/rm -rf push_swap_obj checker_obj
	echo "\033[31mRemoving  \033[32m[✔] \033[0mObject files"

fclean : clean
	make -C ft_printf/ fclean
	/bin/rm -f $(PUSHSWAP_NAME) $(CHECKER_NAME)
	echo "\033[31mRemoving  \033[32m[✔] \033[0m$(NAME)"

re : fclean all

.PHONY : valgrind clean fclean re push_swap checker
