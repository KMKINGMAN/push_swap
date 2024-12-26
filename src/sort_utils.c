#include "push_swap.h"

int get_stack_size(t_stack *stack)
{
    int count = 0;
    t_node *current = stack->top;
    
    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}

void sort_three(t_stack *stack_a)
{
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
    int size = get_stack_size(stack_a);
    int max_bits = 0;
    int num = size - 1;
    
    // Find maximum number of bits needed
    while ((num >> max_bits) != 0)
        max_bits++;
    
    // Radix sort implementation
    for (int i = 0; i < max_bits; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int num = stack_a->top->value;
            if ((num >> i) & 1)
                ra(stack_a, 1);
            else
                pb(stack_a, stack_b);
        }
        
        // Push all numbers back to stack_a
        while (get_stack_size(stack_b) > 0)
            pa(stack_a, stack_b);
    }
}
