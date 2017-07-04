CC = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_atoi.c \
		ft_putnstr.c \
		ft_putnstr_fd.c \
		ft_putnbrbase.c \
		ft_putnbrbase_fd.c \
		ft_putwstr.c \
		ft_putnwstr.c \
		ft_nstrlen.c \
		ft_putwstr_fd.c \
		ft_putwchar.c \
		ft_putwchar_fd.c \
	   ft_nlen.c \
	   ft_bzero.c \
	   ft_isalpha.c \
	   ft_isblank.c \
	   ft_ispunct.c \
	   ft_isascii.c \
	   ft_wstrlen.c \
	   ft_lstrev.c \
	   ft_strsub.c \
	   ft_isdigit.c \
	   ft_isprint.c \
	   ft_isspace.c \
	   ft_isalnum.c \
	   ft_memcmp.c \
	   ft_memchr.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_memset.c \
	   ft_strcat.c \
	   ft_strchr.c \
	   ft_min.c \
	   ft_strcmp.c \
	   ft_strcpy.c \
	   ft_strdup.c \
	   ft_strlcat.c \
	   ft_strlen.c \
	   ft_strncat.c \
	   ft_strncmp.c \
	   ft_strncpy.c \
	   ft_strrchr.c \
	   ft_tolower.c \
	   ft_toupper.c \
	   ft_itoa.c \
	   ft_putstr.c \
	   ft_putchar.c \
	   ft_putnbr.c \
	   ft_perror.c \
	   ft_islower.c \
	   ft_isupper.c \
	   ft_memccpy.c \
	   ft_strnstr.c \
	   ft_strstr.c \
	   ft_strnew.c \
	   ft_strnequ.c \
	   ft_nbrlen.c \
	   ft_strequ.c \
	   ft_strmap.c \
	   ft_strmapi.c \
	   ft_striter.c \
	   ft_striteri.c \
	   ft_strclr.c \
	   ft_strdel.c \
	   ft_memdel.c \
	   ft_memalloc.c \
	   ft_putendl_fd.c \
	   ft_putendl.c \
	   ft_putnbr_fd.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_segcount.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_seglen.c \
	   ft_strsplit.c \
	   ft_lstadd.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_max.c \
	   ft_lstpop.c \
	   ft_lstcreate.c \
	   ft_lstswap.c \
	   ft_lstsort.c \
	   ft_lstadd.c \
	   ft_lstdel.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstmap.c \
	   ft_lstnew.c \
	   ft_max.c \
	   ft_lstpop.c \
	   ft_lstcreate.c \
	   ft_lstswap.c \
	   ft_lstsort.c \
	   get_next_line.c \
	   ft_memdup.c \
	   ft_lstaddfront.c \
	   ft_sc.c \
	   ft_snc.c \
	   ft_pow.c \
	   ft_strndup.c

OBJ = $(SRC:.c=.o)

LIBS = -I ../includes

.SILENT:

all: $(NAME)

$(NAME):
	gcc -c $(SRC) $(FLAGS) $(LIBS)
	echo "\033[33mCreating  \033[32m[✔] \033[0mlibft library"
	ar rcs $(NAME) $(OBJ)
	 ranlib $(NAME)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	echo "\033[31mRemoving  \033[32m[✔] \033[0mlibft library"
	/bin/rm -f $(NAME)

re: fclean all
