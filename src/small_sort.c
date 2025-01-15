/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:43:26 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/15 18:44:35 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_case(t_stack *stack_a, int first, int second, int third)
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
