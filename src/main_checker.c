/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:57:26 by alexzudin         #+#    #+#             */
/*   Updated: 2020/10/06 09:42:12 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*head_a;
	t_stack		*head_b;
	int			result;
	int			vizual;

	vizual = 0;
	if (argc == 1)
		return (0);
	if (argc < 1)
		ft_putendl("Error\n");
	else
	{
		if (argv[1][0] == '-' && argv[1][1] == 'v')
		{
			vizual = 1;
			if (argc == 2)
				return (0);
		}
		head_a = rd(argv, argc - 1, vizual);
		result = parsecommands(&head_a, &head_b, vizual);
		checkresult(&head_a, &head_b);
	}
	return (0);
}

void	checkresult(t_stack **head_a, t_stack **head_b)
{
	if (*head_b != NULL)
	{
		ft_putstr("KO\n");
		endd(*head_a, *head_b, 0);
	}
	else
		truee(*head_a, *head_b);
}

void	truee(t_stack *head_a, t_stack *head_b)
{
	int number;

	if (head_a != NULL)
	{
		while (head_a != NULL)
		{
			number = (head_a)->number;
			if (findbigger(head_a->down, number) == -1)
			{
				ft_putstr("KO\n");
				endd(head_a, head_b, 0);
				return ;
			}
			head_a = head_a->down;
		}
		ft_putstr("OK\n");
		endd(head_a, head_b, 0);
	}
	else
	{
		endd(head_a, head_b, 0);
		ft_putstr("KO\n");
	}
}

int		findbigger(t_stack *now, int number)
{
	while (now != NULL)
	{
		if (now->number < number)
			return (-1);
		now = now->down;
	}
	return (0);
}
