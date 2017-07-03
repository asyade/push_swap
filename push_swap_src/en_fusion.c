#include "push_swap.h"

void		en_fusion(t_env *env)
{
	int curr;
	int min;

	curr = 0;
	while (env->sta)
	{
		min = 0;
		while (min < curr && env->stb && env->sta && env->sta->val < env->stb->val)
		{
			min++;
			en_rot(I_ROTB, env);
		}
		curr++;
		en_push(I_PUSHB, env);
		while(min--)
			en_rot(I_RROTB, env);
	}
	while (env->stb)
	{
		en_push(I_PUSHA, env);
	}
}
