/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 03:38:43 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/21 20:51:46 by tanukool         ###   ########.fr       */
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

int	find_max_element(t_ps_stack stack_name)
{
	int		max;
	int		n;
	size_t	i;

	max = INT_MIN;
	i = 0;
	while (i < size(stack_name))
	{
		n = peek_at(stack_name, i);
		if (n > max)
			max = n;
		i++;
	}
	return (max);
}

int	find_min_element(t_ps_stack stack_name)
{
	int		min;
	int		n;
	size_t	i;

	min = INT_MAX;
	i = 0;
	while (i < size(stack_name))
	{
		n = peek_at(stack_name, i);
		if (n < min)
			min = n;
		i++;
	}
	return (min);
}
