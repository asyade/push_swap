#include "ft_printf.h"

ssize_t	print_octal(va_list *args, t_fmt *arg)
{
	uintmax_t	nbr;

	nbr = pf_getsint(args, arg);
	if (arg->flags & PFF_FORCPREFIX && nbr == 0 &&
arg->flags & PFF_HASPRES && arg->precs == 0)
	{
		pf_gprintpre(arg, 1, 0);
		pf_gprintpost(arg, 1, PDNO);
		return (arg->flags |= PFF_HASWIDTH ? ft_max(arg->width, 1) : 1);
	}
	if (arg->flags & PFF_FORCPREFIX && nbr != 0)
	{
		arg->flags |= PFF_HASPRES;
		arg->precs = ft_max(arg->precs,
		ft_nbrlen(nbr, BASE_OCTAL) + 1);
	}
	return (print_uint(nbr, arg, BASE_OCTAL, NULL));
}

ssize_t	print_binary(va_list *args, t_fmt *arg)
{
	uintmax_t	nbr;

	nbr = pf_getsint(args, arg);
	return (print_uint(nbr, arg, BASE_BIN, PREFIX_BIN));
}
