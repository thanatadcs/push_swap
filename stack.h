/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/12 16:26:54 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/13 05:04:20 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_H
# define STACK_H

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
}	t_stack;

t_stack	*new_stack(void);
t_dlist	*push(t_stack *s, int n);
int		pop(t_stack *s);
int		pop_all(t_stack *s);

#endif
