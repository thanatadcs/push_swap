/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:45:21 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/17 03:56:59 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_ps_stack stack_name)
{
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
		to_return = pop_push(get_ps_stack(B), get_ps_stack(A));
	else
		to_return = pop_push(get_ps_stack(A), get_ps_stack(B));
	print_op("p", stack_name);
	return (to_return);
}

void	u(t_ps_stack stack_name)
{
	rotate_up(get_ps_stack(stack_name));
	print_op("r", stack_name);
}

void	uu(void)
{
	u(A);
	u(B);
	ft_printf("rr\n");
}
