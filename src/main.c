/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:35:13 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/27 15:15:29 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

static int is_number(char *str)
{
    int i = 0;
    
    if (!str[0])
        return 0;
    
    if (str[i] == '-' || str[i] == '+')
        i++;
    
    // Check for lone zero or multiple zeros
    if (str[i] == '0' && str[i + 1] != '\0')
        return 0;
        
    // Must have at least one digit
    if (!str[i])
        return 0;
    
    while (str[i])
    {
        if (str[i] < '0' || str[i] > '9')
            return 0;
        i++;
    }
    return 1;
}

static int is_valid_integer(char *str)
{
    long num = 0;
    int sign = 1;
    int i = 0;
    
    // Handle sign
    if (str[i] == '-' || str[i] == '+')
    {
        sign = (str[i] == '-') ? -1 : 1;
        i++;
    }
    
    // Convert to number and check overflow
    while (str[i])
    {
        num = (num * 10) + (str[i] - '0');
        if ((sign == 1 && num > INT_MAX) || 
            (sign == -1 && num > -(long)INT_MIN))
            return 0;
        i++;
    }
    
    return 1;
}

int check_duplicates(t_stack *stack, int num)
{
    t_node *current = stack->top;
    
    while (current)
    {
        if (current->value == num)
            return 1;
        current = current->next;
    }
    return 0;
}

static int is_already_sorted(t_stack *stack)
{
    if (!stack || !stack->top)
        return 1;
        
    t_node *current = stack->top;
    while (current->next)
    {
        if (current->value >= current->next->value)
            return 0;
        current = current->next;
    }
    return 1;
}

void sort_based_on_size(t_stack *stack_a, t_stack *stack_b)
{
    int size = get_stack_size(stack_a);
    
    if (size <= 3)
        sort_three(stack_a);
    else if (size <= 5)
        sort_five(stack_a, stack_b);
    else
        sort_large_stack(stack_a, stack_b);
}

int main(int argc, char **argv)
{
    if (argc < 2)
        return 1;
    
    t_stack *stack_a = create_stack();
    t_stack *stack_b = create_stack();
    
    if (!stack_a || !stack_b)
        return 1;
    
    // Parse arguments in reverse to maintain order
    for (int i = argc - 1; i > 0; i--)
    {
        if (!is_number(argv[i]) || !is_valid_integer(argv[i]))
        {
            write(2, "Error\n", 6);
            free_stack(stack_a);
            free_stack(stack_b);
            return 1;
        }
        
        int num = atoi(argv[i]);
        if (check_duplicates(stack_a, num))
        {
            write(2, "Error\n", 6);
            free_stack(stack_a);
            free_stack(stack_b);
            return 1;
        }
        
        push(stack_a, num);
    }
    
    // Only sort if not already sorted and more than one element
    if (!is_already_sorted(stack_a) && stack_a->size > 1)
        sort_based_on_size(stack_a, stack_b);
    
    free_stack(stack_a);
    free_stack(stack_b);
    return 0;
}
