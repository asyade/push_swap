/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acorbeau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/11 17:39:11 by acorbeau          #+#    #+#             */
/*   Updated: 2017/06/16 14:06:37 by tgascoin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>
# include <wchar.h>

# define BUFF_SIZE 1024

# define ERR_NOFOUND 1
# define ERR_NOACCESS 2
# define ERR_NOCMD 3
# define ERR_FORK 4
# define ERR_NOTOKEN 5

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				ft_perror(char *str, int flags);
void				ft_errset(char *name);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *s, int c, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				ft_putwstr(wchar_t const *s);
void				*ft_memmove(void *dest, const void *src, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_max(size_t a, size_t b);
int					ft_isspace(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_ispunct(int c);
int					ft_isblank(int c);

unsigned int		ft_nbrlen(uintmax_t nbr, char *base);
int					ft_nlen(int n);
size_t				ft_strlen(const char *str);
size_t				ft_nstrlen(const char *str, size_t n);
int					ft_strcmp(const char *a, const char *b);
int					ft_strncmp(const char *a, const char *b, size_t n);

char				*ft_strncpy(char *dest, char const *src, size_t n);
char				*ft_strcpy(char *dest, char const *src);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t siz);
char				*ft_strdup(const char *str);

char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *str, const char *find);
char				*ft_strnstr(const char *str, const char *find, size_t n);

void				ft_putwchar_fd(wchar_t c, int fd);
void				ft_putwchar(wchar_t c);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putchar_fd(char c, int fd);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putnstr(char const *s, size_t strlen);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putnstr_fd(char const *s, size_t strlen, int fd);
void				ft_putnbr(int n);
int					ft_atoi(const char *str);
char				*ft_itoa(int n);
void				ft_putendl_fd(char const *s, int fd);
size_t				ft_wstrlen(wchar_t *str);
void				ft_putendl(char const *s);
void				ft_putnbr_fd(int n, int fd);
void				ft_putwstr_fd(wchar_t const *s, int fd);
void				ft_putnwstr(wchar_t const *s, size_t strlen);
void				ft_putnbrbase(uintmax_t n, char *base);
void				ft_putnbrbase_fd(uintmax_t n, char *base, int fd);


void				*ft_memdup(void *data, size_t len);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);

char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char(*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);

char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
int					ft_segcount(char const *s, char c);
size_t				ft_seglen(char const *s, char c);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);

t_list				*ft_lstnew(void const *content, size_t content_size);
t_list				*ft_lstcreate(void *content, size_t content_size);
void				ft_lstdelone(t_list **root, void (*f)(void *, size_t));
void				ft_lstdel(t_list **root, void (*f)(void *, size_t));
void				ft_lstadd(t_list **root, t_list *item);
void				ft_lstaddfront(t_list **root, t_list *new);
void				ft_lstiter(t_list *root, void (*f)(t_list *item));
t_list				*ft_lstmap(t_list *root, t_list *(f)(t_list *item));
void				ft_lstpop(t_list **root);
void				ft_lstswap(t_list *lst1, t_list *lst2);
void				ft_lstsort(t_list *root, int (*f)(t_list *, t_list *));
void				ft_lstrev(t_list **alst);

char				*ft_strjoin_at(char *s1, char *s2, int i);
int					ft_sc(char *str, char c);
int					ft_snc(char *str, char c, int size);
int					ft_pow(int n, int p);
char				*ft_strndup(const char *s1, size_t size);

int					get_next_line(int fd, char **line);

#endif
