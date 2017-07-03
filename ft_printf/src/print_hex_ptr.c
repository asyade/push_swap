#include "ft_printf.h"

ssize_t	print_hex(char **fmt, va_list *args, t_fmt *arg)
{
	if (**fmt == 'X')
		return (print_uint(pf_getsint(args, arg), arg, BASE_MAJ_HEX, PREFIX_HEX_MAJ));
	return (print_uint(pf_getsint(args, arg), arg, BASE_MIN_HEX, PREFIX_HEX));
}

ssize_t	print_ptr(va_list *args, t_fmt *arg)
{
	arg->flags |= PFF_Z;
	(arg->flags |= PFF_HASPRES) ? (arg->flags &= ~PFF_NOPAD) : 0;
	return (print_presint(pf_getsint(args, arg), BASE_MIN_HEX, arg, PREFIX_HEX));
}
