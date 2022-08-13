/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_ops.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:26:21 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/13 18:21:49 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

// Return 1 if successfully, 0 otherwise
int	swap(t_stack *s)
{
	t_dlist *first;
	t_dlist *second;
	t_dlist *third;

	if (s == 0 || s->top == 0 || s->top->front == 0)
		return (0);
	first = s->top;
	second = first->front;
	third = second->front;
	first->front = third;
	first->back = second;
	second->front = first;
	second->back = 0;
	if (third != 0)
		third->back = first;
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
	t_dlist *top_node;
	t_dlist *af_top_node;
	t_dlist *bot_node;

	if (s == 0 || s->top == 0 || s->top->front == 0)
		return (0);
	if (s->top->front->front == 0)
		return (swap(s));
	top_node = s->top;
	bot_node = s->bot;
	af_top_node = s->top->front;
	top_node->front = 0;
	top_node->back = bot_node;
	af_top_node->back = 0;
	s->top = af_top_node;
	s->bot = top_node;	
}

// Return 1 if successfully, 0 otherwise
int	rotate_down(t_stack *s)
{
	t_dlist *top_node;
	t_dlist *bef_bot_node;
	t_dlist *bot_node;

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
