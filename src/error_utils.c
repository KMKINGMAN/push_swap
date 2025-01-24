/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:29:35 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 18:19:29 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Cleans up the stacks and exits the program.
 *
 * This function is used to clean up the 
 * allocated memory for the stacks and 
 * exit the program with the specified
 *  error code. If an error is indicated, 
 * it writes "Error\n" to the standard
 *  error output before exiting.
 *
 * @param stack_a Pointer to the first stack (t_stack).
 * @param stack_b Pointer to the second stack (t_stack).
 * @param error Integer error code to exit with.
 *  If non-zero, an error message 
 *  is printed to the standard error output.
 */
void	clean_exit(t_stack *stack_a, t_stack *stack_b, int error)
{
	if (error)
		write(2, "Error\n", 6);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	exit(error);
}

/**
 * @brief Handles errors by cleaning up
 *  and exiting the program.
 *
 * This function is responsible for handling
 *  errors that occur during the
 * execution of the program. It performs 
 * necessary cleanup operations on the
 * provided stacks and then exits the program 
 * with a specified exit code.
 *
 * @param stack_a A pointer to the first stack 
 * (stack_a) that needs to be cleaned up.
 * @param stack_b A pointer to the second stack 
 * (stack_b) that needs to be cleaned up.
 * @return Always returns 0.
 */
int	handle_error(t_stack *stack_a, t_stack *stack_b)
{
	clean_exit(stack_a, stack_b, 1);
	return (0);
}
