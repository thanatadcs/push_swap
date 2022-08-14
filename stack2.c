/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:26:21 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/14 18:03:01 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*get_stack_strs(char **strs, int n)
{
	int		i;
	t_stack	*to_return;

	if (strs == 0)
		return (0);
	to_return = new_stack();
	if (to_return == 0)
		return (0);
	i = n;
	while (i > 0)
	{
		if (push(to_return, ft_atoi(strs[--i])) == 0)
		{
			pop_all(to_return);
			free(to_return);
			return (0);
		}
	}
	return (to_return);
}

// Return 1 if successfully, 0 otherwise
int	swap(t_stack *s)
{
	t_dlist	*first;
	t_dlist	*second;
	t_dlist	*third;

	if (s == 0 || s->top == 0 || s->top->front == 0)
		return (0);
	first = s->top;
	second = first->front;
	third = second->front;
	first->front = third;
	first->back = second;
	second->front = first;
	second->back = 0;
	s->top = second;
	if (third != 0)
		third->back = first;
	else
		s->bot = first;
	return (1);
}

// Pop from s1 push to s2.
// Return 1 if seccessful, 0 otherwise
int	pop_push(t_stack *s1, t_stack *s2)
{
	int	pop_num;

	if (s1 == 0 || s1->top == 0)
		return (0);
	pop_num = pop(s1);
	if (push(s2, pop_num) == 0)
		return (0);
	return (1);
}

int	rotate_up(t_stack *s)
{
	t_dlist	*top_node;
	t_dlist	*af_top_node;
	t_dlist	*bot_node;

	if (s == 0 || s->top == 0 || s->top->front == 0)
		return (0);
	if (s->top->front->front == 0)
		return (swap(s));
	top_node = s->top;
	bot_node = s->bot;
	af_top_node = s->top->front;
	top_node->front = 0;
	top_node->back = bot_node;
	bot_node->front = top_node;
	af_top_node->back = 0;
	s->top = af_top_node;
	s->bot = top_node;
	return (1);
}

// Return 1 if successfully, 0 otherwise
int	rotate_down(t_stack *s)
{
	t_dlist	*top_node;
	t_dlist	*bef_bot_node;
	t_dlist	*bot_node;

	if (s == 0 || s->top == 0 || s->top->front == 0)
		return (0);
	if (s->top->front->front == 0)
		return (swap(s));
	top_node = s->top;
	bot_node = s->bot;
	bef_bot_node = bot_node->back;
	bot_node->front = top_node;
	bot_node->back = 0;
	bef_bot_node->front = 0;
	top_node->back = bot_node;
	s->top = bot_node;
	s->bot = bef_bot_node;
	return (1);
}
