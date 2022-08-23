/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:08:09 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 12:50:12 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	is_sorted(t_ps_stack stack_name)
{
	t_dlist	*cur_node;

	if (size(stack_name) <= 1)
		return (1);
	cur_node = get_ps_stack(stack_name)->top;
	while (cur_node->front)
	{
		if (cur_node->num > cur_node->front->num)
			return (0);
		cur_node = cur_node->front;
	}
	return (1);
}

void	five_sort(void)
{
	int		max;
	int		min;
	size_t	ai;

	if (is_sorted(A))
		return ;
	max = find_max_element(A);
	min = find_min_element(A);
	while (size(A) > 3)
	{
		while (peek_at(A, 0) == max || peek_at(A, 0) == min)
			u(A);
		p(B);
	}
	three_sort();
	while (size(B) > 0)
		lowest_move();
	ai = 0;
	while (peek_at(A, ai) != min)
		ai++;
	srot(ai, 0);
}
