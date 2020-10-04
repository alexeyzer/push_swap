/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 10:44:44 by alexzudin         #+#    #+#             */
/*   Updated: 2020/10/04 15:54:06 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft.h"
# include <stdlib.h>
# include <stdint.h>
# include <unistd.h>

typedef struct			s_stack
{
	long double		number;
	struct s_stack	*down;
	struct s_stack	*up;
}						t_stack;

t_stack					*rd(char **argv, int argc);
void					c_stack(t_stack *head);
int						endd(t_stack *head_a, t_stack *head_b, int status);
int						parsecommands(t_stack **head_a, t_stack **head_b);
int						strtoint(char *str);
int						execc(char *st, int siz3, t_stack **h_a, t_stack **h_b);
void					rdd(char **argv, int argc, t_stack *head);
int						dupliforhead(t_stack *now);
int						duplicates(t_stack *now);
int						countofelem(t_stack *now);
void					rotate(t_stack *now);
void					addtostack(t_stack **head, int nbr);
void					push(t_stack **head_add, t_stack **head_from);
void					swap(t_stack *head);
void					reverserotate(t_stack *now);
void					exec(t_stack **head_a, t_stack **head_b, int command);
t_stack					*blast(t_stack *now);
int						findbigger(t_stack *now, int number);
void					truee(t_stack *head_a, t_stack *head_b);
void					checkresult(t_stack **head_a, t_stack **head_b);
t_stack					*strf(char *str, int argc, t_stack *now, int i);
t_stack					*addnew(char **argv, int argc, t_stack *now, int i);
t_stack					*addelemdown(t_stack *now);
int						isssort(t_stack	*head_a);
int						fdmax(t_stack *now);
int						fdmin(t_stack *now);
int						fdmid(t_stack *now);
void					solver(t_stack **head_a, t_stack **head_b);
void					leftelem(int mi, int ma, t_stack **h_a, t_stack **h_b);
int						*bubblesort(int count, int *massive);
int						*trnslttomass(int *massive, t_stack *head);
void					output_command(int i);
void					issycle(t_stack *h_a);
int						getindex(t_stack *now);
int						mvtzind(int index, int count);
int						nbrtomv(t_stack *h_a, t_stack *h_b);
t_stack					*findnbr(int nbr, t_stack *h_a);
void					sort(t_stack **h_a, t_stack **h_b);
int						lessmass(int *mass, int count);
void					moverlittle(t_stack **h, int index, int mv, int i);
void					mover(t_stack **h_a, t_stack **h_b, int index);
int						findminin(t_stack *h_a);
int						correctnumb(t_stack *now, int min, int mid, int max);
int						find(int min, int max, t_stack *h_a);
void					ctb(int min, int max, t_stack **h_a, t_stack **h_b);
void					ctbgn(int min, int max, t_stack **h_a, t_stack **h_b);

#endif
