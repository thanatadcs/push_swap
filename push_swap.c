/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:26:22 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/20 16:13:16 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	find_min_index(t_ps_stack stack_name)
{
	int		min;
	int		n;
	size_t	min_index;
	size_t	i;

	min = INT_MAX;
	i = 0;
	while (i < size(stack_name))
	{
		n = peek_at(stack_name, i);
		if (n < min)
		{
			min = n;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

void	simple_sort(void)
{
	size_t		min_index;
	size_t		initial_size_a;
	t_ps_stack	a;
	t_ps_stack	b;

	a = A;
	b = B;
	if (size(a) <= 1)
		return ;
	initial_size_a = size(a);
	while (size(b) < initial_size_a)
	{
		min_index = find_min_index(a);
		while (min_index)
		{
			u(a);
			min_index--;
		}
		check_ps_error(p(b));
	}
	while (size(b) > 0)
		check_ps_error(p(a));
	return ;
}
