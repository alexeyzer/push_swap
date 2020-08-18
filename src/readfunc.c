/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfunc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 14:04:52 by alexzudin         #+#    #+#             */
/*   Updated: 2020/08/18 19:54:03 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int isnb(char *a)
{
	int i;

	i = 0;
	while(a[i] != '\0')
	{
		if (ft_isdigit(a[i]) == 0)
			return (-1);
		i++;
	}
	return (1);
}

t_stack *rd(char **argv, int argc)
{
	int i;
	t_stack *head;
	t_stack *now;

	i = 1;
	head = (t_stack*)malloc(sizeof(t_stack));
	now = head;
	while (i <= argc)
	{
		if (isnb(argv[i]) < 0)
			endd(head, NULL);
		now->number = ft_atoi(argv[i]);
		if ((i + 1) <= argc)
		{
			now->down = (t_stack*)malloc(sizeof(t_stack));
			now = now->down;
		}
		i++;
	}
	return (head);
}

int endd(t_stack *head_a, t_stack *head_b)
{
	ft_putendl("Error\n");
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
	return (-1);
}

void c_stack(t_stack *head)
{
	if (head->down != NULL)
		c_stack(head->down);
	free(head);
}