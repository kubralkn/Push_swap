/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:42:43 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/12 12:18:06 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	init_stack(t_stack *stack, int size)
{
	stack->a = malloc(sizeof(int) * size);
	if (!stack->a)
		return (0);
	stack->size_a = size;
	stack->b = malloc(sizeof(int) * size);
	if (!stack->b)
	{
		free(stack->a);
		return (0);
	}
	stack->size_b = 0;
	return (1);
}

static void	fill_stack(t_stack *stack, char **av, t_free *cnt)
{
	int	i;
	int	j;

	i = -1;
	while (++i < stack->size_a)
	{
		j = av_space_control(av[i], stack, av, cnt);
		if (j == 1)
			stack->a[i] = ps_atoi(av[i], stack, av, cnt);
	}
}

static void	push_swap(char **av, t_free *cnt)
{
	t_stack	stack;
	int		size;

	size = av_len(av);
	if (!init_stack(&stack, size))
		return ;
	fill_stack(&stack, av, cnt);
	repeat_check(size, &stack, av, cnt);
	sort_stack(&stack, size);
	free(stack.a);
	free(stack.b);
}

int	main(int ac, char **av)
{
	t_free	freesplit;
	char	**data;

	data = NULL;
	freesplit.flag = 0;
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			freesplit.flag = 1;
			av_space_error(*av);
			data = ft_split(*av, ' ');
			if (data)
				push_swap(data, &freesplit);
		}
		else
			push_swap(av, &freesplit);
	}
	if (data)
		data_free(data);
	return (0);
}
