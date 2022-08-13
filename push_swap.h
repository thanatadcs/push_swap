/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 01:03:21 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/14 01:04:59 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

int	swap(t_stack *s);
int	pop_push(t_stack *s1, t_stack *s2);
int	rotate_up(t_stack *s);
int	rotate_down(t_stack *s);

#endif
