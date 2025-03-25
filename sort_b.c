/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:43:19 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/11 16:36:56 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sorted_b(t_stack *stack, int *size)
{
	while (*size > 0
		|| !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
	{
		if (*size == 1 && stack->a[0] > stack->a[1])
			sa(stack);
		else if (*size == 1 || (*size >= 2 && stack->b[0] > stack->b[1])
			|| (*size == 3 && stack->b[0] > stack->b[2]))
			*size = push_stack(stack, *size, 1);
		else
			sb(stack);
	}
}

static int	sort_b_three_elements(t_stack *stack, int size)
{
	if (size == 1)
		pa(stack);
	else if (size == 2)
	{
		if (stack->b[0] < stack->b[1])
			sb(stack);
		while (size--)
			pa(stack);
	}
	else
		small_sorted_b(stack, &size);
	return (0);
}

int	quick_sort_b(t_stack *stack, int size, int count)
{
	int	pivot;
	int	len;

	if (!count && sorted_check(stack->b, size, 1) == 1)
	{
		while (size--)
			pa(stack);
	}
	if (size <= 3)
		return (sort_b_three_elements(stack, size), 1);
	len = size;
	if (!get_pivot(&pivot, stack->b, size))
		return (0);
	while (size != len / 2)
	{
		if (stack->b[0] >= pivot && size--)
			pa(stack);
		else if (++count)
			rb(stack);
	}
	while (len / 2 != stack->size_b && count--)
		rrb(stack);
	return (quick_sort_a(stack, len / 2 + len % 2, 0)
		&& quick_sort_b(stack, len / 2, 0));
}
