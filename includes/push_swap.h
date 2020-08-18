#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <stdarg.h>
# include <limits.h>
# include <stdint.h>

typedef struct				s_stack
{
	int                     number;
    struct s_stack          *down;
    struct s_stack          *up;
}							t_stack;

t_stack                     *rd(char **argv, int argc);
void                        c_stack(t_stack *head);
int                         endd(t_stack *head_a, t_stack *head_b);

#endif