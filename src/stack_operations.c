/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:33:43 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/15 17:32:34 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

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

void	free_stack(t_stack *stack)
{
	while (stack->top)
		pop(stack);
}
