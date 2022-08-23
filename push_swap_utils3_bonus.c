/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 11:14:34 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 14:08:47 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	d(t_ps_stack stack_name)
{
	if (size(stack_name) <= 1)
		return ;
	rotate_down(get_ps_stack(stack_name));
}

void	dd(void)
{
	rotate_down(get_ps_stack(A));
	rotate_down(get_ps_stack(B));
}

size_t	size(t_ps_stack stack_name)
{
	return (get_ps_stack(stack_name)->size);
}

int	peek_at(t_ps_stack stack_name, size_t i)
{
	if (i == size(stack_name) - 1)
		return (get_ps_stack(stack_name)->bot->num);
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
