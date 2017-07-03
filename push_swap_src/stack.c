#include "push_swap.h"

t_stack		*st_new(int val, t_stack *prev, t_stack *next)
{
	t_stack	*ret;

	if (!(ret = (t_stack *)malloc(sizeof(t_stack))))
		return (NULL);
	ret->val = val;
	ret->prev = prev;
	ret->next = next;
	return (ret);
}

void		st_addfront(t_stack	**root, int val)
{
	t_stack		*st;

	st = *root;
	*root = st_new(val, NULL, st);
}

void		st_addend(t_stack **root, int val)
{
	t_stack	*tmp;

	if (!*root)
	{
		*root = st_new(val, NULL, NULL);
		return ;
	}
	tmp = *root;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = st_new(val, tmp, NULL);
}

int			st_pop(t_stack **st)
{
	t_stack	*ret;
	int		v;

	if (!*st)
		return 0;
	ret = (*st);
	*st = (*st)->next;
	v = ret->val;
	free(ret);
	return (v);
}

int			st_done(t_stack **st)
{
	int		ret;
	t_stack	*tmp;

	if (!*st)
		return 0;
	if (!(*st)->next)
	{
		ret = (*st)->val;
		free(*st);
		*st = NULL;
		return (ret);
	}
	tmp = *st;
	while (tmp->next->next)
		tmp = tmp->next;
	ret = tmp->next->val;
	free(tmp->next);
	tmp->next = NULL;
	return (ret);
}
