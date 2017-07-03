#include "libft.h"

void	ft_lstaddfront(t_list **root, t_list *new)
{
	t_list	*elem;

	if (!*root)
	{
		*root = new;
		return ;
	}
	elem = *root;
	while (elem->next)
		elem = elem->next;
	elem->next = new;
}
