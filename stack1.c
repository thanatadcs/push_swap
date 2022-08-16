/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 04:05:03 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/17 01:30:08 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stack.h"

t_stack	*new_stack(void)
{
	t_stack	*to_return;

	to_return = malloc(sizeof(t_stack));
	if (to_return == 0)
		return (0);
	to_return->top = 0;
	to_return->bot = 0;
	to_return->size = 0;
	return (to_return);
}

// Return new node being push in to stack s, null if error.
int	push(t_stack *s, int n)
{
	t_dlist	*new_node;
	t_dlist	*top_node;

	if (s == 0)
		return (0);
	new_node = malloc(sizeof(t_dlist));
	if (new_node == 0)
		return (0);
	new_node->num = n;
	new_node->front = 0;
	new_node->back = 0;
	if (s->top == 0)
	{
		s->top = new_node;
		s->bot = new_node;
	}
	else
	{
		top_node = s->top;
		new_node->front = top_node;
		top_node->back = new_node;
		s->top = new_node;
	}
	(s->size)++;
	return (1);
}

// Return an interger pop from the stack.
int	pop(t_stack *s)
{
	t_dlist	*pop_node;
	int		to_return;

	if (s == 0 || s->top == 0)
		return (0);
	pop_node = s->top;
	to_return = pop_node->num;
	s->top = s->top->front;
	if (s->top != 0)
		s->top->back = 0;
	else
		s->bot = 0;
	free(pop_node);
	(s->size)--;
	return (to_return);
}

// Return number of node being pop from stack s, -1 if error.
void	pop_all(t_stack *s)
{
	if (s == 0 || s->top == 0)
		return ;
	while (s->top)
		pop(s);
}

int	get_int_at(t_stack *s, size_t position)
{
	size_t	i;
	t_dlist	*cur_node;

	if (s == 0 || s->top == 0)
		return (0);
	i = 0;
	cur_node = s->top;
	while (cur_node->front && i < position)
	{
		cur_node = cur_node->front;
		i++;
	}
	if (i != position)
		return (0);
	return (cur_node->num);
}
