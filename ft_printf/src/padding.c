#include "ft_printf.h"

void		print_padd(int nblen, int width, char padwith)
{
	while (nblen++ < width)
		ft_putchar(padwith);
}

void		pf_gprintpre(t_fmt *arg, int len, char s)
{
	if (!s)
		s = arg->flags & PFF_NOPAD ? PDNO : PDSP;
	if (arg->flags & PFF_HASWIDTH && !(arg->flags & PFF_PADRIGHT))
		print_padd(len, arg->width, s);
}

void		pf_gprintpost(t_fmt *arg, int len, char s)
{
	if (!s)
		s = (arg->flags & PFF_NOPAD) ? PDNO : PDSP;
	if (arg->flags & PFF_HASWIDTH && arg->flags & PFF_PADRIGHT)
		print_padd(len, arg->width, s);
}
