/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:33:43 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/07 18:18:20 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	pop(t_stack *stack)
{
	t_node	*temp;
	int		value;

	if (!stack->top)
		return (0);
	temp = stack->top;
	value = temp->value;
	stack->top = temp->next;
	free(temp);
	stack->size--;
	return (value);
}

void	free_stack(t_stack *stack)
{
	while (stack->top)
		pop(stack);
	free(stack);
}
