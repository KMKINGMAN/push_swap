#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
    int value;
    int index;
    struct s_node *next;
} t_node;

typedef struct s_stack
{
    t_node *top;
    int size;
} t_stack;

// Stack operations
t_stack *create_stack(void);
void push(t_stack *stack, int value);
int pop(t_stack *stack);
void free_stack(t_stack *stack);

// Basic operations
void sa(t_stack *stack_a, int print);
void sb(t_stack *stack_b, int print);
void ss(t_stack *stack_a, t_stack *stack_b);
void pa(t_stack *stack_a, t_stack *stack_b);  // Fixed parameter declaration
void pb(t_stack *stack_a, t_stack *stack_b);  // Fixed parameter declaration

// Rotate operations
void ra(t_stack *stack_a, int print);
void rb(t_stack *stack_b, int print);
void rr(t_stack *stack_a, t_stack *stack_b);
void rra(t_stack *stack_a, int print);
void rrb(t_stack *stack_b, int print);
void rrr(t_stack *stack_a, t_stack *stack_b);

// Sort functions
void sort_stack(t_stack *stack_a, t_stack *stack_b);
void sort_three(t_stack *stack);
void sort_small(t_stack *stack_a, t_stack *stack_b);
void sort_large(t_stack *stack_a, t_stack *stack_b);

// Utility functions
int check_duplicates(t_stack *stack, int num);  // Added missing declaration
int get_stack_size(t_stack *stack);
void sort_three(t_stack *stack_a);
void sort_five(t_stack *stack_a, t_stack *stack_b);
void sort_large_stack(t_stack *stack_a, t_stack *stack_b);

#endif
