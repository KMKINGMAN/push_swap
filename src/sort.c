/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:34:43 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/26 21:22:53 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Helper function to check if stack is sorted
static inline int is_sorted(t_stack *stack)
{
    t_node *current = stack->top;
    while (current && current->next)
    {
        if (current->value > current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

// Find the smallest number in stack
int find_min(t_stack *stack)
{
    t_node *current = stack->top;
    int min = current->value;
    
    while (current)
    {
        if (current->value < min)
            min = current->value;
        current = current->next;
    }
    return min;
}

// Find the largest number in stack
int find_max(t_stack *stack)
{
    t_node *current = stack->top;
    int max = current->value;
    
    while (current)
    {
        if (current->value > max)
            max = current->value;
        current = current->next;
    }
    return max;
}

// Get position of a number in stack
int get_position(t_stack *stack, int num)
{
    t_node *current = stack->top;
    int pos = 0;
    
    while (current)
    {
        if (current->value == num)
            return pos;
        pos++;
        current = current->next;
    }
    return -1;
}

static void sort_three_nodes(t_stack *stack)
{
    int a = stack->top->value;
    int b = stack->top->next->value;
    int c = stack->top->next->next->value;
    
    if (a > b && b < c && a < c)
        sa(stack, 1);
    else if (a > b && b > c)
    {
        sa(stack, 1);
        ra(stack, 1);
    }
    else if (a > b && b < c && a > c)
        ra(stack, 1);
    else if (a < b && b > c && a < c)
    {
        sa(stack, 1);
        ra(stack, 1);
    }
    else if (a < b && b > c)
        rra(stack, 1);
}

static void quick_sort(t_stack *stack_a, t_stack *stack_b, int len)
{
    if (len <= 3)
    {
        sort_three_nodes(stack_a);
        return;
    }

    int pivot = stack_a->top->value;
    int pushed = 0;

    for (int i = 0; i < len && pushed < len / 2; i++)
    {
        if (stack_a->top->value < pivot)
        {
            pb(stack_a, stack_b);
            pushed++;
        }
        else
            ra(stack_a, 1);
    }

    quick_sort(stack_a, stack_b, len - pushed);
    quick_sort(stack_b, stack_a, pushed);
}

void sort_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (is_sorted(stack_a))
        return;
        
    if (stack_a->size <= 3)
        sort_three_nodes(stack_a);
    else
        quick_sort(stack_a, stack_b, stack_a->size);
}
