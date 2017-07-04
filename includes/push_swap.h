#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "mixed.h"

#define KYEL  "\x1B[33m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KBLU  "\x1B[34m"
#define KNRM  "\x1B[0m"

typedef struct		s_ps
{
	t_stack			*sta;
	t_stack			*stb;
    t_stat			*ssta;
	t_stat			*sstb;
	int				mode;
	int				count;
    int             min;
    int             max;
}					t_ps;

t_ps				*ps_init(char **lst);
void				en_fusion(t_ps *env);
void				print_env(t_ps *env);
void				ps_swap(int flags, t_ps *env);
void				ps_rot(int flags, t_ps *env);
void				ps_push(int flags, t_ps *env);

#endif
