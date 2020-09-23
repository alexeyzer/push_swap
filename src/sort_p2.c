/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_p2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:32:20 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/23 21:18:38 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *findnbr(int nbr, t_stack *h_a)
{
	t_stack * tail;

	tail = becomelast(h_a);
	if (h_a->number > nbr)
	{
		if (h_a->up != NULL)
		{
			if (h_a->up->number < nbr)
				return(h_a);
			else
				return(findnbr(nbr, h_a->up));
		}
		else
		{
			if (tail->number < nbr)
				return(h_a);
			else
				return(findnbr(nbr, tail));
		}
	}
	else
		return(findnbr(nbr, h_a->down));
}

int lessmass(int *mass, int count)
{
	int i;
	int nbr;

	i = 0;
	nbr = mass[0];
	while (i < count)
	{
		if (mass[i] < nbr)
			nbr = mass[i];
			i++;
	}
	i = 0;
	while(i < count)
	{
		if (mass[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}

void mover(t_stack **h_a, t_stack **h_b, int index)
{
	t_stack *now;
	int moveb;
	int movea;
	int index_a;

	now = *h_b;
	while (index > 0)
	{
		now = now->down;
		index--;
	}
	index_a = getindex(findnbr(now->number, *h_a));
	moveb = mvtzind(getindex(now), countofelem(*h_b));
	movea =  mvtzind(index_a, countofelem(*h_a));
	moverlittle(h_b, getindex(now), moveb, 1);
	moverlittle(h_a, index_a, movea, 2);
	push(h_a, h_b);
	output_command(4);
}

void moverlittle(t_stack **head, int index, int movement, int i)
{
	if (index <= countofelem(*head) / 2)
	{
		while(movement != 0)
		{
			rotate(*head);
			if (i == 2)
				output_command(6);
			else
				output_command(7);
			movement--;
		}
	}
	else
	{
		while(movement != 0)
		{
			reverserotate(*head);
			if (i == 2)
				output_command(9);
			else
				output_command(10);
			movement--;
		}
	}
}

int findminin(t_stack *h_a)
{
	t_stack *now;
	int a;
	int i;

	now = h_a;
	i = 0;
	a = now->number;
	while (now != NULL)
	{
		if (now->number < a)
			a = now->number;
		now = now->down;
	}
	while (h_a != NULL)
	{
		if (h_a->number == a)
			return (i);
		i++;
		h_a = h_a->down;
	}
	return (-1);
}