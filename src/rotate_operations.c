/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:40:12 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/27 15:18:24 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"



void rr(t_stack *stack_a, t_stack *stack_b)
{
    ra(stack_a, 0);
    rb(stack_b, 0);
    write(1, "rr\n", 3);
}

void rra(t_stack *stack_a, int print)
{
    if (!stack_a || !stack_a->top || !stack_a->top->next)
        return;
    
    t_node *last = stack_a->top;
    t_node *second_last = NULL;
    
    // Find the last and second last nodes
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    
    // Make last node the first node
    last->next = stack_a->top;
    stack_a->top = last;
    second_last->next = NULL;
    
    if (print)
        write(1, "rra\n", 4);
}

void rrb(t_stack *stack_b, int print)
{
    if (!stack_b || !stack_b->top || !stack_b->top->next)
        return;
    
    t_node *last = stack_b->top;
    t_node *second_last = NULL;
    
    while (last->next)
    {
        second_last = last;
        last = last->next;
    }
    
    last->next = stack_b->top;
    stack_b->top = last;
    second_last->next = NULL;
    
    if (print)
        write(1, "rrb\n", 4);
}

void rrr(t_stack *stack_a, t_stack *stack_b)
{
    rra(stack_a, 0);
    rrb(stack_b, 0);
    write(1, "rrr\n", 4);
}
