#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int             value;
    int             counter;
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
void    sort_large_stack(t_stack *stack_a, t_stack *stack_b);

#endif
