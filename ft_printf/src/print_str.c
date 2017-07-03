#include "ft_printf.h"

static size_t	calc_wstrlen(wchar_t *str, int precs, size_t i)
{
	if (*str == '\0' || precs == 0)
		return (i);
	else if (*str <= 0x7F)
		return (calc_wstrlen(str + 1, precs - 1, i + 1));
	else if (*str <= 0x7FF && precs >= 2)
		return (calc_wstrlen(str + 1, precs - 2, i + 2));
	else if (*str <= 0xFFFF && precs >= 3)
		return (calc_wstrlen(str + 1, precs - 3, i + 3));
	else if (*str <= 0x10FFFF && precs >= 4)
		return (calc_wstrlen(str + 1, precs - 4, i + 4));
	return (i);
}

ssize_t			print_str(va_list *args, t_fmt *arg)
{
	char	*str;
	size_t	len;

	if (arg->flags & PFF_L)
		return (print_wstr(args, arg));
	str = va_arg(*args, char*);
	str = (!str) ? STRNULL : str;
	len = arg->flags & PFF_HASPRES ?
ft_nstrlen(str, arg->precs) : ft_strlen(str);
	pf_gprintpre(arg, len, PDSP);
	ft_putnstr(str, len);
	pf_gprintpost(arg, len, PDSP);
	return (arg->flags |= PFF_HASWIDTH ? ft_max(len, arg->width) : len);
}

ssize_t			print_wstr(va_list *args, t_fmt *arg)
{
	wchar_t	*str;
	size_t	l;

	str = va_arg(*args, wchar_t*);
	str = (!str) ? ((wchar_t *)STRNULL) : str;
	l = arg->flags & PFF_HASPRES ?
calc_wstrlen(str, arg->flags & PFF_HASPRES, 0) : ft_wstrlen(str);
	pf_gprintpre(arg, l, PDSP);
	ft_putnwstr(str, l);
	pf_gprintpost(arg, l, PDSP);
	return (arg->flags & PFF_HASWIDTH ? ft_max(l, arg->width) : l);
}
