#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <libft.h>
# include <stdarg.h>
# include <stdarg.h>
# include <stdint.h>
# include <sys/types.h>
# include <inttypes.h>
# include "ft_printf.h"
# include <wchar.h>

# define SMORE "+"
# define SLESS "-"
# define SSP " "
# define STREMPTY ""
# define STRNULL "(null)"
# define FMTCHR '%'
# define PDNO '0'
# define PDSP ' '
# define PREFIX_HEX "0x"
# define PREFIX_HEX_MAJ "0X"
# define PREFIX_BIN "0b"
# define BASE_BIN "01"
# define BASE_OCTAL "01234567"
# define BASE_NUM "0123456789"
# define BASE_MIN_HEX "0123456789abcdef"
# define BASE_MAJ_HEX "0123456789ABCDEF"
# define PF_FLAGS "#0-+ "

# define PFF_NONE       0x00000000
# define PFF_HH         0x00000002
# define PFF_H          0x00000004
# define PFF_L          0x00000020
# define PFF_LL         0x00000040
# define PFF_J          0x00000080
# define PFF_Z          0x00000200
# define PFF_FORCPREFIX 0x20000000
# define PFF_NOPAD      0x40000000
# define PFF_PADRIGHT   0x80000000
# define PFF_SHOWSING   0x02000000
# define PFF_BLANKSIGN  0x04000000
# define PFF_HASWIDTH   0x08000000
# define PFF_HASPRES    0x00200000

typedef struct		s_fmt
{
	unsigned int	width;
	unsigned int	precs;
	int				flags;
}					t_fmt;

uintmax_t			pf_getsint(va_list *av, t_fmt *f);
void				print_padd(int nbrstrlen, int width, char padwith);
unsigned int		pf_nbslen(uintmax_t nbr, char *base, char *p, t_fmt *f);
void				pf_parse_exp(char **fmt, t_fmt *arg, va_list *list);

void				pf_gprintpre(t_fmt *arg, int len, char pd);
void				pf_gprintpost(t_fmt *arg, int len, char pd);

ssize_t				print_presint(uintmax_t nbr, char *base, t_fmt *arg, char *prefix);
ssize_t				print_escape(t_fmt *arg);
ssize_t				print_str(va_list *args, t_fmt *arg);
ssize_t				print_wstr(va_list *args, t_fmt *arg);
ssize_t				print_ptr(va_list *args, t_fmt *arg);
ssize_t				print_int(va_list *args, t_fmt *arg);
ssize_t				print_long(char **fmt, va_list *args, t_fmt *arg);
ssize_t				print_octal(va_list *args, t_fmt *arg);
ssize_t				print_unsigned(va_list *args, t_fmt *arg);
ssize_t				print_hex(char **fmt, va_list *args, t_fmt *arg);
ssize_t				print_char(va_list *args, t_fmt *arg);
ssize_t				print_wchar(va_list *args, t_fmt *arg);
ssize_t				print_binary(va_list *args, t_fmt *arg);
ssize_t				print_uint(uintmax_t nbr, t_fmt *arg, char *b, char *p);

ssize_t				exec_fmt(char **fmt, va_list *v, t_fmt *a);
int					ft_printf(const char *fmt, ...);

#endif
