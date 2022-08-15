/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:14:34 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 15:26:49 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(void)
{
	rotate_up(get_stack_ps('a'));
	write(1, "ra\n", 3);
}

void	rb(void)
{
	rotate_up(get_stack_ps('b'));
	write(1, "rb\n", 3);
}

void	rr(void)
{
	ra();
	rb();
	write(1, "rr\n", 3);
}

void	rra(void)
{
	rotate_down(get_stack_ps('a'));
	write(1, "rra\n", 4);
}

void	rrb(void)
{
	rotate_down(get_stack_ps('b'));
	write(1, "rrb\n", 4);
}
