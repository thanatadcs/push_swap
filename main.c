/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 03:10:26 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 03:10:28 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"
#include "push_swap.h"
#include <unistd.h>

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (!is_valid(++av, ac - 1))
		{
			write(2, "Error\n", 6);
			return (EXIT_FAILURE);
		}
		(void) av;
	}
}
