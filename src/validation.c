/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:04:20 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/03 09:39:19 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int duplicates(t_stack *now)
{
	int result;

	result = 0;
	while (now != NULL)
	{
		result = dupliforhead(now);
		if (result == -1)
			return (-1);
		now = now->down;
	}
	return (1);
}

int dupliforhead(t_stack *now)
{
	long long int find;
	find = now->number;
	if (find > 2147483647 || find < -2147483647)
		return (-1);
	now = now->down;
	while (now != NULL)
	{
		if (now->number == find)
			return (-1);
		now = now->down;
	}
	return (1);
}

int countofelem(t_stack *now)
{
	int i;

	i = 0;
	while(now != NULL)
	{
		i++;
		now = now->down;
	}
	return (i);
}

t_stack *becomelast(t_stack *now)
{
	while(now->down != NULL)
		now = now->down;
	return (now);
}

