/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils5.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 10:08:09 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 10:20:52 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
