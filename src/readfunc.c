/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:04:52 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/24 09:07:48 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			isnb(char *a)
{
	int i;
	int p;
	int z;

	i = 0;
	p = 0;
	z = 0;
	while (a[i] != '\0')
	{
		if (a[i] == ' ')
			p++;
		if (ft_isdigit(a[i]) != 0)
			z++;
		if (ft_isdigit(a[i]) == 0 && a[i] != '-' && a[i] != '+' && a[i] != ' ')
			return (-1);
		i++;
	}
	if (z == 0)
		return (-1);
	if (p > 0)
		return (2);
	return (1);
}

t_stack		*rd(char **argv, int argc)
{
	t_stack *head;

	head = (t_stack*)malloc(sizeof(t_stack));
	head->down = NULL;
	head->up = NULL;
	rdd(argv, argc, head);
	if (duplicates(head) == -1)
	{
		endd(head, NULL, 1);
	}
	return (head);
}

int			endd(t_stack *head_a, t_stack *head_b, int status)
{
	if (status == 1)
		ft_putstr_fd("Error\n", 2);
	if (head_a != NULL)
	{
		c_stack(head_a);
		head_a = NULL;
	}
	if (head_b != NULL)
	{
		c_stack(head_b);
		head_b = NULL;
	}
	exit(0);
	return (-1);
}

void		c_stack(t_stack *head)
{
	if (head->down != NULL)
		c_stack(head->down);
	free(head);
}

void		rdd(char **argv, int argc, t_stack *head)
{
	int		i;
	int		a;
	t_stack *now;

	i = 1;
	now = head;
	while (i <= argc)
	{
		a = 0;
		a = isnb(argv[i]);
		if (a == -1)
			endd(head, NULL, 1);
		else if (a == 2)
			now = strf(argv[i], argc, now, i);
		else
			now = addnew(argv, argc, now, i);
		i++;
	}
}
