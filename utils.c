/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:43:27 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/12 12:17:11 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>
#include <stdlib.h>

void	repeat_check(int size, t_stack *stack, char **av, t_free *cnt)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size)
	{
		while (j < size)
		{
			if (stack->a[i] == stack->a[j])
				print_error(stack, av, cnt);
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	ps_atoi(char *str, t_stack *stack, char **av, t_free *cnt)
{
	unsigned int		i;
	int					sgn;
	unsigned long int	res;

	i = 0;
	res = 0;
	sgn = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sgn = -1;
		i++;
	}
	if ((str[i] == '-' || str[i] == '+') || !(str[i] >= '0' && str[i] <= '9'))
		print_error(stack, av, cnt);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - '0');
		if ((res > 2147483647 && sgn == 1) || (res > 2147483648 && sgn == -1))
			print_error(stack, av, cnt);
		i++;
	}
	return (res * sgn);
}

int	av_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	av_space_control(char *str, t_stack *stack, char **av, t_free *cnt)
{
	int	i;

	i = 0;
	while ((str[i] && str[i] == 32)
		|| ((str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!str[i])
		print_error(stack, av, cnt);
	return (1);
}

void	av_space_error(char *str)
{
	int	i;

	i = 0;
	while ((str[i] && str[i] == 32)
		|| ((str[i] >= 9 && str[i] <= 13)))
		i++;
	if (!str[i] && i > 0)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
}
