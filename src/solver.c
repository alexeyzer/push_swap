/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 14:31:00 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/23 19:52:11 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void solver(t_stack **h_a, t_stack **h_b)
{
	if (countofelem(*h_a) > 3)
		leftelem(fdmin(*h_a), fdmax(*h_a), fdmid(*h_a), h_a, h_b);
	issycle(*h_a);
	sort(h_a, h_b);
}

void leftelem(int min, int max, int mid, t_stack **head_a, t_stack **head_b)
{
	while (countofelem(*head_a) > 3)
	{
		if ((*head_a)->number != min && (*head_a)->number != max && (*head_a)->number != mid)
		{
			push(head_b,head_a);
			output_command(5);
		}
		else if ((*head_a)->down->number != min && (*head_a)->down->number != max && (*head_a)->down->number != mid)
		{
			rotate(*head_a);
			output_command(6);
		}
		else if (becomelast(*head_a)->number != min && becomelast(*head_a)->number != max && becomelast(*head_a)->number != mid)
		{
			reverserotate(*head_a);
			output_command(9);
		}
		else
		{
			rotate(*head_a);
			output_command(6);
		}
	}
}

int *bubblesort(int count, int *massive)
{
	int i;
	int j;
	int perenos;

	i = 0;
	j = 0;
	perenos = 0;
	while(i < count)
	{
		j = 0;
		while(j < count)
		{
			if (massive[i] < massive[j])
			{
				perenos = massive[i];
				massive[i] = massive[j];
				massive[j] = perenos;
			}
			j++;
		}
		i++;
	}
	return (massive);
}

int *trnslttomass(int *massive, t_stack *head)
{
	int nbr;
	int i;

	i = 0;
	while (head != NULL)
	{
		nbr = head->number;
		massive[i] = nbr;
		i++;
		head = head->down;
	}
	return (massive);
}

int findbigger(t_stack *now, int number)
{
	while (now != NULL)
	{
		if (now->number < number)
			return (-1);
			now = now->down;
	}
	return (0);
}