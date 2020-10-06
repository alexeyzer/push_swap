/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visual.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 14:22:35 by alexzudin         #+#    #+#             */
/*   Updated: 2020/10/05 16:41:32 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	visualor(t_stack *head_a, t_stack *head_b, char *str)
{
	ft_putstr("Action:");
	ft_putstr(str);
	write(1, "\n", 1);
	ft_putstr("stack A:");
	while (head_a != NULL)
	{
		write(1, " ", 1);
		ft_putnbr(head_a->number);
		head_a = head_a->down;
	}
	write(1, "\n", 1);
	ft_putstr("stack B:");
	while (head_b != NULL)
	{
		write(1, " ", 1);
		ft_putnbr(head_b->number);
		head_b = head_b->down;
	}
	write(1, "\n", 1);
}
