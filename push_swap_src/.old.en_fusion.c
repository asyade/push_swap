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

void		insert_bytop(t_env *env)
{
	int	rot;
	int	old;

	rot = 0;
	old = env->stb->val;
	while (env->sta->val < env->stb->val)
	{
		old = env->stb->val;
		if (env->sta->next && env->stb->next && env->sta->next->val >= env->stb->next->val && env->sta->next->val < old)
			en_rot(I_ROTA, env);
		en_rot(I_ROTB, env);
		rot++;
	}
	while (env->sta && env->stb && env->sta->val >= env->stb->val && env->sta->val < old)
		en_push(I_PUSHB, env);
	while (rot--)
	{
		if (env->sta && env->sta->next && st_pkpre(env->stb) && env->stb->next && env->sta->next->val > st_pkend(env->stb)->val && env->sta->val > st_pkpre(env->stb)->val)
		{
			en_rot(I_ROTA, env);
		}
		en_rot(I_RROTB, env);
		if (env->sta && st_pkend(env->stb) && env->sta->val > env->stb->val && env->sta->val < st_pkend(env->stb)->val)
			en_push(I_PUSHB, env);
	}
}

void		en_fusion(t_env *env)
{
	while (env->sta)
	{
		if (!env->stb || (env->sta->val > env->stb->val))
		{
			en_push(I_PUSHB, env);
			continue ;
		}
		if (env->sta->val < env->sstb->min)
		{
			en_push(I_PUSHB, env);
			en_rot(I_ROTB, env);
			continue ;
		}
		insert_bytop(env);
	}
	while (env->stb)
	{
		en_push(I_PUSHA, env);
	}
}
