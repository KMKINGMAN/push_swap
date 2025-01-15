/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:18:32 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/15 18:44:28 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_stack_size(t_stack *stack)
{
	return (stack->size);
}

static void	sort_two(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a, 1);
}

static int	find_min_pos(t_stack *stack)
{
	t_node	*current;
	int		min;
	int		pos;
	int		min_pos;

	current = stack->top;
	min = current->value;
	pos = 0;
	min_pos = 0;
	while (current)
	{
		if (current->value < min)
		{
			min = current->value;
			min_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (min_pos);
}

void	move_min_to_top(t_stack *stack_a, int size)
{
	int	min_pos;

	min_pos = find_min_pos(stack_a);
	while (min_pos > 0)
	{
		if (min_pos <= size / 2)
			ra(stack_a, 1);
		else
			rra(stack_a, 1);
		min_pos = find_min_pos(stack_a);
	}
}
