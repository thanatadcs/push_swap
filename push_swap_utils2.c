/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 10:45:21 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 14:47:32 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Have to be called before using push swap operations
t_stack	*initialize_ps(char **strs, int n)
{
	static t_stack	*a;

	if (a == 0)
	{
		a = get_stack_strs(strs, n);
		if (a == 0)
			return (0);
	}
	return (a);
}

t_stack	*get_stack_ps(char c)
{
	static t_stack	*a;
	static t_stack	*b;

	if (c == 'a')
	{
		if (a == 0)
		{
			a = initialize_ps(0, 0);
			if (a == 0)
				return (0);
		}
		return (a);
	}
	else if (c == 'b')
	{
		if (b == 0)
		{
			b = new_stack();
			if (b == 0)
				return (0);
		}
		return (b);
	}
	return (0);
}

void	sa(void)
{
	swap(get_stack_ps('a'));
}

void	sb(void)
{
	swap(get_stack_ps('b'));
}

void	ss(void)
{
	sa();
	sb();
}
