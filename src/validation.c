/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/20 14:04:20 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/25 10:32:50 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*strf(char *str, int argc, t_stack *now, int i)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		while (str[j] == ' ')
			j++;
		now->number = ft_atoi(&(str[j]));
		while (str[j] >= '0' && str[j] <= '9')
			j++;
		while (str[j] == ' ')
			j++;
		if (str[j] >= '0' && str[j] <= '9')
			now = addelemdown(now);
		else if (((i + 1) <= argc))
			now = addelemdown(now);
		else
			now->down = NULL;
	}
	return (now);
}

int			duplicates(t_stack *now)
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

int			dupliforhead(t_stack *now)
{
	long long int find;

	find = now->number;
	if (find > 2147483647 || find < -2147483648)
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

int			countofelem(t_stack *now)
{
	int i;

	i = 0;
	while (now != NULL)
	{
		i++;
		now = now->down;
	}
	return (i);
}

t_stack		*blast(t_stack *now)
{
	while (now->down != NULL)
		now = now->down;
	return (now);
}
