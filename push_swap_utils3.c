/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:14:34 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/17 03:57:44 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	d(t_ps_stack stack_name)
{
	rotate_down(get_ps_stack(stack_name));
	print_op("rr", stack_name);
}

void	dd(void)
{
	d(A);
	d(B);
	ft_printf("rrr\n");
}

size_t	size(t_ps_stack stack_name)
{
	return (get_ps_stack(stack_name)->size);
}

int	peek_at(t_ps_stack stack_name, size_t i)
{
	return (get_int_at(get_ps_stack(stack_name), i));
}

void	free_ps(void)
{
	t_stack	*a;
	t_stack	*b;

	a = get_ps_stack(A);
	pop_all(a);
	free(a);
	b = get_ps_stack(B);
	pop_all(b);
	free(b);
}
