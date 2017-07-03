#include "push_swap.h"

static int		check_av(char **av)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (av[++i])
	{
		j = 0;
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]) && !(ft_strchr("+-", av[i][j])))
				return (0);
			j++;
		}
		if (j > 11)
			return (0);
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_env	*env;

	(void)ac;
	if (!check_av(av))
	{
		ft_putendl_fd("Erreur", 2);
		return (1);
	}
	env = en_init(av);
	en_fusion(env);
	return (EXIT_SUCCESS);
}
