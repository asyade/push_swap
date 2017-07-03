#include "ft_printf.h"

static void	pf_parseprefix(char **fmt, t_fmt *arg)
{
	while(**fmt && ft_strchr(PF_FLAGS, **fmt))
	{
		if (**fmt == '#')
			arg->flags |= PFF_FORCPREFIX;
		else if (**fmt == '0')
			arg->flags |= PFF_NOPAD;
		else if (**fmt == '-')
			arg->flags |= PFF_PADRIGHT;
		else if (**fmt == '+')
			arg->flags |= PFF_SHOWSING;
		else if (**fmt == ' ')
			arg->flags |= PFF_BLANKSIGN;
		arg->flags = (arg->flags & PFF_PADRIGHT) ? arg->flags & ~PFF_NOPAD : arg->flags;
		(*fmt)++;
	}
}

static void			pf_parsext(char **fmt, t_fmt *arg)
{
	if (ft_strnequ("hh", *fmt, 2) && (arg->flags |= PFF_HH))
		*fmt += 2;
	else if (ft_strnequ("ll", *fmt, 2) && (arg->flags |= PFF_LL))
		*fmt += 2;
	if (**fmt == 'h' && (arg->flags |= PFF_H))
		++(*fmt);
	else if (**fmt == 'l' && (arg->flags |= PFF_L))
		++(*fmt);
	else if (**fmt == 'j' && (arg->flags |= PFF_J))
		++(*fmt);
	else if (**fmt == 'z' && (arg->flags |= PFF_Z))
		++(*fmt);
}

static void	pf_parsepres(char **fmt, t_fmt *arg, va_list *av)
{
	int prec;

	if (**fmt == '.' && ((*fmt)++))
	{
		if (**fmt == '*' && ((*fmt)++))
		{
			prec = va_arg(*av, int);
			if (prec >= 0 && (arg->flags |= PFF_HASPRES))
				arg->precs = prec;
		}
		else if ((arg->flags |= PFF_HASPRES))
			while (ft_isdigit(**fmt))
				arg->precs = arg->precs * 10 + (*(*fmt)++ - '0');
	}
}

static void		pf_parsesize(char **fmt, t_fmt *arg, va_list *list)
{
	int	av;

	while (**fmt == '*' || ft_isdigit(**fmt))
	{
		if (**fmt == '*' && (arg->flags |= PFF_HASWIDTH) && (*fmt)++)
		{
			av = va_arg(*list, int);
			(av < 0 && (av -= av)) ? (arg->flags |= PFF_PADRIGHT) : 0;
			arg->width = av;
		}
		if (ft_isdigit(**fmt) && (arg->flags |= PFF_HASWIDTH))
		{
			arg->width = 0;
			while (ft_isdigit(**fmt))
				arg->width = arg->width * 10 + (*(*fmt)++ - '0');
		}
	}
}

void		pf_parse_exp(char **fmt, t_fmt *arg, va_list *list)
{
	pf_parseprefix(fmt, arg);
	pf_parsesize(fmt, arg, list);
	pf_parsepres(fmt, arg, list);
	pf_parsext(fmt ,arg);
}
