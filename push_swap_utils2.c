/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:45:21 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/19 19:16:40 by tanukool         ###   ########.fr       */
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
	s(A);
	s(B);
	ft_printf("ss\n");
}

int	p(t_ps_stack stack_name)
{
	int	to_return;

	if (stack_name == A)
	{
		if (size(B) == 0)
			return (1);
		to_return = pop_push(get_ps_stack(B), get_ps_stack(A));
	}
	else
	{
		if (size(A) == 0)
			return (1);
		to_return = pop_push(get_ps_stack(A), get_ps_stack(B));
	}
	print_op("p", stack_name);
	return (to_return);
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
	u(A);
	u(B);
	ft_printf("rr\n");
}
