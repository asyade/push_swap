#include "libft.h"

unsigned int	ft_nbrlen(uintmax_t nbr, char *base)
{
	size_t			bl;
	unsigned int	i;

	bl = ft_strlen(base);
	i = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= bl;
		i++;
	}
	return (i);
}
