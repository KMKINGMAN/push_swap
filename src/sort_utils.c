/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:18:32 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 17:26:45 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Get the size of the stack.
 *
 * This function returns the number of 
 * elements currently in the stack.
 *
 * @param stack A pointer to the stack 
 * whose size is to be determined.
 * @return The size of the stack.
 *
 * @example
 * t_stack *my_stack = create_stack();
 * push(my_stack, 10);
 * push(my_stack, 20);
 * int size = get_stack_size(my_stack);
 * // size now equals 2
 */
/**
 * @brief get the size of the stack
 */
int	get_stack_size(t_stack *stack)
{
	return (stack->size);
}

/**
 * @brief Sorts the top two elements of 
 * the given stack in ascending order.
 *
 * This function checks if the stack has at 
 * least two elements. If the top element
 * is greater than the next element, 
 * it swaps them to sort the top two elements.
 *
 * @param stack_a A pointer to the stack to be sorted.
 *
 * @example
 * // Given a stack with the following
 * // elements (top to bottom):
 * // [3, 1]
 * // After calling sort_two(stack_a),
 * //the stack will be:
 * // [1, 3]
 *
 * // Given a stack with the following 
 * // elements (top to bottom):
 * // [1, 2]
 * // After calling sort_two(stack_a),
 * //the stack will remain:
 * // [1, 2]
 */
void	sort_two(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return ;
	if (stack_a->top->value > stack_a->top->next->value)
		sa(stack_a, 1);
}

/**
 * @brief Finds the position of the 
 * minimum value in a stack.
 *
 * This function iterates through the 
 * stack and determines the position
 * of the node with the smallest value. 
 * The position is zero-based, meaning
 * the top of the stack is position 0.
 *
 * @param stack A pointer to the stack structure.
 * @return The position of the node with the minimum value.
 *
 * @example
 * // Given a stack with the following values (top to bottom):
 * // 3 -> 1 -> 4 -> 2
 * // The function will return 1, 
 * because the minimum value (1) is at position 1.
 *
 * t_stack *stack = create_stack();
 * push(stack, 3);
 * push(stack, 1);
 * push(stack, 4);
 * push(stack, 2);
 * int min_pos = find_min_pos(stack);
 * printf("The position of the minimum value is: %d\n"
 * , min_pos); // Output: 1
 */
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

/**
 * @brief Moves the minimum element in the stack to the top.
 *
 * This function finds the position of 
 * the minimum element in the stack and 
 * rotates the stack until the minimum 
 * element is at the top. It uses the 
 * `ra` (rotate up) and `rra` (rotate down) 
 * operations to achieve this.
 *
 * @param stack_a A pointer to the stack where
 *  the minimum element will be moved to the top.
 * @param size The size of the stack.
 *
 * @example
 * // Given a stack: [3, 5, 1, 4, 2]
 * // After calling move_min_to_top(stack_a, 5):
 * // The stack becomes: [1, 3, 5, 4, 2]
 */
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
