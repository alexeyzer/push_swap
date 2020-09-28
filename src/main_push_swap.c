/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_push_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 18:38:59 by alexzudin         #+#    #+#             */
/*   Updated: 2020/09/24 09:07:51 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*head_a;
	t_stack		*head_b;

	head_b = NULL;
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
		if (isssort(head_a) == -1)
			solver(&head_a, &head_b);
		endd(head_a, head_b, 0);
	}
	return (0);
}
