#include "libft.h"

static char	*errname = "default";

void		ft_errset(char *name)
{
	errname = name;
}

void		ft_perror(char *err, int flag)
{
	ft_putstr_fd(errname, 2);
	ft_putstr_fd(": ", 2);
	if (err)
		ft_putstr_fd(err, 2);
	if (flag && err)
		ft_putstr_fd(": ", 2);
	if (flag == ERR_NOCMD)
		ft_putstr_fd("command not found", 2);
	if (flag == ERR_NOFOUND)
		ft_putstr_fd("no such file or directory", 2);
	if (flag == ERR_FORK)
		ft_putstr_fd("can't fork", 2);
	if (flag == ERR_NOTOKEN)
		ft_putstr_fd("invalide token", 2);
	ft_putendl_fd("", 2);
}
