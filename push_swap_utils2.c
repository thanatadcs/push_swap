/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:45:21 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/17 02:29:24 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_ps_stack stack_name)
{
	swap(get_ps_stack(stack_name));
}

void	ss(void)
{
	s(A);
	s(B);
}

int	p(t_ps_stack stack_name)
{
	if (stack_name == A)
		return (pop_push(get_ps_stack(B), get_ps_stack(A)));
	return (pop_push(get_ps_stack(A), get_ps_stack(B)));
}

void	u(t_ps_stack stack_name)
{
	rotate_up(get_ps_stack(stack_name));
}

void	uu(void)
{
	u(A);
	u(B);
}
