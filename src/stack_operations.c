/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:33:43 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 17:30:34 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

/**
 * @brief Creates a new stack.
 *
 * This function allocates memory for a 
 * new stack and initializes 
 * its top pointer to NULL
 * and its size to 0. 
 * If memory allocation
 * fails, the program will terminate.
 *
 * @return A pointer to the newly created stack.
 *
 * @example
 * // Example usage:
 * t_stack *my_stack = create_stack();
 * if (my_stack == NULL) {
 *     // Handle error
 * }
 * // Now you can use my_stack to perform
 * // stack operations.
 */
t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)gc_malloc(sizeof(t_stack));
	if (!stack)
		gc_finish_and_exit();
	stack->top = NULL;
	stack->size = 0;
	return (stack);
}

/**
 * @brief Pushes a value onto the stack.
 *
 * This function creates a new node with the
 * given value and pushes 
 * it onto the top of the stack.
 * If memory allocation for
 *  the new node fails,
 * the program will exit.
 *
 * @param stack A pointer to the stack where
 * the value will be pushed.
 * @param value The value to be pushed
 *  onto the stack.
 *
 * @example
 * // Assuming t_stack and t_node are properly 
 * // defined and initialized
 * t_stack *my_stack = initialize_stack();
 * push(my_stack, 10);
 * push(my_stack, 20);
 * push(my_stack, 30);
 * // The stack now looks like this:
 * // Top -> [30] -> [20] -> [10] -> NULL
 */
inline void	push(t_stack *stack, int value)
{
	t_node	*new_node;

	new_node = (t_node *)gc_malloc(sizeof(t_node));
	if (!new_node)
		gc_finish_and_exit();
	new_node->value = value;
	new_node->counter = 0;
	new_node->next = stack->top;
	stack->top = new_node;
	stack->size++;
}

/**
 * @brief Pops the top element from the stack.
 *
 * This function removes the top element from 
 * the stack and returns its value.
 * If the stack is empty, it returns 0.
 *
 * @param stack A pointer to the stack from which
 *  the top element will be popped.
 * @return The value of the popped element. 
 * If the stack is empty, returns 0.
 *
 * @example
 * t_stack *stack = create_stack();
 * push(stack, 10);
 * push(stack, 20);
 * int value = pop(stack); 
 * // value will be 20, stack size will be 1
 * value = pop(stack); 
 * // value will be 10, stack size will be 0
 * value = pop(stack); 
 * // value will be 0, stack is empty
 */
int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack->top)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	stack->size--;
	return (value);
}

/**
 * @brief Frees all elements in the stack 
 * and the stack itself.
 *
 * This function iterates through the stack, 
 * popping each element until the stack is empty.
 * It then removes the stack pointer from 
 * the garbage collector and frees 
 * the stack memory.
 *
 * @param stack A pointer to the stack to be freed.
 *
 * @example
 * // Assume t_stack is a structure representing
 * // a stack and has been properly initialized.
 * t_stack *my_stack = initialize_stack();
 * push(my_stack, 10);
 * push(my_stack, 20);
 * push(my_stack, 30);
 *
 * // Free the stack and all its elements
 * free_stack(my_stack);
 */
void	free_stack(t_stack *stack)
{
	while (stack->top)
		pop(stack);
	gc_remove_pointer(stack);
	free(stack);
}
