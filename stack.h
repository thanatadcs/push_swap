/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:26:54 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 01:57:18 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

# include <libft.h>
# include <stdlib.h>

typedef struct s_dlist
{
	int				num;
	struct s_dlist	*front;
	struct s_dlist	*back;
}	t_dlist;

typedef struct s_stack
{
	t_dlist	*top;
	t_dlist	*bot;
	size_t	size;
}	t_stack;

// stack1.c
t_stack	*new_stack(void);
t_dlist	*push(t_stack *s, int n);
int		pop(t_stack *s);
int		pop_all(t_stack *s);
t_dlist	*get_node_at(t_stack *s, size_t position);

// stack2.c
t_stack	*get_stack_strs(char **strs, int n);
int		swap(t_stack *s);
int		pop_push(t_stack *s1, t_stack *s2);
int		rotate_up(t_stack *s);
int		rotate_down(t_stack *s);

#endif
