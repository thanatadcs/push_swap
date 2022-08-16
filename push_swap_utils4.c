/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:38:43 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/17 03:53:17 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_ps_error(int is_success)
{
	if (!is_success)
	{
		write(2, "Error\n", 6);
		free_ps();
		exit(EXIT_FAILURE);
	}
}

void	print_op(char *op_str, t_ps_stack stack_name)
{
	char	*stack_str;

	stack_str = 0;
	if (stack_name == A)
		stack_str = "a";
	else if (stack_name == B)
		stack_str = "b";
	ft_printf("%s%s\n", op_str, stack_str);
}
