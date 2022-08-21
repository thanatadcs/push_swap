/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:26:22 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/21 20:54:15 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	cost_a(int n)
{
	size_t	ai;

	ai = 0;
	while (ai < size(A) - 1)
	{
		if (n > peek_at(A, ai) && n < peek_at(A, ai + 1))
			return (ai + 1);
		ai++;
	}
	return (0);
}

void	srot(t_ps_stack stack_name, size_t i)
{
	void	(*f)(t_ps_stack);

	if (i > size(stack_name))
		return ;
	f = u;
	if (i > size(stack_name) / 2)
	{
		i = size(stack_name) - i;
		f = d;
	}
	while (i > 0)
	{
		f(stack_name);
		i--;
	}
}

void	lowest_move(void)
{
	size_t	ai;
	size_t	bi;
	size_t	mi[2];
	size_t	min_cost;
	size_t	cost;

	bi = 0;
	min_cost = -1;
	while (bi < size(B))
	{
		ai = cost_a(peek_at(B, bi));
		cost = (ai) * (ai <= size(A) / 2) + \
		(size(A) - ai) * (ai > size(A) / 2) + \
		(bi) * (bi <= size(B) / 2) + (size(B) - bi) * (bi > size(B) / 2);
		if (cost < min_cost)
		{
			min_cost = cost;
			mi[0] = ai;
			mi[1] = bi;
		}
		bi++;
	}
	srot(A, mi[0]);
	srot(B, mi[1]);
	p(A);
}

void	gsort(void)
{
	int		max;
	int		min;
	size_t	ai;

	max = find_max_element(A);
	min = find_min_element(A);
	while (size(A) > 2)
	{
		while (peek_at(A, 0) == max || peek_at(A, 0) == min)
			u(A);
		p(B);
	}
	while (size(B) > 0)
		lowest_move();
	ai = 0;
	while (peek_at(A, ai) != min)
		ai++;
	srot(A, ai);
}
