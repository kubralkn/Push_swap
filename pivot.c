/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:43:00 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/11 12:10:27 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static void	sort_for_pivot(int *tmp_stack, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tmp_stack[i] > tmp_stack[j])
			{
				tmp = tmp_stack[i];
				tmp_stack[i] = tmp_stack[j];
				tmp_stack[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int	get_pivot(int *pivot, int *stack, int size)
{
	int	i;
	int	*tmp;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return (0);
	i = 0;
	while (i < size)
	{
		tmp[i] = stack[i];
		i++;
	}
	sort_for_pivot(tmp, size);
	*pivot = tmp[size / 2];
	free(tmp);
	return (1);
}
