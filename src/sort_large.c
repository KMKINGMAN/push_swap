/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:18:12 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/07 18:18:12 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

static void	assign_index(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;
	int		pos;

	current = stack->top;
	while (current)
	{
		pos = 0;
		temp = stack->top;
		while (temp)
		{
			if (current->value > temp->value)
				pos++;
			temp = temp->next;
		}
		current->counter = pos;
		current = current->next;
	}
}

static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

static void	radix_sort_bit(t_stack *stack_a, t_stack *stack_b, int bit)
{
	int	size;
	int	i;
	int	num;

	size = stack_a->size;
	i = 0;
	while (i < size)
	{
		num = stack_a->top->counter;
		if ((num >> bit) & 1)
			ra(stack_a, 1);
		else
			pb(stack_a, stack_b);
		i++;
	}
}

void	sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;

	if (!stack_a || stack_a->size < 2)
		return ;
	assign_index(stack_a);
	max_bits = get_max_bits(stack_a->size);
	i = 0;
	while (i < max_bits)
	{
		radix_sort_bit(stack_a, stack_b, i);
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
