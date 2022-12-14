/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:10:26 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 11:04:25 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (!is_valid(++av, ac - 1) || initialize_ps(av, ac - 1) == 0)
		{
			write(2, "Error\n", 6);
			return (EXIT_FAILURE);
		}
		if (ac - 1 == 3)
			three_sort();
		else if (ac - 1 == 5)
			five_sort();
		else
			gsort();
		free_ps();
	}
}
