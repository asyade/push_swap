#include "checker.h"

int			exec_str(char *str, t_env *ev)
{
	if (ft_strequ(str, "sa"))
		en_swap(I_SWAPA, ev);
	else if (ft_strequ(str, "sb"))
		en_swap(I_SWAPB, ev);
	else if (ft_strequ(str, "ra"))
		en_rot(I_ROTA, ev);
	else if (ft_strequ(str, "rb"))
		en_rot(I_ROTB, ev);
	else if (ft_strequ(str, "rra"))
		en_rot(I_RROTA, ev);
	else if (ft_strequ(str, "rrb"))
		en_rot(I_RROTB, ev);
	else if  (ft_strequ(str, "pa"))
		en_push(I_PUSHA, ev);
	else if (ft_strequ(str, "pb"))
		en_push(I_PUSHB, ev);
	else
		return (0);
	return (1);
}
