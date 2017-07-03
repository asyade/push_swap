#include "push_swap.h"

void		en_swap(int flags, t_env *env)
{
	t_stack		*work;
	int			tmp;

	env->count++;
	work = (flags & I_SWAPA) ? env->sta : env->stb;
	if (!work || !work->next)
		return ;
	tmp = work->val;
	work->val = work->next->val;
	work->next->val = tmp;
}

void		en_rot(int flags, t_env *env)
{
	int		val;
	t_stack	**work;

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

void		en_push(int flags, t_env *env)
{
	t_stack		**dst;
	t_stack		**src;

	env->count++;
	src = (flags & I_PUSHA) ? &env->stb : &env->sta;
	dst = (flags & I_PUSHA) ? &env->sta : &env->stb;
	if (!*src)
		return ;
	if (src)
		st_addfront(dst, st_pop(src));
}
