 #ifndef MIXED_H
 # define MIXED_h

 # include "libft.h"
 # include "ft_printf.h"

# define INT_MIN -2147483648
# define INT_MAX 2147483647

 # define I_SWAPA    0x00000002
 # define I_SWAPB    0x00000004
 # define I_SWAPAB   0x00000008
 # define I_ROTA     0x00000020
 # define I_ROTB     0x00000040
 # define I_RROTA    0x00000080
 # define I_RROTB    0x00000200
 # define I_PUSHA    0x00000400
 # define I_PUSHB    0x00000800
 # define I_RRR      0x280
 # define I_RR		 0x60
 # define I_SS		 0x6

typedef struct		s_stack
{
	int				val;
	struct s_stack	*prev;
	struct s_stack	*next;
}					t_stack;

typedef struct      s_stat
{
    int             min;
    int             midd;
    int             max;
}					t_stat;

typedef struct		s_env
{
	t_stack			*sta;
	t_stack			*stb;
    t_stat			*ssta;
	t_stat			*sstb;
	int				mode;
	int				count;
    int             min;
    int             max;
}					t_env;

void				en_rot(int flags, t_env *env);
void				en_swap(int flags, t_env *env);
void				en_push(int flags, t_env *env);
void				st_addfront(t_stack	**root, int val);
void				st_addend(t_stack **root, int val);
int					st_done(t_stack **st);
int					st_pop(t_stack **st);
t_env				*en_init(char **lst);

#endif
