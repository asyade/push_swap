#include "checker.h"


void		print_env(t_env *env)
{
	t_stack	*a;
	t_stack	*b;

	a = env->sta;
	b = env->stb;
	ft_printf("\e[1;1H\e[2JSTACK A       STACK B\n");

	while (a || b)
	{
		if (a)
			ft_printf("%+-11d  ", a->val);
		else
			ft_printf("             ");
		if (b)
			ft_printf("%+11d", b->val);
		ft_printf("%s", "\n");
		a = (a) ? a->next : NULL;
		b = (b) ? b->next : NULL;
	}
	usleep(80000);
}

int			is_sort(t_env *ev)
{
	t_stack	*ptr;
	if (ev->stb)
		return (0);
	ptr = ev->sta;
	while (ptr->next)
	{
		if (ptr->val > ptr->next->val)
			return (0);
		ptr = ptr->next;
	}
	return (1);
}
