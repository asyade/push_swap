#include "libft.h"

void	*ft_memdup(void *data, size_t len)
{
	void	*dup;

	if (!data || !(dup = malloc(sizeof(len))))
		return (NULL);
	ft_memcpy(dup, data, len);
	return (dup);
}
