/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 15:18:32 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/07 16:38:55 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int get_stack_size(t_stack *stack)
{
    return stack->size;
}

void sort_three(t_stack *stack_a)
{
    if (!stack_a || stack_a->size < 2)
        return;
    
    if (stack_a->size == 2)
    {
        if (stack_a->top->value > stack_a->top->next->value)
            sa(stack_a, 1);
        return;
    }

    int first = stack_a->top->value;
    int second = stack_a->top->next->value;
    int third = stack_a->top->next->next->value;

    if (first > second && second < third && first < third)
        sa(stack_a, 1);
    else if (first > second && second > third)
    {
        sa(stack_a, 1);
        rra(stack_a, 1);
    }
    else if (first > second && second < third && first > third)
        ra(stack_a, 1);
    else if (first < second && second > third && first < third)
    {
        sa(stack_a, 1);
        ra(stack_a, 1);
    }
    else if (first < second && second > third && first > third)
        rra(stack_a, 1);
}

static int find_min_position(t_stack *stack)
{
    t_node *current = stack->top;
    int min = current->value;
    int pos = 0;
    int min_pos = 0;
    
    while (current)
    {
        if (current->value < min)
        {
            min = current->value;
            min_pos = pos;
        }
        pos++;
        current = current->next;
    }
    return min_pos;
}

void sort_five(t_stack *stack_a, t_stack *stack_b)
{
    int size = get_stack_size(stack_a);
    
    // Push 2 minimum numbers to stack_b
    while (get_stack_size(stack_a) > 3)
    {
        int min_pos = find_min_position(stack_a);
        
        while (min_pos > 0)
        {
            if (min_pos <= size / 2)
                ra(stack_a, 1);
            else
                rra(stack_a, 1);
            min_pos = find_min_position(stack_a);
        }
        pb(stack_a, stack_b);
    }
    
    // Sort remaining 3 numbers
    sort_three(stack_a);
    
    // Push back from stack_b
    while (get_stack_size(stack_b) > 0)
        pa(stack_a, stack_b);
}

static void assign_counters(t_stack *stack)
{
    t_node *current = stack->top;
    t_node *compare;
    
    while (current)
    {
        current->counter = 0;
        compare = stack->top;
        while (compare)
        {
            if (current->value > compare->value)
                current->counter++;
            compare = compare->next;
        }
        current = current->next;
    }
}

void sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || stack_a->size < 2)
        return;
    
    // Check if already sorted
    t_node *current = stack_a->top;
    int is_sorted = 1;
    
    while (current && current->next)
    {
        if (current->value > current->next->value)
        {
            is_sorted = 0;
            break;
        }
        current = current->next;
    }
    
    if (is_sorted)
        return;
    
    // Assign counters based on position in sorted sequence
    assign_counters(stack_a);
    
    // Calculate max bits needed (now based on stack size - 1)
    int max_bits = 0;
    int max_num = stack_a->size - 1;
    while (max_num >> max_bits)
        max_bits++;
    
    // Radix sort using counters
    for (int i = 0; i < max_bits; i++)
    {
        int size = stack_a->size;
        for (int j = 0; j < size; j++)
        {
            if ((stack_a->top->counter >> i) & 1)
                ra(stack_a, 1);
            else
                pb(stack_a, stack_b);
        }
        
        while (stack_b->size > 0)
            pa(stack_a, stack_b);
    }
}
