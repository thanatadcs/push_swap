/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:45:21 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 15:27:50 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(void)
{
	swap(get_stack_ps('a'));
	write(1, "sa\n", 3);
}

void	sb(void)
{
	swap(get_stack_ps('b'));
	write(1, "ss\n", 3);
}

void	ss(void)
{
	sa();
	sb();
	write(1, "ss\n", 3);
}

void	pa(void)
{
	pop_push(get_stack_ps('b'), get_stack_ps('a'));
	write(1, "pa\n", 3);
}

void	pb(void)
{
	pop_push(get_stack_ps('a'), get_stack_ps('b'));
	write(1, "pb\n", 3);
}
