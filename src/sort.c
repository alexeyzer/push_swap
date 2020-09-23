/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 17:52:06 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/23 20:22:16 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void issycle(t_stack *h_a)
{
	int a;
	int b;
	int c;

	if (countofelem(h_a) == 3)
	{
		a = h_a->number;
		b = h_a->down->number;
		c = h_a->down->down->number;
		if ((a < b && b > c && c > a) || (a > b && b < c && c > a) || (a > b && b > c && c < a))
		{
			swap(h_a);
			output_command(1);
		}
		
	}
}

int getindex(t_stack *now)
{
	int index;

	index = 0;
	while (now->up != NULL)
	{
		index++;
		now = now->up;
	}
	return (index);
}

void sort(t_stack **h_a, t_stack **h_b)
{
	int index;
	int move;

	index = 0;
	move = 0;
	while(countofelem(*h_b) != 0)
	{
		index = nbrtomv(*h_a, *h_b);
		mover(h_a, h_b, index);
	}
	index = findminin(*h_a);
	move = mvtzind(index, countofelem(*h_a));
	moverlittle(h_a, index, move);
}

int nbrtomv(t_stack *h_a, t_stack *h_b)
{
	int *mass;
	int i;
	t_stack *now;

	i = 0;
	now = h_b;
	mass = (int*)malloc(sizeof(int) * countofelem(h_b));
	while(now != NULL)
	{
		//printf("nbr is %lld count to do =", now->number);
		mass[i] = (mvtzind(getindex(now), countofelem(h_b)) + mvtzind(getindex(findnbr(now->number, h_a)), countofelem(h_a)) + 1);
		//printf("%d\n", mass[i]);
		i++;
		now = now->down;
	}
	return (lessmass(mass, countofelem(h_b)));
}

int mvtzind(int index, int count)
{
	if (index <= (count / 2))
		return (index);
	else
		return (count - index);
}