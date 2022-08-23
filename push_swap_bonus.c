/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 02:26:22 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 12:45:47 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

void	srot_ab(size_t ai, size_t bi, \
void (*fa)(t_ps_stack), void (*fb)(t_ps_stack))
{
	void	(*f)(void);

	f = uu;
	if (fa == d)
		f = dd;
	while (fa == fb && ai > 0 && bi > 0)
	{
		f();
		ai--;
		bi--;
	}
	while (ai > 0)
	{
		fa(A);
		ai--;
	}
	while (bi > 0)
	{
		fb(B);
		bi--;
	}
}

void	srot(size_t ai, size_t bi)
{
	void	(*fa)(t_ps_stack);
	void	(*fb)(t_ps_stack);

	if (ai > size(A) || bi > size(B))
		return ;
	fa = u;
	fb = u;
	if (ai > size(A) / 2)
	{
		ai = size(A) - ai;
		fa = d;
	}
	if (bi > size(B) / 2)
	{
		bi = size(B) - bi;
		fb = d;
	}
	srot_ab(ai, bi, fa, fb);
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
	srot(mi[0], mi[1]);
	p(A);
}

void	gsort(void)
{
	int		max;
	int		min;
	size_t	ai;

	if (is_sorted(A))
		return ;
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
	srot(ai, 0);
}
