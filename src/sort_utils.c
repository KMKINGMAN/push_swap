#include "../include/push_swap.h"

int get_stack_size(t_stack *stack)
{
    return stack->size;  // Use the size field we're already tracking
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

void sort_large_stack(t_stack *stack_a, t_stack *stack_b)
{
    if (!stack_a || stack_a->size < 2)
        return;
    
    // Find min and max and check if sorted
    t_node *current = stack_a->top;
    t_node *prev = NULL;
    int min = current->value;
    int max = current->value;
    int is_sorted = 1;
    
    while (current)
    {
        if (current->value < min)
            min = current->value;
        if (current->value > max)
            max = current->value;
        if (prev && prev->value > current->value)
            is_sorted = 0;
        prev = current;
        current = current->next;
    }
    
    // If already sorted or single unique number, return
    if (is_sorted || min == max)
        return;
    
    // Normalize numbers (shift to positive range)
    current = stack_a->top;
    while (current)
    {
        current->value = current->value - min;
        current = current->next;
    }
    
    // Calculate max bits needed
    int max_shifted = max - min;
    int max_bits = 0;
    while (max_shifted >> max_bits)
        max_bits++;
    
    // Modified radix sort
    for (int i = 0; i < max_bits; i++)
    {
        int size = stack_a->size;
        for (int j = 0; j < size; j++)
        {
            int num = stack_a->top->value;
            if ((num >> i) & 1)
                ra(stack_a, 1);
            else
                pb(stack_a, stack_b);
        }
        
        while (stack_b->size > 0)
            pa(stack_a, stack_b);
    }
    
    // Restore original values
    current = stack_a->top;
    while (current)
    {
        current->value = current->value + min;
        current = current->next;
    }
}
