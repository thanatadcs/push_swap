/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tanukool <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 02:55:06 by tanukool          #+#    #+#             */
/*   Updated: 2022/08/15 04:11:33 by tanukool         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
