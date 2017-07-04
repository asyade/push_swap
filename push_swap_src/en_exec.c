#include "push_swap.h"

void		ps_swap(int flags, t_ps *env)
{
	t_stack		*work;
	int			tmp;

	ft_putendl((flags & I_SWAPA) ? "sa" : "sb");
	env->count++;
	work = (flags & I_SWAPA) ? env->sta : env->stb;
	if (!work || !work->next)
		return ;
	tmp = work->val;
	work->val = work->next->val;
	work->next->val = tmp;
}

void		ps_rot(int flags, t_ps *env)
{
	int		val;
	t_stack	**work;

	ft_putstr(flags & (I_RROTA | I_RROTB) ? "r" : NULL);
	ft_putendl((flags & (I_ROTA | I_RROTA)) ? "ra" : "rb");//TODO show rr or rrr
	env->count++;
	work = (flags & (I_ROTA | I_RROTA)) ? &env->sta : &env->stb;
	if (!*work)
		return ;
	if (flags & (I_ROTA | I_ROTB))
	{
		val = st_pop(work);
		st_addend(work, val);
	}
	else
	{
		val = st_done(work);
		st_addfront(work, val);
	}
}

void		ps_push(int flags, t_ps *env)
{
	t_stack		**dst;
	t_stack		**src;

	ft_putendl((flags & I_PUSHA) ? "pa" : "pb");
	env->count++;
	src = (flags & I_PUSHA) ? &env->stb : &env->sta;
	dst = (flags & I_PUSHA) ? &env->sta : &env->stb;
	if (!*src)
		return ;
	if (src)
		st_addfront(dst, st_pop(src));
	if ((flags & I_PUSHA) && *dst)
	{
		env->ssta->min = (env->ssta->min < (*dst)->val) ? env->ssta->min : (*dst)->val;
		env->ssta->max = (env->ssta->max > (*dst)->val) ? env->ssta->max : (*dst)->val;
	}
	else if (*dst)
	{
		env->sstb->min = (env->sstb->min < (*dst)->val) ? env->sstb->min : (*dst)->val;
		env->sstb->max = (env->sstb->max > (*dst)->val) ? env->sstb->max : (*dst)->val;
	}
}
