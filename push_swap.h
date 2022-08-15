/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 02:56:36 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 14:38:58 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "stack.h"

// push_swap_util1.c
int	ft_strcmp(char *s1, char *s2);
int is_int(char *s);
int	is_valid(char **strs, int n);

// push_swap_util2.c: push swap operations 1
t_stack	*initialize_ps(char **strs, int n);
t_stack	*get_stack_ps(char c);
void	sa(void);
void	sb(void);
void	ss(void);

// push_swap_util3.c: push swap operations 2
void	pa(void);
void	pb(void);
void	ra(void);
void	rb(void);
void	rr(void);

// push_swap_util4.c: push swap operations 3
void	rra(void);
void	rrb(void);
void	rrr(void);
void	free_ps(void);
#endif

