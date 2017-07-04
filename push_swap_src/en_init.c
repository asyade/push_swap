#include "push_swap.h"

static int	ps_init_stat(t_ps *ret)
{
	if (!(ret->ssta = malloc(sizeof(t_stat))))
		return (0);
	if (!(ret->sstb = malloc(sizeof(t_stat))))
		return (0);
	ret->ssta->min = INT_MAX;
	ret->ssta->max = INT_MIN;
	ret->sstb->min = INT_MAX;
	ret->sstb->max = INT_MIN;
	ret->ssta->midd = 0;
	ret->sstb->midd = 0;
	return (1);
}

t_ps		*ps_init(char **lst)
{
	t_ps	*ret;
	int		tmp;

	if (!(ret = malloc(sizeof(t_ps))))
		return (NULL);
	if (!(ps_init_stat(ret)))
		return (NULL);
	ret->sta = NULL;
	ret->stb = NULL;
	ret->count = 0;
	ret->min = INT_MAX;
	ret->max = INT_MIN;
	while (*(++lst))
	{
		tmp = ft_atoi(*lst);
		ret->ssta->min = ft_min(tmp, ret->min);
		ret->ssta->max = (tmp > ret->max) ? tmp : ret->max;
		st_addend(&ret->sta, tmp);
	}
	return (ret);
}
