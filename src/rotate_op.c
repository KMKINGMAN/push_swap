/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_op.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:30:08 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 18:20:12 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Rotates the stack 'stack_a' upwards
 *  by moving the top element to the bottom.
 *
 * This function performs a rotate operation 
 * on the stack 'stack_a'. The top element
 * of the stack is moved to the bottom of the 
 * stack. If the 'print' parameter is set
 * to a non-zero value, the function will print 
 * "ra" to the standard output.
 *
 * @param stack_a A pointer to the 
 * stack to be rotated.
 * @param print An integer flag to 
 * indicate whether to print the operation ("ra\n").
 *
 * @example
 * // Given a stack 'stack_a' with elements: [1, 2, 3, 4]
 * // After calling ra(stack_a, 1), the stack will be: [2, 3, 4, 1]
 *
 * // Example usage:
 * t_stack *stack_a = create_stack();
 * push(stack_a, 4);
 * push(stack_a, 3);
 * push(stack_a, 2);
 * push(stack_a, 1);
 * ra(stack_a, 1); // Output: "ra"
 * // stack_a now contains: [2, 3, 4, 1]
 */
void	ra(t_stack *stack_a, int print)
{
	t_node	*first;
	t_node	*last;

	if (stack_a->size < 2)
		return ;
	first = stack_a->top;
	last = first;
	while (last->next)
		last = last->next;
	stack_a->top = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "ra\n", 3);
}

/**
 * @brief Rotates the stack_b by shifting all elements up by one.
 *        The first element becomes the last one.
 *
 * This function performs a rotate 
 * operation on the given stack_b.
 * If the stack has fewer than 2 
 * elements, the function returns immediately.
 * Otherwise, it moves the top element 
 * to the bottom of the stack.
 * If the print flag is set, it writes 
 * "rb\n" to the standard output.
 *
 * @param stack_b Pointer to the stack to be rotated.
 * @param print Flag to indicate whether 
 * to print the operation ("rb\n").
 *
 * @example
 * // Before rotation:
 * // stack_b: [1, 2, 3, 4]
 * 
 * rb(stack_b, 1);
 * 
 * // After rotation:
 * // stack_b: [2, 3, 4, 1]
 */
void	rb(t_stack *stack_b, int print)
{
	t_node	*first;
	t_node	*last;

	if (stack_b->size < 2)
		return ;
	first = stack_b->top;
	last = first;
	while (last->next)
		last = last->next;
	stack_b->top = first->next;
	first->next = NULL;
	last->next = first;
	if (print)
		write(1, "rb\n", 3);
}

/**
 * @brief Perform a simultaneous rotation 
 * on both stack_a and stack_b.
 *
 * The function `rr` rotates both `stack_a`
 *  and `stack_b` by one position.
 * This is equivalent to performing the `ra`
 *  and `rb` operations consecutively.
 * After performing the rotations, it writes
 *  "rr\n" to the standard output.
 *
 * @param stack_a Pointer to the first stack (t_stack).
 * @param stack_b Pointer to the second stack (t_stack).
 *
 * Example:
 * Before rr:
 * stack_a: [1, 2, 3, 4]
 * stack_b: [5, 6, 7, 8]
 *
 * After rr:
 * stack_a: [2, 3, 4, 1]
 * stack_b: [6, 7, 8, 5]
 *
 * The function will output:
 * rr
 */
void	rr(t_stack *stack_a, t_stack *stack_b)
{
	ra(stack_a, 0);
	rb(stack_b, 0);
	write(1, "rr\n", 3);
}
