/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:34:16 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 17:22:11 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Swaps the first two elements at
 * the top of stack_a.
 *
 * This function swaps the values of the
 * first two elements in the stack_a.
 * If the stack has fewer than two elements,
 *  the function does nothing.
 * If the print flag is set, the function
 *  writes "sa\n" to the standard output.
 *
 * @param stack_a A pointer to the stack
 * (t_stack) where the swap will occur.
 * @param print An integer flag to determine
 *  if the operation should be printed (1 to print, 0 otherwise).
 *
 * @example
 * // Given a stack_a with the following
 *  elements (top to bottom):
 * // [3, 2, 1]
 * sa(stack_a, 1);
 * // After calling sa, the stack_a will be:
 * // [2, 3, 1]
 * // And "sa\n" will be printed to the standard output.
 */
void	sa(t_stack *stack_a, int print)
{
	int	temp;

	if (stack_a->size < 2)
		return ;
	temp = stack_a->top->value;
	stack_a->top->value = stack_a->top->next->value;
	stack_a->top->next->value = temp;
	if (print)
		write(1, "sa\n", 3);
}

/**
 * @brief Swaps the top two elements of stack_b.
 *
 * This function swaps the values of the top two
 * elements of the given stack_b.
 * If the stack has fewer than two elements, the
 * function does nothing.
 * If the print flag is set, the function writes
 * "sb\n" to the standard output.
 *
 * @param stack_b A pointer to the stack_b structure.
 * @param print An integer flag to indicate whether
 *  to print the operation.
 *
 * @example
 * // Given a stack_b with the following
 * elements (top to bottom):
 * // 5 -> 3 -> 2 -> 1
 * t_stack *stack_b = create_stack();
 * push(stack_b, 5);
 * push(stack_b, 3);
 * push(stack_b, 2);
 * push(stack_b, 1);
 *
 * // Call the sb function
 * sb(stack_b, 1);
 *
 * // After calling sb, the stack_b will be:
 * // 3 -> 5 -> 2 -> 1
 * // And "sb\n" will be printed to the
 * // standard output.
 */
void	sb(t_stack *stack_b, int print)
{
	int	temp;

	if (stack_b->size < 2)
		return ;
	temp = stack_b->top->value;
	stack_b->top->value = stack_b->top->next->value;
	stack_b->top->next->value = temp;
	if (print)
		write(1, "sb\n", 3);
}

/**
 * @brief Performs the 'ss' operation on two stacks.
 *
 * The 'ss' operation swaps the first two elements
 * of both stack_a and stack_b.
 * This function calls the 'sa' and 'sb' functions
 * to perform the swaps and
 * then writes "ss\n" to the standard output.
 *
 * @param stack_a Pointer to the first stack (t_stack).
 * @param stack_b Pointer to the second stack (t_stack).
 *
 * @example
 * // Before ss operation:
 * // stack_a: [3, 2, 1]
 * // stack_b: [6, 5, 4]
 *
 * ss(stack_a, stack_b);
 *
 * // After ss operation:
 * // stack_a: [2, 3, 1]
 * // stack_b: [5, 6, 4]
 */
void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}

/**
 * @brief Pushes the top element from stack_b to stack_a.
 *
 * This function takes the top element from stack_b
 *  and pushes it onto stack_a.
 * If stack_b is empty, the function does nothing.
 *
 * @param stack_a Pointer to the destination stack (stack_a).
 * @param stack_b Pointer to the source stack (stack_b).
 *
 * @example
 * // Before calling pa:
 * // stack_a: top -> [3] -> [2] -> [1]
 * // stack_b: top -> [6] -> [5] -> [4]
 *
 * pa(stack_a, stack_b);
 *
 * // After calling pa:
 * // stack_a: top -> [6] -> [3] -> [2] -> [1]
 * // stack_b: top -> [5] -> [4]
 */
void	pa(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_b->top)
		return ;
	temp = stack_b->top;
	stack_b->top = temp->next;
	temp->next = stack_a->top;
	stack_a->top = temp;
	stack_a->size++;
	stack_b->size--;
	write(1, "pa\n", 3);
}

/**
 * @brief Pushes the top element from
 *  stack_a to stack_b.
 *
 * This function removes the top element 
 * from stack_a
 *  and pushes it onto the top of stack_b.
 * If stack_a is empty, the function does nothing.
 *
 * @param stack_a A pointer to the source 
 * stack (stack_a).
 * @param stack_b A pointer to the destination
 *  stack (stack_b).
 *
 * Example:
 * Before pb:
 * stack_a: [3, 2, 1]
 * stack_b: [6, 5, 4]
 *
 * After pb:
 * stack_a: [2, 1]
 * stack_b: [3, 6, 5, 4]
 *
 * The top element (3) from stack_a is moved to the top of stack_b.
 *

 * The function also writes "pb\n" to the standard output to indicate
 *	 the operation performed.
 */
void	pb(t_stack *stack_a, t_stack *stack_b)
{
	t_node	*temp;

	if (!stack_a->top)
		return ;
	temp = stack_a->top;
	stack_a->top = temp->next;
	temp->next = stack_b->top;
	stack_b->top = temp;
	stack_b->size++;
	stack_a->size--;
	write(1, "pb\n", 3);
}
