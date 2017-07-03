#include "ft_printf.h"

ssize_t	print_escape(t_fmt *arg)
{
	(arg->flags & PFF_HASWIDTH && !(arg->flags & PFF_PADRIGHT)) ?
(print_padd(1, arg->width, arg->flags & PFF_NOPAD ? PDNO : PDSP)) : NULL;
	ft_putchar(FMTCHR);
	pf_gprintpost(arg, 1, PDSP);
	return (arg->flags & PFF_HASWIDTH ? ft_max(arg->width, 1) : 1);
}
