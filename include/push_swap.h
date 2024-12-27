/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:33:15 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/27 15:18:41 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int             value;
    struct s_node   *next;
} t_node;

typedef struct s_stack
{
    t_node  *top;
    int     size;
} t_stack;

// Stack operations
t_stack *create_stack(void);
void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
void    free_stack(t_stack *stack);
void    swap(t_stack *stack);
void    rotate(t_stack *stack);

// Basic operations
void    sa(t_stack *stack_a, int print);
void    sb(t_stack *stack_b, int print);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void    ra(t_stack *stack_a, int print);
void    rb(t_stack *stack_b, int print);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a, int print);
void    rrb(t_stack *stack_b, int print);
void    rrr(t_stack *stack_a, t_stack *stack_b);

// Stack utility functions
int     get_stack_size(t_stack *stack);

// Sorting functions
void    sort_three(t_stack *stack_a);
void    sort_five(t_stack *stack_a, t_stack *stack_b);
void sort_large_stack(t_stack *stack_a, t_stack *stack_b);
void    sort_stack(t_stack *stack_a, t_stack *stack_b);

int     find_min(t_stack *stack);
int     find_max(t_stack *stack);
int     get_position(t_stack *stack, int num);
void    quick_sort(t_stack *stack_a, t_stack *stack_b, int size);

#endif
