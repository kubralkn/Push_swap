/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kalkan <kalkan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 11:43:12 by kalkan            #+#    #+#             */
/*   Updated: 2025/03/12 12:16:03 by kalkan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct s_free
{
	int		flag;
}	t_free;

typedef struct s_stack
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_stack;

char	**ft_split(char const *s, char c);

void	data_free(char **data);
void	print_error(t_stack *stack, char **av, t_free *data);
void	repeat_check(int size, t_stack *stack, char **av, t_free *cnt);
void	sort_three_elements(t_stack *s);
void	sa(t_stack *stack);
void	ra(t_stack *stack);
void	rra(t_stack *stack);
void	pa(t_stack *stack);
void	sb(t_stack	*stack);
void	rb(t_stack	*stack);
void	rrb(t_stack *stack);
void	pb(t_stack *stack);
void	av_space_error(char *str);

int		av_len(char **av);
int		av_space_control(char *str, t_stack *stack, char **av, t_free *cnt);
int		ps_atoi(char *str, t_stack *stack, char **av, t_free *cnt);
int		sorted_check(int *stack, int size, int flag);
int		sort_stack(t_stack *stack, int size);
int		quick_sort_a(t_stack *stack, int size, int count);
int		quick_sort_b(t_stack *stack, int size, int count);
int		get_pivot(int *pivot, int *stack, int size);
int		push_stack(t_stack *stack, int size, int flag);

#endif
