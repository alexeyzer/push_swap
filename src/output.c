/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 11:37:28 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/24 09:07:50 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	output_command(int i)
{
	if (i == 1)
		write(1, "sa\n", 3);
	else if (i == 2)
		write(1, "sb\n", 3);
	else if (i == 3)
		write(1, "ss\n", 3);
	else if (i == 4)
		write(1, "pa\n", 3);
	else if (i == 5)
		write(1, "pb\n", 3);
	else if (i == 6)
		write(1, "ra\n", 3);
	else if (i == 7)
		write(1, "rb\n", 3);
	else if (i == 8)
		write(1, "rr\n", 3);
	else if (i == 9)
		write(1, "rra\n", 4);
	else if (i == 10)
		write(1, "rrb\n", 4);
	else if (i == 10)
		write(1, "rrr\n", 4);
}

int		fdmin(t_stack *now)
{
	int min;

	min = now->number;
	while (now != NULL)
	{
		if (now->number < min)
			min = now->number;
		now = now->down;
	}
	return (min);
}

int		fdmax(t_stack *now)
{
	int max;

	max = now->number;
	while (now != NULL)
	{
		if (now->number > max)
			max = now->number;
		now = now->down;
	}
	return (max);
}

int		isssort(t_stack *head_a)
{
	int number;

	if (head_a != NULL)
	{
		while (head_a != NULL)
		{
			number = (head_a)->number;
			if (findbigger(head_a->down, number) == -1)
				return (-1);
			head_a = head_a->down;
		}
	}
	else
		return (-2);
	return (1);
}

int		fdmid(t_stack *now)
{
	int count;
	int a;
	int *massive;

	count = countofelem(now);
	massive = (int*)malloc(count * sizeof(int));
	massive = trnslttomass(massive, now);
	massive = bubblesort(count, massive);
	a = massive[count / 2 + count % 2];
	free(massive);
	return (a);
}
