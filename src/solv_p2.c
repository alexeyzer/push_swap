/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solv_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/04 15:34:30 by alexzudin         #+#    #+#             */
/*   Updated: 2020/10/04 15:55:18 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		find(int min, int max, t_stack *h_a)
{
	while (h_a != NULL)
	{
		if (correctnumb(h_a, min, fdmid(h_a), max) && h_a->number < fdmid(h_a))
			return (1);
		h_a = h_a->down;
	}
	return (0);
}

void	ctb(int min, int max, t_stack **h_a, t_stack **h_b)
{
	if (correctnumb(*h_a, min, fdmid(*h_a), max) &&
		(*h_a)->number < fdmid(*h_a))
	{
		push(h_b, h_a);
		output_command(5);
	}
	else if (correctnumb((*h_a)->down, min, fdmid(*h_a), max) &&
		(*h_a)->down->number < fdmid(*h_a))
	{
		rotate(*h_a);
		output_command(6);
	}
	else if (correctnumb(blast(*h_a), min, fdmid(*h_a), max) &&
		blast(*h_a)->number < fdmid(*h_a))
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

void	ctbgn(int min, int max, t_stack **h_a, t_stack **h_b)
{
	if (correctnumb(*h_a, min, fdmid(*h_a), max))
	{
		push(h_b, h_a);
		output_command(5);
	}
	else if (correctnumb((*h_a)->down, min, fdmid(*h_a), max))
	{
		rotate(*h_a);
		output_command(6);
	}
	else if (correctnumb(blast(*h_a), min, fdmid(*h_a), max))
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
