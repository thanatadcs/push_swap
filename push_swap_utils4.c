/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils4.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:19:03 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 19:54:53 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrr(void)
{
	rra();
	rrb();
	write(1, "rrr\n", 4);
}

size_t	size_a(void)
{
	return (get_stack_ps('a')->size);
}

size_t	size_b(void)
{
	return (get_stack_ps('b')->size);
}

int	peek_at(char c, int i)
{
	t_dlist	*node;

	node = get_node_at(get_stack_ps(c), i);
	if (node == 0)
		return (0);
	return (node->num);
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
