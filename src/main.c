/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:35:13 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 17:31:58 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks if the given string represents a valid number.
 *
 * 
 * This function verifies if the input 
 * string is a valid number. It allows for
 * optional leading '+' or '-' signs. I
 * t also ensures that the string does not
 * contain any non-numeric characters 
 * and does not have leading zeros unless
 * the number is zero itself.
 *
 * @param str The input string to be checked.
 * @return int Returns 1 if the string is a 
 * valid number, otherwise returns 0.
 */
int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] != '\0')
		return (0);
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Sorts the stack using an 
 * appropriate algorithm based on its size.
 *
 * This function determines the size of 
 * the stack and selects the appropriate
 * sorting algorithm to sort the stack. 
 * It uses different algorithms for
 * different stack sizes:
 * - For stacks with 3 or fewer elements, 
 * it uses the `sort_three` function.
 * - For stacks with 4 or 5 elements, 
 * it uses the `sort_five` function.
 * - For stacks with more than 5 elements, 
 * it uses the `sort_large_stack` function.
 *
 * @param stack_a Pointer to the primary stack to be sorted.
 * @param stack_b Pointer to the auxiliary stack used for sorting larger stacks.
 */
void	sort_based_on_size(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = get_stack_size(stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);
}

/**
 * @brief Checks if the stack is 
 * already sorted in ascending order.
 *
 * This function iterates through 
 * the stack and checks if each element is 
 * less than the next element. 
 * If any element is found to be greater than 
 * or equal to the next element, 
 * the function returns 0, indicating that 
 * the stack is not sorted. 
 * If the stack is empty or all elements are in 
 * ascending order, the function returns 1.
 *
 * @param stack A pointer to the stack to be checked.
 * @return int Returns 1 if the stack is 
 * sorted or empty, 0 otherwise.
 */
int	is_already_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value >= current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

/**
 * @brief Allocates memory for two 
 * stacks and checks if the allocation is successful.
 *
 * This function attempts to allocate memory
 *  for two stack structures, `stack_a` and `stack_b`.
 * If either allocation fails, 
 * it frees any successfully allocated stack and returns 0 to indicate failure.
 * If both allocations are successful, 
 * it returns 1.
 *
 * @param stack_a A pointer to a pointer to the first stack.
 * @param stack_b A pointer to a pointer to the second stack.
 * @return int Returns 1 if both stacks are successfully
 *  allocated, otherwise returns 0.
 */
static int	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = create_stack();
	*stack_b = create_stack();
	if (!*stack_a || !*stack_b)
	{
		if (*stack_a)
			free_stack(*stack_a);
		if (*stack_b)
			free_stack(*stack_b);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	if (!init_stacks(&stack_a, &stack_b))
		return (EXIT_FAILURE);
	if (!parse_arguments(argc, argv, stack_a))
		clean_exit(stack_a, stack_b, 1);
	if (!is_already_sorted(stack_a) && stack_a->size > 1)
		sort_based_on_size(stack_a, stack_b);
	clean_exit(stack_a, stack_b, 0);
	return (0);
}
