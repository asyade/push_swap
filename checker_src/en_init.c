#include "push_swap.h"

t_env		*en_init(char **lst)
{
	t_env	*ret;

	if (!(ret = malloc(sizeof(t_env))))
		return (NULL);
	ret->sta = NULL;
	ret->stb = NULL;
	ret->count = 0;
	while (*(++lst))
		st_addend(&ret->sta, ft_atoi(*lst));
	return (ret);
}
