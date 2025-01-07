/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:34:16 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/07 16:38:53 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

// Stack management operations
t_stack *create_stack(void)
{
    t_stack *stack = (t_stack *)malloc(sizeof(t_stack));
    if (!stack)
        return NULL;
    stack->top = NULL;
    stack->size = 0;
    return stack;
}

inline void push(t_stack *stack, int value)
{
    t_node *new_node = (t_node *)malloc(sizeof(t_node));
    if (!new_node)
        return;
    new_node->value = value;
    new_node->counter = 0;  // Initialize counter
    new_node->next = stack->top;
    stack->top = new_node;
    stack->size++;
}

void sa(t_stack *stack_a, int print)
{
    if (stack_a->size < 2)
        return;
    int temp = stack_a->top->value;
    stack_a->top->value = stack_a->top->next->value;
    stack_a->top->next->value = temp;
    if (print)
        write(1, "sa\n", 3);
}

void sb(t_stack *stack_b, int print)
{
    if (stack_b->size < 2)
        return;
    int temp = stack_b->top->value;
    stack_b->top->value = stack_b->top->next->value;
    stack_b->top->next->value = temp;
    if (print)
        write(1, "sb\n", 3);
}

void ss(t_stack *stack_a, t_stack *stack_b)
{
    sa(stack_a, 0);
    sb(stack_b, 0);
    write(1, "ss\n", 3);
}

void ra(t_stack *stack_a, int print)
{
    if (stack_a->size < 2)
        return;
    t_node *first = stack_a->top;
    t_node *last = first;
    while (last->next)
        last = last->next;
    stack_a->top = first->next;
    first->next = NULL;
    last->next = first;
    if (print)
        write(1, "ra\n", 3);
}

void rb(t_stack *stack_b, int print)
{
    if (stack_b->size < 2)
        return;
    t_node *first = stack_b->top;
    t_node *last = first;
    while (last->next)
        last = last->next;
    stack_b->top = first->next;
    first->next = NULL;
    last->next = first;
    if (print)
        write(1, "rb\n", 3);
}

// Optimized push operations
void pa(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_b->top)
        return;
    t_node *temp = stack_b->top;
    stack_b->top = temp->next;
    temp->next = stack_a->top;
    stack_a->top = temp;
    stack_a->size++;
    stack_b->size--;
    write(1, "pa\n", 3);
}

void pb(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a->top)
        return;
    t_node *temp = stack_a->top;
    stack_a->top = temp->next;
    temp->next = stack_b->top;
    stack_b->top = temp;
    stack_b->size++;
    stack_a->size--;
    write(1, "pb\n", 3);
}
