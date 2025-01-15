/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:34:16 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/15 17:31:38 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ss(t_stack *stack_a, t_stack *stack_b)
{
	sa(stack_a, 0);
	sb(stack_b, 0);
	write(1, "ss\n", 3);
}

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
