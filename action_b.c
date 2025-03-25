/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:42:52 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/11 12:07:47 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <unistd.h>

void	sb(t_stack	*stack)
{
	int	tmp;

	tmp = 0;
	if (stack->size_b < 2)
		return ;
	tmp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = tmp;
	write(1, "sb\n", 3);
}

void	rb(t_stack	*stack)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = tmp;
	write(1, "rb\n", 3);
}

void	rrb(t_stack *stack)
{
	int	tmp;
	int	i;

	i = stack->size_b - 1;
	tmp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = tmp;
	write(1, "rrb\n", 4);
}

void	pb(t_stack *stack)
{
	int	i;

	i = 0;
	if (stack->size_a)
	{
		stack->size_b++;
		i = stack->size_b;
		while (--i > 0)
			stack->b[i] = stack->b[i -1];
		stack->b[0] = stack->a[0];
		i = -1;
		stack->size_a--;
		while (++i < stack->size_a)
			stack->a[i] = stack->a[i + 1];
		write(1, "pb\n", 3);
	}
	else
		return ;
}
