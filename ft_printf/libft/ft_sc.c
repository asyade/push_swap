#include <libft.h>

int		ft_sc(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			if (str[i] == c)
				count++;
			i++;
		}
	}
	return (count);
}
