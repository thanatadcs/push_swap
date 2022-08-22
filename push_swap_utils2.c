/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:45:21 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 00:21:57 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_ps_stack stack_name)
{
	if (size(stack_name) <= 1)
		return ;
	swap(get_ps_stack(stack_name));
	print_op("s", stack_name);
}

void	ss(void)
{
	swap(get_ps_stack(A));
	swap(get_ps_stack(B));
	ft_printf("ss\n");
}

void	p(t_ps_stack stack_name)
{
	int	is_success;

	if (stack_name == A)
	{
		if (size(B) == 0)
			return ;
		is_success = pop_push(get_ps_stack(B), get_ps_stack(A));
	}
	else
	{
		if (size(A) == 0)
			return ;
		is_success = pop_push(get_ps_stack(A), get_ps_stack(B));
	}
	check_ps_error(is_success);
	print_op("p", stack_name);
}

void	u(t_ps_stack stack_name)
{
	if (size(stack_name) <= 1)
		return ;
	rotate_up(get_ps_stack(stack_name));
	print_op("r", stack_name);
}

void	uu(void)
{
	rotate_up(get_ps_stack(A));
	rotate_up(get_ps_stack(B));
	ft_printf("rr\n");
}
