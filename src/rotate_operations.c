/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:40:12 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 17:25:35 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * rra - Reverse rotate stack A.
 * 
 * This function performs a reverse rotation
 *  on stack A, which means that the 
 * last element of the stack becomes the first
 *  one. If the `print` parameter 
 * is set to a non-zero value, the function
 *  will also print "rra" to the 
 * standard output.
 * 
 * @param stack_a A pointer to the stack A 
 * structure.
 * @param print An integer flag to indicate 
 * whether to print the operation.
 * 
 * Example:
 * Before rra:
 * stack_a: [1, 2, 3, 4, 5]
 * 
 * After rra:
 * stack_a: [5, 1, 2, 3, 4]
 * 
 * If print is non-zero, the output will be:
 * rra
 */
void	rra(t_stack *stack_a, int print)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack_a || !stack_a->top || !stack_a->top->next)
		return ;
	last = stack_a->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack_a->top;
	stack_a->top = last;
	second_last->next = NULL;
	if (print)
		write(1, "rra\n", 4);
}

/**
 * @brief Reverses the rotation of stack_b 
 * by moving the last element to the top.
 *
 * This function performs a reverse rotation 
 * on the given stack_b. It moves the
 * last element of the stack to the top. 
 * If the stack is empty or has only one
 * element, the function does nothing. 
 * If the print flag is set, it prints "rrb"
 * to the standard output.
 *
 * @param stack_b A pointer to the stack 
 * (t_stack) to be rotated.
 * @param print An integer flag indicating 
 * whether to print the operation ("rrb\n").
 *
 * @example
 * // Given stack_b: 1 -> 2 -> 3 -> 4
 * rrb(stack_b, 1);
 * // Resulting stack_b: 4 -> 1 -> 2 -> 3
 *
 * @note The function assumes that the stack 
 * is implemented as a linked list
 * where the top of the stack is the head of the list.
 */
void	rrb(t_stack *stack_b, int print)
{
	t_node	*last;
	t_node	*second_last;

	if (!stack_b || !stack_b->top || !stack_b->top->next)
		return ;
	last = stack_b->top;
	second_last = NULL;
	while (last->next)
	{
		second_last = last;
		last = last->next;
	}
	last->next = stack_b->top;
	stack_b->top = last;
	second_last->next = NULL;
	if (print)
		write(1, "rrb\n", 4);
}

/**
 * @brief Perform a reverse rotate
 * operation on both stack_a and stack_b.
 *
 * The function `rrr` performs a reverse 
 * rotate operation on two stacks, `stack_a` and `stack_b`.
 * This operation involves moving the bottom 
 * element of each stack to the top.
 * The function also writes "rrr\n" to the 
 * standard output to indicate the operation.
 *
 * @param stack_a A pointer to the first stack (t_stack).
 * @param stack_b A pointer to the second stack (t_stack).
 *
 * @example
 * // Before rrr operation:
 * // stack_a: [1, 2, 3, 4]
 * // stack_b: [5, 6, 7, 8]
 * 
 * rrr(stack_a, stack_b);
 * 
 * // After rrr operation:
 * // stack_a: [4, 1, 2, 3]
 * // stack_b: [8, 5, 6, 7]
 */
void	rrr(t_stack *stack_a, t_stack *stack_b)
{
	rra(stack_a, 0);
	rrb(stack_b, 0);
	write(1, "rrr\n", 4);
}
