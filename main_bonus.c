/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:35:18 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 13:36:22 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "checker_bonus.h"

int	main(int ac, char **av)
{
	if (ac >= 2)
	{
		if (!is_valid(++av, ac - 1) || initialize_ps(av, ac - 1) == 0)
		{
			write(2, "Error\n", 6);
			return (EXIT_FAILURE);
		}
		check_push_swap();
		free_ps();
	}
}
