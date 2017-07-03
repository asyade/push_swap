#include "ft_printf.h"

static void	ft_putnbrbp(uintmax_t nbr, char *base, t_fmt *av, unsigned len)
{
	if (av->flags & PFF_HASPRES)
		print_padd(len, av->precs, base[0]);
	if (!(nbr == 0 && av->flags & PFF_HASPRES && av->precs == 0))
		ft_putnbrbase(nbr, base);
}

static void uiadjust(t_fmt *av, int len)
{
	if (!(av->flags & (PFF_HASWIDTH & PFF_NOPAD) && !(av->flags & ~PFF_PADRIGHT)))
		return ;
	av->precs = (av->flags & PFF_HASPRES) ? ft_max(av->width, av->precs) : ft_max(av->width, len);
	av->flags = (av->flags | PFF_HASPRES) & ~PFF_HASWIDTH;
}

ssize_t		print_uint(uintmax_t nbr, t_fmt *av, char *base, char *prefix)
{
	unsigned int	len;
	unsigned int	slen;

	len = ft_nbrlen(nbr, base);
	if (av->flags & PFF_NOPAD &&
av->flags & PFF_FORCPREFIX && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	av->flags &= (av->flags & PFF_HASPRES) ? (~PFF_NOPAD) : av->flags;
	uiadjust(av, len);
	slen = pf_nbslen(nbr, base, prefix, av);
	pf_gprintpre(av, slen, 0);
	if (!(av->flags & PFF_NOPAD) &&
av->flags & PFF_FORCPREFIX && prefix != NULL && nbr != 0)
		ft_putstr(prefix);
	ft_putnbrbp(nbr, base, av, len);
	pf_gprintpost(av, slen, 0);
	return (av->flags & PFF_HASWIDTH ? ft_max(slen, av->width) : slen);
}
