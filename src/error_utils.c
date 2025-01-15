/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:29:35 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/15 17:29:36 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	handle_error(t_stack *stack_a, t_stack *stack_b)
{
	clean_exit(stack_a, stack_b, 1);
	return (0);
}
