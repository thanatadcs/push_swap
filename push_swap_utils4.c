/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:19:03 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 14:47:56 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(void)
{
	rotate_down(get_stack_ps('a'));
}

void	rrb(void)
{
	rotate_down(get_stack_ps('b'));
}

void	rrr(void)
{
	rra();
	rrb();
}

void	free_ps(void)
{
	t_stack	*a;
	t_stack	*b;

	a = get_stack_ps('a');
	pop_all(a);
	free(a);
	b = get_stack_ps('b');
	pop_all(b);
	free(b);
}
