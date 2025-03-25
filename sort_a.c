/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:43:16 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/11 13:57:53 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	small_sorted_a(t_stack *stack, int *size)
{
	while (*size != 3
		|| !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
	{
		if (*size == 3 && stack->a[0] > stack->a[1] && stack->a[2])
			sa(stack);
		else if (*size == 3
			&& !(stack->a[2] > stack->a[0] && stack->a[2] > stack->a[1]))
			*size = push_stack(stack, *size, 0);
		else if (stack->a[0] > stack->a[1])
			sa(stack);
		else if ((*size)++)
			pa(stack);
	}
}

static void	sort_a_three_elements(t_stack *stack, int size)
{
	if (size == 3 && stack->size_a == 3)
		sort_three_elements(stack);
	else if (size == 2 && stack->a[0] > stack->a[1])
		sa(stack);
	else if (size == 3)
		small_sorted_a(stack, &size);
}

int	quick_sort_a(t_stack *stack, int size, int count)
{
	int	pivot;
	int	len;

	if (sorted_check(stack->a, size, 0))
		return (1);
	len = size;
	if (size <= 3)
		return (sort_a_three_elements(stack, size), 1);
	if (!get_pivot(&pivot, stack->a, size))
		return (0);
	while (size != len / 2 + len % 2)
	{
		if (stack->a[0] < pivot && size--)
			pb(stack);
		else
		{
			ra(stack);
			count++;
		}
	}
	while (len / 2 + len % 2 != stack->size_a && count--)
		rra(stack);
	return (quick_sort_a(stack, len / 2 + len % 2, 0)
		&& quick_sort_b(stack, len / 2, 0));
}
