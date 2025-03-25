/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:42:56 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/11 12:11:34 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>
#include <unistd.h>

void	data_free(char **data)
{
	int	i;

	i = -1;
	while (data[++i])
		free(data[i]);
	free(data);
}

void	print_error(t_stack *stack, char **av, t_free *cnt)
{
	if (cnt->flag)
		data_free(av);
	if (stack->a)
		free (stack->a);
	if (stack->b)
		free (stack->b);
	write (2, "Error\n", 6);
	exit (1);
}
