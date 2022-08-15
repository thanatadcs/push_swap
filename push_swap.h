/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 02:56:36 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 19:45:33 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include "stack.h"
# include <unistd.h>

// push_swap.c: sorting algorithm
int		bsort(void);
size_t	find_min_index(void);

// push_swap_util1.c: validating input and initializing push swap
int		ft_strcmp(char *s1, char *s2);
int		is_int(char *s);
int		is_valid(char **strs, int n);
t_stack	*initialize_ps(char **strs, int n);
t_stack	*get_stack_ps(char c);

// push_swap_util2.c: push swap operations 1
void	sa(void);
void	sb(void);
void	ss(void);
void	pa(void);
void	pb(void);

// push_swap_util3.c: push swap operations 2
void	ra(void);
void	rb(void);
void	rr(void);
void	rra(void);
void	rrb(void);

// push_swap_util4.c: push swap operations 3
void	rrr(void);
size_t	size_a(void);
size_t	size_b(void);
int		peek_at(char c, int i);
void	free_ps(void);

#endif
