/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:33:15 by mkurkar           #+#    #+#             */
/*   Updated: 2024/12/24 16:02:46 by mkurkar          ###   ########.fr       */
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

void    sa(t_stack *stack_a, int print);
void    sb(t_stack *stack_b, int print);
void    ss(t_stack *stack_a, t_stack *stack_b);
void    pa(t_stack *stack_a, t_stack *stack_b);
void    pb(t_stack *stack_a, t_stack *stack_b);
void quick_sort(t_stack *stack_a, t_stack *stack_b, int size);
void    ra(t_stack *stack_a, int print);
void    rb(t_stack *stack_b, int print);
void    rr(t_stack *stack_a, t_stack *stack_b);
void    rra(t_stack *stack_a, int print);
void    rrb(t_stack *stack_b, int print);
void    rrr(t_stack *stack_a, t_stack *stack_b);
void sort_stack(t_stack *stack_a, t_stack *stack_b);
// Stack utilities
t_stack *create_stack(void);
void    push(t_stack *stack, int value);
int     pop(t_stack *stack);
void    free_stack(t_stack *stack);

#endif
