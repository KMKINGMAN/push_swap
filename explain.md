# Push Swap Algorithm Explanation

## Overview
Push Swap is a sorting algorithm project that requires sorting a stack of numbers using two stacks (A and B) with a limited set of operations. The goal is to sort numbers in ascending order with the minimum number of operations possible.

## Data Structures
```c
typedef struct s_node {
    int value;
    struct s_node *next;
} t_node;

typedef struct s_stack {
    t_node *top;
    int size;
} t_stack;
```

## Available Operations

### Swap Operations
- `sa`: Swap the first 2 elements of stack A
- `sb`: Swap the first 2 elements of stack B
- `ss`: Do `sa` and `sb` simultaneously

Example of `sa`:
```
Before: [3, 1, 2]
After:  [1, 3, 2]
```

### Push Operations
- `pa`: Push the top element from stack B to stack A
- `pb`: Push the top element from stack A to stack B

Example of `pb`:
```
Stack A: [1, 2, 3]  →  [2, 3]
Stack B: []         →  [1]
```

### Rotate Operations
- `ra`: Rotate stack A up (first element becomes last)
- `rb`: Rotate stack B up
- `rr`: Do `ra` and `rb` simultaneously

Example of `ra`:
```
Before: [1, 2, 3, 4]
After:  [2, 3, 4, 1]
```

### Reverse Rotate Operations
- `rra`: Rotate stack A down (last element becomes first)
- `rrb`: Rotate stack B down
- `rrr`: Do `rra` and `rrb` simultaneously

Example of `rra`:
```
Before: [1, 2, 3, 4]
After:  [4, 1, 2, 3]
```

## Sorting Strategies

### For 3 Numbers
Uses a hardcoded approach based on possible permutations:
```
Case 1: [3, 1, 2] → sa → [1, 3, 2] → rra → [2, 1, 3]
Case 2: [2, 3, 1] → rra → [1, 2, 3]
Case 3: [3, 2, 1] → ra → [2, 1, 3] → sa → [1, 2, 3]
```

### For 5 Numbers
1. Find minimum value
2. Rotate until minimum is on top
3. Push to stack B
4. Repeat once more
5. Sort remaining 3 numbers
6. Push back from B to A

Example:
```
Initial A: [4, 2, 1, 5, 3]  B: []
Step 1:    [4, 2, 5, 3]     [1]
Step 2:    [4, 5, 3]        [2, 1]
Sort 3:    [3, 4, 5]        [2, 1]
Final:     [1, 2, 3, 4, 5]  []
```

### For Large Numbers (>5)
Uses a modified radix sort algorithm:
1. Normalize numbers to positive range
2. Sort based on binary digits
3. For each bit position:
   - Push numbers with 0 at current bit to B
   - Keep numbers with 1 at current bit in A
   - Push all numbers back to A

Example with binary representation:
```
Original: [5, 2, 8, 1]
Binary:   [101, 010, 1000, 001]

Sorting by least significant bit:
A: [5, 2, 8, 1] → [5, 1] (odd numbers)
B: []           → [2, 8] (even numbers)
```

## Complexity Analysis
- 3 numbers: Maximum 2-3 operations
- 5 numbers: Maximum 12 operations
- 100 numbers: Around 700 operations
- 500 numbers: Around 5500 operations

## Error Handling
The program handles several error cases:
- Non-numeric input
- Duplicate numbers
- Numbers outside INT range
- Invalid format (spaces, signs, etc.)

## Memory Management
The program properly frees all allocated memory:
- Frees nodes during operations
- Frees stacks at program end
- Handles memory allocation failures

## Best Practices
1. Always check if stack is already sorted
2. Use different algorithms based on input size
3. Optimize number of operations
4. Handle edge cases properly
5. Maintain proper memory management
