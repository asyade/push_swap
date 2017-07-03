#include "ft_printf.h"

unsigned int	pf_nbslen(uintmax_t nbr, char *base, char *p, t_fmt *arg)
{
	unsigned int	len;
	unsigned int	nblen;

	len = ft_nbrlen(nbr, base);
	nblen = 0;
	if (nbr != 0 || !(arg->flags & PFF_HASPRES) || arg->precs != 0)
		nblen = (arg->flags & PFF_HASPRES) ? ft_max(len, arg->precs) : len;
	return (nblen += (arg->flags & PFF_FORCPREFIX && p != NULL && nbr != 0) ?
ft_strlen(p) : 0);
}

uintmax_t	pf_getsint(va_list *args, t_fmt *arg)
{
	uintmax_t	n;

	n = va_arg(*args, uintmax_t);
	if (arg->flags & PFF_HH)
		n = (unsigned char)n;
	else if (arg->flags & PFF_H)
		n = (unsigned short int)n;
	else if (arg->flags & PFF_L)
		n = (unsigned long int)n;
	else if (arg->flags & PFF_LL)
		n = (unsigned long long int)n;
	else if (arg->flags & PFF_J)
		n = (uintmax_t)n;
	else if (arg->flags & PFF_Z)
		n = (size_t)n;
	else
		n = (unsigned int)n;
	return (n);
}
