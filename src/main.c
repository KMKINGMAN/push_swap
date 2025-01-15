/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:35:13 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/15 19:07:06 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (!str[0])
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '0' && str[i + 1] != '\0')
		return (0);
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	sort_based_on_size(t_stack *stack_a, t_stack *stack_b)
{
	int	size;

	size = get_stack_size(stack_a);
	if (size <= 3)
		sort_three(stack_a);
	else if (size <= 5)
		sort_five(stack_a, stack_b);
	else
		sort_large_stack(stack_a, stack_b);
}

int	is_already_sorted(t_stack *stack)
{
	t_node	*current;

	if (!stack || !stack->top)
		return (1);
	current = stack->top;
	while (current->next)
	{
		if (current->value >= current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

static int	init_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = create_stack();
	*stack_b = create_stack();
	if (!*stack_a || !*stack_b)
	{
		if (*stack_a)
			free_stack(*stack_a);
		if (*stack_b)
			free_stack(*stack_b);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc < 2)
		return (1);
	if (!init_stacks(&stack_a, &stack_b))
		return (EXIT_FAILURE);
	if (!parse_arguments(argc, argv, stack_a))
		clean_exit(stack_a, stack_b, 1);
	if (!is_already_sorted(stack_a) && stack_a->size > 1)
		sort_based_on_size(stack_a, stack_b);
	clean_exit(stack_a, stack_b, 0);
	return (0);
}
