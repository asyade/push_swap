#include "ft_printf.h"

static unsigned	calc_wcharlen(wchar_t chr)
{
	if (chr <= 0x7F)
		return (1);
	else if (chr <= 0x7FF)
		return (2);
	else if (chr <= 0xFFFF)
		return (3);
	else if (chr <= 0x10FFFF)
		return (4);
	return (0);
}

ssize_t print_char(va_list *args, t_fmt *arg)
{
	if (arg->flags & PFF_L)
		return (print_wchar(args, arg));
	pf_gprintpre(arg, 1, 0);
	ft_putchar(va_arg(*args, int));
	pf_gprintpost(arg, 1, PDSP);
	return (arg->flags & PFF_HASWIDTH ? ft_max(arg->width, 1) : 1);
}

ssize_t	print_wchar(va_list *args, t_fmt *arg)
{
	wchar_t		chr;
	unsigned	len;

	chr = (wchar_t)va_arg(*args, wint_t);
	len = calc_wcharlen(chr);
	pf_gprintpre(arg, 1, 0);
	ft_putwchar(chr);
	pf_gprintpost(arg, 1, PDSP);
	return (arg->flags & PFF_HASWIDTH ? ft_max(len, arg->width) : len);
}
