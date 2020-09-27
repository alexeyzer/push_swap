/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfunc_p2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 08:49:41 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/27 13:11:49 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*addnew(char **argv, int argc, t_stack *now, int i)
{
	now->number = ft_atoi(argv[i]);
	if ((i + 1) <= argc)
		now = addelemdown(now);
	else
		now->down = NULL;
	return (now);
}

t_stack		*addelemdown(t_stack *now)
{
	now->down = (t_stack*)malloc(sizeof(t_stack));
	now->down->up = now;
	now = now->down;
	return (now);
}

int			correctnumb(t_stack *now, int min, int mid, int max)
{
	if (now->number != min && now->number != max && now->number != mid)
		return (1);
	return (0);
}
