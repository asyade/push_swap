#include "checker.h"

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

int			main(int ac, char **av)
{
	t_env	*ev;
	char	*line;
	int		print;

(void)print;
	ac = 1;
	line = NULL;
	print = 0;
	if (ft_strequ(av[1], "-v"))
	{
		print = 1;
		av++;
	}
	if (!check_av(av))
	{
		ft_putendl_fd("Erreur", 2);
		ac = 0;
	}
	ev = en_init(av);
	while (get_next_line(0, &line) && ac)
	{
		if (!exec_str(line, ev))
		{
			ft_putendl("KO");
			ac = 0;
			break ;
		}
		if (print)
		{
			print_env(ev);
		}
		free(line);
	}
	if (is_sort(ev) && ac)
		ft_putendl("OK");
	else if (ac)
		ft_putendl("KO");
	free(line);
}
