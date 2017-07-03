
#include "libft.h"

void	ft_strrev(char *s)
{
	char *s_end;
	char c;

	s_end = s + ft_strlen(s) - 1;
	while (s < s_end)
	{
		c = *s;
		*s++ = *s_end;
		*s_end-- = c;
	}
}
