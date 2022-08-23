/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 13:08:40 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 14:12:23 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"
#include "get_next_line.h"
#include "ft_printf.h"

int	do_ops(char *line)
{
	if (ft_strcmp("sa\n", line) == 0)
		s(A);
	else if (ft_strcmp("sb\n", line) == 0)
		s(B);
	else if (ft_strcmp("ss\n", line) == 0)
		ss();
	else if (ft_strcmp("pa\n", line) == 0)
		p(A);
	else if (ft_strcmp("pb\n", line) == 0)
		p(B);
	else if (ft_strcmp("ra\n", line) == 0)
		u(A);
	else if (ft_strcmp("rb\n", line) == 0)
		u(B);
	else if (ft_strcmp("rr\n", line) == 0)
		uu();
	else if (ft_strcmp("rra\n", line) == 0)
		d(A);
	else if (ft_strcmp("rrb\n", line) == 0)
		d(B);
	else if (ft_strcmp("rrr\n", line) == 0)
		dd();
	else
		return (0);
	return (1);
}

void	check_push_swap(void)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		check_ps_error(do_ops(line));
		free(line);
		line = get_next_line(0);
	}
	if (size(B) == 0 && is_sorted(A))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
}
