#include "ft_printf.h"

static intmax_t	get_sval(va_list *args, t_fmt *arg)
{
	intmax_t	nbr;

	nbr = va_arg(*args, intmax_t);
	if (arg->flags & PFF_HH)
		return((char)nbr);
	else if (arg->flags & PFF_H)
		return((short int)nbr);
	else if (arg->flags & PFF_LL)
		return((long long int)nbr);
	else if (arg->flags & PFF_L)
		return((long int)nbr);
	else if (arg->flags & PFF_J)
		return((intmax_t)nbr);
	else if (arg->flags & PFF_Z)
		return((size_t)nbr);
	return((int)nbr);
}

ssize_t	print_presint(uintmax_t nbr, char *base, t_fmt *arg, char *pr)
{
	unsigned	len;
	size_t		sek;

	sek = ft_strlen(pr);
	len = pf_nbslen(nbr, base, NULL, arg) + sek;
	if (arg->flags & PFF_HASWIDTH && !(arg->flags & (PFF_PADRIGHT | PFF_NOPAD)))
	{
		print_padd(len, arg->width, PDSP);
		sek += ft_max(arg->width - len, 0);
		arg->flags &= ~PFF_HASWIDTH;
	}
	else if (arg->flags & PFF_HASWIDTH)
		arg->width -= ft_strlen(pr);
	ft_putstr(pr);
	return (print_uint(nbr, arg, base, NULL) + sek);
}

ssize_t			print_int(va_list *args, t_fmt *arg)
{
	intmax_t		nbr;
	char			*pr;

	pr = STREMPTY;
	arg->flags = (arg->flags & PFF_HASPRES) ? arg->flags & ~PFF_NOPAD : arg->flags;
	nbr = get_sval(args, arg);
	if (!(nbr < 0 || arg->flags & (PFF_SHOWSING | PFF_BLANKSIGN)))
		return (print_uint(nbr, arg, BASE_NUM, NULL));
	if (nbr < 0 && (nbr = -nbr))
		pr = SLESS;
	else if (arg->flags & PFF_SHOWSING)
		pr = SMORE;
	else if (arg->flags & PFF_BLANKSIGN)
		pr = SSP;
	return (print_presint(nbr, BASE_NUM, arg, pr));
}

ssize_t	print_long(char **format, va_list *args, t_fmt *arg)
{
	arg->flags |= PFF_L;
	return exec_fmt(format, args, arg);
}

ssize_t	print_unsigned(va_list *args, t_fmt *arg)
{
	return (print_uint(pf_getsint(args, arg), arg, BASE_NUM, NULL));
}
