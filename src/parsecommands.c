/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsecommands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 19:23:00 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/27 14:09:24 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		parsecommands(t_stack **head_a, t_stack **head_b)
{
	char	*str;

	while ((get_next_line(0, &str)) > 0)
	{
		execc(str, ft_strlen(str), head_a, head_b);
		free(str);
	}
	return (0);
}

int		execc(char *str, int size, t_stack **h_a, t_stack **h_b)
{
	int command;

	if (size > 3 || size < 2)
		endd(*h_a, *h_b, 1);
	else
	{
		command = strtoint(str);
		if (command == -1)
			endd(*h_a, *h_b, 1);
		else
			exec(h_a, h_b, command);
	}
	return (0);
}

void	exec2(t_stack **head_a, t_stack **head_b, int command)
{
	if (command == 9)
		reverserotate(*head_a);
	else if (command == 10)
		reverserotate(*head_b);
	else if (command == 11)
	{
		reverserotate(*head_a);
		reverserotate(*head_b);
	}
}

void	exec(t_stack **head_a, t_stack **head_b, int command)
{
	if (command == 1)
		swap(*head_a);
	else if (command == 2)
		swap(*head_b);
	else if (command == 3)
	{
		swap(*head_a);
		swap(*head_b);
	}
	else if (command == 4)
		push(head_a, head_b);
	else if (command == 5)
		push(head_b, head_a);
	else if (command == 6)
		rotate(*head_a);
	else if (command == 7)
		rotate(*head_b);
	else if (command == 8)
	{
		rotate(*head_a);
		rotate(*head_b);
	}
	else
		exec2(head_a, head_b, command);
}

int		strtoint(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	else if (ft_strcmp(str, "sb") == 0)
		return (2);
	else if (ft_strcmp(str, "ss") == 0)
		return (3);
	else if (ft_strcmp(str, "pa") == 0)
		return (4);
	else if (ft_strcmp(str, "pb") == 0)
		return (5);
	else if (ft_strcmp(str, "ra") == 0)
		return (6);
	else if (ft_strcmp(str, "rb") == 0)
		return (7);
	else if (ft_strcmp(str, "rr") == 0)
		return (8);
	else if (ft_strcmp(str, "rra") == 0)
		return (9);
	else if (ft_strcmp(str, "rrb") == 0)
		return (10);
	else if (ft_strcmp(str, "rrr") == 0)
		return (11);
	return (-1);
}
