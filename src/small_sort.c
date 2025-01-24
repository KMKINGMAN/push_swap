/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 18:43:26 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 17:00:32 by mkurkar          ###   ########.fr       */
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

/**
 * @brief Sorts a stack of three elements in ascending order.
 *
 * This function sorts a stack containing exactly three elements. If the stack
 * has fewer than two elements, the function returns immediately. If the stack
 * has exactly two elements, it calls the `sort_two` function to sort them.
 * Otherwise, it retrieves the values of the top three elements and calls the
 * `sort_three_case` function to sort them.
 *
 * @param stack_a A pointer to the stack to be sorted. The stack should contain
 *                at least three elements for this function to perform sorting.
 *
 * @example
 * // Given a stack with elements [3, 1, 2] (top to bottom):
 * t_stack *stack_a = create_stack();
 * push(stack_a, 2);
 * push(stack_a, 1);
 * push(stack_a, 3);
 *
 * sort_three(stack_a);
 *
 * // After sorting, the stack will be [1, 2, 3] (top to bottom).
 */
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

/**
 * @brief Sorts a stack of up to five elements using a secondary stack.
 *
 * This function sorts a stack (stack_a) containing up to five elements by
 * moving the smallest elements to the top and pushing them to a secondary
 * stack (stack_b). Once the main stack has three elements left, it sorts
 * those three elements and then moves the elements from the secondary stack
 * back to the main stack.
 *
 * @param stack_a Pointer to the main stack to be sorted.
 * @param stack_b Pointer to the secondary stack used for sorting.
 *
 * Example:
 * Before sorting:
 * stack_a: [5, 2, 4, 1, 3]
 * stack_b: []
 *
 * After sorting:
 * stack_a: [1, 2, 3, 4, 5]
 * stack_b: []
 */
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
