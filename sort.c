/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:43:22 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/12 11:30:22 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_stack *stack, int size, int flag)
{
	if (flag == 0)
		pb(stack);
	else
		pa(stack);
	size--;
	return (size);
}

void	sort_three_elements(t_stack *s)
{
	if (s->a[0] > s->a[1])
	{
		if (s->a[0] < s->a[2])
			sa(s);
		else if (s->a[1] > s->a[2])
		{
			sa(s);
			rra(s);
		}
		else
			ra(s);
	}
	else if (s->a[1] > s->a[2])
	{
		if (s->a[0] < s->a[2])
		{
			sa(s);
			ra(s);
		}
		else
			rra(s);
	}
}

int	sorted_check(int *stack, int size, int flag)
{
	int	i;

	i = 1;
	while (i < size)
	{
		if ((flag == 0 && stack[i - 1] > stack[i])
			|| (flag == 1 && stack[i - 1] < stack[i]))
			return (0);
		i++;
	}
	return (1);
}

int	sort_stack(t_stack *stack, int size)
{
	if (!sorted_check(stack->a, stack->size_a, 0))
	{
		if (size == 2)
			sa(stack);
		else if (size == 3)
			sort_three_elements(stack);
		else
			quick_sort_a(stack, size, 0);
	}
	return (0);
}
