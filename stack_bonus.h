/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:26:54 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 12:51:35 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_BONUS_H
# define STACK_BONUS_H

# include <stdlib.h>
# include "libft.h"

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

// stack1.c: basic stack operations
t_stack	*new_stack(void);
int		push(t_stack *s, int n);
int		pop(t_stack *s);
void	pop_all(t_stack *s);
int		get_int_at(t_stack *s, size_t position);

// stack2.c: additional operations for push swap operations
t_stack	*get_stack_strs(char **strs, int n);
void	swap(t_stack *s);
int		pop_push(t_stack *s1, t_stack *s2);
void	rotate_up(t_stack *s);
void	rotate_down(t_stack *s);

#endif
