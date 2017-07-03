
#include <libft.h>

int		ft_snc(char *str, char c, int size)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (str != NULL)
	{
		while (str[i] != '\0' && i < size)
		{
			if (str[i] == c)
				count++;
			i++;
		}
	}
	return (count);
}
