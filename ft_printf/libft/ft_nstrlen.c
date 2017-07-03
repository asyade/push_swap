
#include "libft.h"

size_t		ft_nstrlen(const char *str, size_t n)
{
	size_t	i;

	i = 0;
	while (*str++ && i < n)
		i++;
	return (i);
}
