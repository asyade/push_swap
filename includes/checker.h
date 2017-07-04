#ifndef CHECKER_H
# define CHECKER_H

# include "mixed.h"


int			exec_str(char *str, t_env *ev);
int			is_sort(t_env *ev);
void		print_env(t_env *env);

#endif
