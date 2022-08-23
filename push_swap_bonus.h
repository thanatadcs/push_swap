/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 02:56:36 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 12:45:18 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include <limits.h>
# include <unistd.h>
# include "ft_printf.h"
# include "libft.h"
# include "stack.h"

typedef enum e_ps_stack {A, B}	t_ps_stack;

// push_swap.c: sorting algorithm
void	gsort(void);
size_t	cost_a(int n);
void	srot_ab(size_t ai, size_t bi, \
void (*fa)(t_ps_stack), void (*fb)(t_ps_stack));
void	srot(size_t ai, size_t bi);
void	lowest_move(void);

// push_swap_util1.c: validating input and initializing push swap
int		ft_strcmp(char *s1, char *s2);
int		is_int(char *s);
int		is_valid(char **strs, int n);
t_stack	*initialize_ps(char **strs, int n);
t_stack	*get_ps_stack(t_ps_stack stack_name);

// push_swap_util2.c: push swap operations 1
void	s(t_ps_stack stack_name);
void	ss(void);
void	p(t_ps_stack stack_name);
void	u(t_ps_stack stack_name);
void	uu(void);

// push_swap_util3.c: push swap operations 2
void	d(t_ps_stack stack_name);
void	dd(void);
size_t	size(t_ps_stack stack_name);
int		peek_at(t_ps_stack stack_name, size_t i);
void	free_ps(void);

// push_swap_util4.c: sorting utility and miscellaneous
int		find_min_element(t_ps_stack stack_name);
int		find_max_element(t_ps_stack stack_name);
void	check_ps_error(int is_success);
void	print_op(char *op_str, t_ps_stack stack_name);
void	three_sort(void);

// push_swap_util5.c: additional utility for optimization
int		is_sorted(t_ps_stack stack_name);
void	five_sort(void);

#endif
