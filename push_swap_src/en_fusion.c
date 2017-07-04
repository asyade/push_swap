#include "push_swap.h"

t_stack			*st_pkend(t_stack *st)
{
	while (st && st->next)
		st = st->next;
	return (st);
}

t_stack			*st_pkpre(t_stack *st)
{
	while (st && st->next && st->next->next)
		st = st->next;
	return (st);
}


void		path_add(char	inst[3], t_path **path)
{
	if (!(new = malloc(sizeof(t_path))))
		return ;
	new->count++;

}

int			can_insert(t_ps	*env, t_path *path)
{
	if (!env->stb || !env->sta)
		return (1);
	if (env->sta->val > env->stb->val)
	{
		//TODO check last ellement if path > 0
		return (1);
	}
}

t_list		*en_ftb(t_ps *env, t_path *p)
{
	t_path	*st;
	t_ps	*tma;
	t_ps	*tmb;
	t_list	*res[2]

	if (can_insert(ps, p))
		return (p);
	if (!(st = (t_path)malloc(sizeof(t_path))))
		return (NULL);
	if (!(tma = (t_ps)ft_memdup(env)))
		return (NULL);
	if (!(tmb = (t_ps)ft_memdup(env)))
		return (NULL);
	ps_rot(I_ROTA, tma);
	ps_rot(I_ROTB, tmb);
	res[0] = en_ftb(tma, p);
	res[1] = en_ftb(tmb, p);
	return (ps_join_path((res[0]->count < res[1]->count) ? res[0])
}

void		en_fusion(t_ps *env)
{
	while (env->sta)
	{
		if (!env->stb || (env->sta->val > env->stb->val))
		{
			ps_push(I_PUSHB, env);
			continue ;
		}
		/*if (env->sta->val < env->sstb->min)
		{
			en_push(I_PUSHB, env);
			en_rot(I_ROTB, env);
			continue ;
		}*/
	}
	while (env->stb)
	{
		ps_push(I_PUSHA, env);
	}
}
