/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 18:01:02 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/24 09:08:05 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack *head)
{
	int	swap;

	if (head != NULL && head->down != NULL)
	{
		swap = head->number;
		head->number = head->down->number;
		head->down->number = swap;
	}
}

void	push(t_stack **head_add, t_stack **head_from)
{
	t_stack *now;
	int		nubmer;

	if (*head_from != NULL)
	{
		if ((*head_from)->down != NULL)
		{
			nubmer = (*head_from)->number;
			now = *head_from;
			*head_from = (*head_from)->down;
			(*head_from)->up = NULL;
			free(now);
			addtostack(head_add, nubmer);
		}
		else
		{
			nubmer = (*head_from)->number;
			free(*head_from);
			*head_from = NULL;
			addtostack(head_add, nubmer);
		}
	}
}

void	addtostack(t_stack **head, int nbr)
{
	t_stack *new_head;

	new_head = (t_stack*)malloc(sizeof(t_stack));
	new_head->number = nbr;
	if (*head != NULL)
	{
		new_head->down = *head;
		(*head)->up = new_head;
		*head = new_head;
		(*head)->up = NULL;
	}
	else
	{
		*head = new_head;
		(*head)->down = NULL;
		(*head)->up = NULL;
	}
}

void	rotate(t_stack *now)
{
	int wait;
	int	count;

	count = countofelem(now);
	if (now != NULL)
	{
		if (count > 2)
		{
			wait = now->number;
			while (now->down != NULL)
			{
				now->number = now->down->number;
				now = now->down;
			}
			now->number = wait;
		}
		else if (count == 2)
			swap(now);
	}
}

void	reverserotate(t_stack *now)
{
	int wait;
	int	count;

	count = countofelem(now);
	if (now != NULL)
	{
		if (count > 2)
		{
			now = blast(now);
			wait = now->number;
			while (now->up != NULL)
			{
				now->number = now->up->number;
				now = now->up;
			}
			now->number = wait;
		}
		else if (count == 2)
			swap(now);
	}
}
