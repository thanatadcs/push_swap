/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 14:57:48 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/16 00:02:20 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>
#include <stdio.h>

size_t	find_min_index(void)
{
	int		min;
	int		n;
	size_t	min_index;
	size_t	i;

	min = INT_MAX;
	i = 0;
	while (i < size_a())
	{
		n = peek_at('a', i);
		if (n < min)
		{
			min = n;
			min_index = i;
		}
		i++;
	}
	return (min_index);
}

int	bsort(void)
{
	size_t	min_index;
	size_t	initial_size_a;

	if (size_a() <= 1)
		return (1);
	initial_size_a = size_a();
	while (size_b() < initial_size_a)
	{
		min_index = find_min_index();
		while (min_index)
		{
			ra();
			min_index--;
		}
		pb();
	}
	while (size_b() > 0)
		pa();
	return (1);
}
