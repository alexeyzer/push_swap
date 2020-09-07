#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

typedef struct				s_stack
{
	long long int           number;
    struct s_stack          *down;
    struct s_stack          *up;
}							t_stack;

t_stack                     *rd(char **argv, int argc);
void                        c_stack(t_stack *head);
int                         endd(t_stack *head_a, t_stack *head_b, int status);
int                         parsecommands(t_stack **head_a, t_stack **head_b);
int                         strtoint(char *str);
int                         execcommand(char *str, int size, t_stack **head_a, t_stack **head_b);
void                        rdd(char **argv, int argc, t_stack *head);
int                         dupliforhead(t_stack *now);
int                         duplicates(t_stack *now);
int                         countofelem(t_stack *now);
void                        rotate(t_stack *now);
void                        addtostack(t_stack **head, int nbr);
void                        push(t_stack **head_add, t_stack **head_from);
void                        swap(t_stack *head);
void                        reverserotate(t_stack *now);
void                        exec(t_stack **head_a, t_stack **head_b, int command);
t_stack                     *becomelast(t_stack *now);
int                         findbigger(t_stack *now, int number);
void                        truee(t_stack *head_a, t_stack *head_b);
void                        checkresult(t_stack **head_a, t_stack **head_b);

#endif