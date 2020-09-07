/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:57:26 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/07 10:37:20 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack		*head_a;
	t_stack		*head_b;
	int			result;

	if (argc == 1)
		return (0);
	if (argc < 1)
	{
		ft_putendl("Error\n");
		return (0);
	}
	else
	{
		head_a = rd(argv, argc - 1);
		result = parsecommands(&head_a, &head_b);
		checkresult(&head_a, &head_b);
	}
	return (0);
}

void checkresult(t_stack **head_a, t_stack **head_b)
{
	if (*head_b != NULL)
	{
		endd(*head_a, *head_b, 0);
		ft_putstr("KO");
	}
	else
		truee(*head_a, *head_b);
	
	
}

void truee(t_stack *head_a, t_stack *head_b)
{
	int number;

	if (head_a != NULL)
	{
		while (head_a != NULL)
		{
			number = (head_a)->number;
			if (findbigger(head_a->down, number) == -1)
			{
				endd(head_a, head_b, 0);
				ft_putstr("KO");
				return ;
			}
			head_a = head_a->down;
		}
		ft_putstr("OK");
		endd(head_a, head_b, 0);
	}
	else
	{
		endd(head_a, head_b, 0);
		ft_putstr("KO");
	}
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