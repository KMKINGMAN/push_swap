/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:18:32 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/07 17:07:38 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

static void	sort_three_case(t_stack *stack_a, int first, int second, int third)
{
	if (first > second && second < third && first < third)
		sa(stack_a, 1);
	else if (first > second && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (first > second && second < third && first > third)
		ra(stack_a, 1);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first < second && second > third && first > third)
		rra(stack_a, 1);
}

void	sort_three(t_stack *stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->size == 2)
		return (sort_two(stack_a));
	first = stack_a->top->value;
	second = stack_a->top->next->value;
	third = stack_a->top->next->next->value;
	sort_three_case(stack_a, first, second, third);
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

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = get_stack_size(stack_a);
	while (get_stack_size(stack_a) > 3)
	{
		move_min_to_top(stack_a, size);
		pb(stack_a, stack_b);
	}
	sort_three(stack_a);
	while (get_stack_size(stack_b) > 0)
		pa(stack_a, stack_b);
}
