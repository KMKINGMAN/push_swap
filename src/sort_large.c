/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 18:18:12 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/27 21:54:53 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Assigns an index to each node 
 * in the stack based on its value.
 *
 * This function iterates through each 
 * node in the stack and assigns an index
 * (counter) to each node. 
 * The index is determined by the number of nodes with
 * a smaller value than the current node.
 *
 * @param stack A pointer to the stack 
 * structure containing the nodes.
 *
 * @example
 * // Given a stack with the following values:
 * // top -> [3] -> [1] -> [4] -> [2]
 * //
 * // After calling assign_index(stack), the stack will be:
 * // top -> [3, counter=2] -> [1, counter=0]
 * // -> [4, counter=3] -> [2, counter=1]
 *
 * // Explanation:
 * // - Node with value 3 has 2 nodes 
 * // with smaller values (1 and 2), so counter = 2.
 * // - Node with value 1 has 0 nodes 
 * // with smaller values, so counter = 0.
 * // - Node with value 4 has 3 nodes 
 * // with smaller values (3, 1, and 2), so counter = 3.
 * // - Node with value 2 has 1 node with a smaller
 * /// value (1), so counter = 1.
 */
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

/**
 * @brief Calculates the number of bits required to 
 * represent the given size.
 *
 * This function determines the number of bits needed 
 * to represent the given size
 * by continuously right-shifting the size until it 
 * becomes zero, counting the number
 * of shifts performed.
 *
 * @param size The size to be represented in bits.
 * @return The number of bits required to represent 
 * the given size.
 *
 * @example
 * // Example usage:
 * int size = 16;
 * int max_bits = get_max_bits(size);
 * // max_bits will be 4, because 16 in binary is 10000, 
 * // which requires 4 bits.
 */
static int	get_max_bits(int size)
{
	int	max_bits;

	max_bits = 0;
	while ((size - 1) >> max_bits)
		max_bits++;
	return (max_bits);
}

/**
 * @brief Performs a radix sort on the given stack using 
 * the specified bit.
 *
 * This function sorts the elements in stack_a by 
 * examining the specified bit
 * of each element's counter. Elements with a 1 in 
 * the specified bit position
 * are rotated to the bottom of stack_a,
 * while elements with a 0 are pushed
 * to stack_b.
 *
 * @param stack_a Pointer to the stack 
 * to be sorted.
 * @param stack_b Pointer to the auxiliary 
 * stack used for sorting.
 * @param bit The bit position to be used
 *  for sorting (0-based index).
 *
 * @example
 * // Given stack_a with elements having counters: [5, 3, 8, 6]
 * // and stack_b initially empty:
 * // bit = 0 (least significant bit)
 * // Iteration 1: 
 * stack_a = [3, 8, 6], stack_b = [5]
 * // Iteration 2: 
 * stack_a = [8, 6], stack_b = [5, 3]
 * // Iteration 3: 
 * stack_a = [6], stack_b = [5, 3, 8]
 * // Iteration 4: 
 * stack_a = [], stack_b = [5, 3, 8, 6]
 * // After the function call, 
 * stack_a will be empty and stack_b will contain
 * // the elements sorted based on the specified bit.
 */
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

/**
 * @brief Gets the maximum index value in the stack.
 * 
 * @param stack A pointer to the stack structure.
 * @return The maximum index value in the stack.
 */
int	get_max_index(t_stack *stack)
{
	t_node	*current;
	int		max;

	current = stack->top;
	max = 0;
	while (current)
	{
		if (current->counter > max)
			max = current->counter;
		current = current->next;
	}
	return (max);
}

/**
 * @brief Sorts the stack using the radix sort algorithm.
 *
 * This function sorts the elements in
 *  stack_a using the radix sort algorithm.
 * It utilizes stack_b as an auxiliary
 *  stack during the sorting process.
 * The function first assigns an index
 *  to each element in stack_a, then
 * determines the maximum number of bits
 *  required to represent the largest
 * index. It iterates through each bit
 *  position, performing a radix sort
 * based on the current bit, and moves
 *  elements back from stack_b to stack_a
 * after sorting by each bit.
 *
 * @param stack_a Pointer to the primary 
 * stack to be sorted.
 * @param stack_b Pointer to the auxiliary
 *  stack used during sorting.
 *
 * @example
 * // Given stack_a with elements: [3, 6, 9, 1, 4]
 * // stack_b is initially empty: []
 * 
 * // After calling sort_large_stack(stack_a, stack_b):
 * // stack_a will be sorted: [1, 3, 4, 6, 9]
 * // stack_b will be empty: []
 */
void	sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
	int	max_bits;
	int	i;

	if (!stack_a || stack_a->size < 2)
		return ;
	assign_index(stack_a);
	max_bits = get_max_bits(get_max_index(stack_a));
	i = 0;
	while (i < max_bits)
	{
		radix_sort_bit(stack_a, stack_b, i);
		while (stack_b->size > 0)
			pa(stack_a, stack_b);
		i++;
	}
}
