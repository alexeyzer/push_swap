/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alexzudin <alexzudin@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/18 12:57:26 by alexzudin         #+#    #+#             */
/*   Updated: 2020/08/18 19:22:10 by alexzudin        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
	t_stack		*head;
	int			commands;

	if (argc <= 1)
	{
		ft_putendl("Error\n");
		return (0);
	}
	else
	{
		head = rd(argv, argc - 1);
		
	}
	return (0);
}