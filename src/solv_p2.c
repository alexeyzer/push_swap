/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:34:30 by alexzudin         #+#    #+#             */
/*   Updated: 2020/10/05 16:28:13 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find(int min, int max, int mid, t_stack *h_a)
{
	while (h_a != NULL)
	{
		if (correctnumb(h_a, min, mid, max) && h_a->number < mid)
			return (1);
		h_a = h_a->down;
	}
	return (0);
}

void	ctb(int mid, int max, t_stack **h_a, t_stack **h_b)
{
	if (correctnumb(*h_a, fdmin(*h_a), mid, max) &&
		(*h_a)->number < mid)
	{
		push(h_b, h_a);
		output_command(5);
	}
	else if (correctnumb((*h_a)->down, fdmin(*h_a), mid, max) &&
		(*h_a)->down->number < mid)
	{
		rotate(*h_a);
		output_command(6);
	}
	else if (correctnumb(blast(*h_a), fdmin(*h_a), mid, max) &&
		blast(*h_a)->number < mid)
	{
		reverserotate(*h_a);
		output_command(9);
	}
	else
	{
		rotate(*h_a);
		output_command(6);
	}
}

void	ctbgn(int mid, int max, t_stack **h_a, t_stack **h_b)
{
	if (correctnumb(*h_a, fdmin(*h_a), mid, max))
	{
		push(h_b, h_a);
		output_command(5);
	}
	else if (correctnumb((*h_a)->down, fdmin(*h_a), mid, max))
	{
		rotate(*h_a);
		output_command(6);
	}
	else if (correctnumb(blast(*h_a), fdmin(*h_a), mid, max))
	{
		reverserotate(*h_a);
		output_command(9);
	}
	else
	{
		rotate(*h_a);
		output_command(6);
	}
}
