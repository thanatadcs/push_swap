/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:14:34 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 14:46:47 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(void)
{
	pop_push(get_stack_ps('b'), get_stack_ps('a'));
}

void	pb(void)
{
	pop_push(get_stack_ps('a'), get_stack_ps('b'));
}

void	ra(void)
{
	rotate_up(get_stack_ps('a'));
}

void	rb(void)
{
	rotate_up(get_stack_ps('b'));
}

void	rr(void)
{
	ra();
	rb();
}
