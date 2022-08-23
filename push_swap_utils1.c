/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 02:55:06 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/23 00:44:07 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	if (s1 == 0 || s2 == 0)
		return (0);
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

int	is_int(char *s)
{
	int	i;

	if (s == 0 || *s == '\0' || (*s == '-' && *(s + 1) == '\0'))
		return (0);
	i = (*s == '-');
	while (s[i])
	{
		if (s[i] < '0' || s[i] > '9')
			return (0);
		i++;
	}
	i -= (*s == '-');
	if (i > 10)
		return (0);
	if (i < 10)
		return (1);
	else if (*s == '-' && ft_strcmp(s, "-2147483648") > 0)
		return (0);
	else if (ft_strcmp(s, "2147483647") > 0)
		return (0);
	return (1);
}

int	is_valid(char **strs, int n)
{
	int	i;
	int	j;

	if (strs == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		if (!is_int(strs[i]))
			return (0);
		j = 0;
		while (j < n)
		{
			if (j != i && ft_strcmp(strs[i], strs[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// Have to be called before using push swap operations
t_stack	*initialize_ps(char **strs, int n)
{
	static t_stack	*a;
	t_ps_stack		snb;

	snb = B;
	if (get_ps_stack(snb) == 0)
		check_ps_error(0);
	if (a == 0)
	{
		a = get_stack_strs(strs, n);
		if (a == 0)
			check_ps_error(0);
	}
	return (a);
}

t_stack	*get_ps_stack(t_ps_stack stack_name)
{
	static t_stack	*a;
	static t_stack	*b;

	if (stack_name == A)
	{
		if (a == 0)
		{
			a = initialize_ps(0, 0);
			if (a == 0)
				return (0);
		}
		return (a);
	}
	else if (stack_name == B)
	{
		if (b == 0)
		{
			b = new_stack();
			if (b == 0)
				return (0);
		}
		return (b);
	}
	return (0);
}
