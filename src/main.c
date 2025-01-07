/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 15:35:13 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/07 18:16:20 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>
#include <unistd.h>

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

int	is_valid_integer(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		sign = (str[i] == '-') ? -1 : 1;
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num >
				-(long)INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates(t_stack *stack, int num)
{
	t_node	*current;

	current = stack->top;
	while (current)
	{
		if (current->value == num)
			return (1);
		current = current->next;
	}
	return (0);
}

static int	is_already_sorted(t_stack *stack)
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

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static int	process_number(char *str, t_stack *stack_a)
{
	int	num;

	if (!is_number(str) || !is_valid_integer(str))
		return (0);
	num = ft_atoi(str);
	if (check_duplicates(stack_a, num))
		return (0);
	push(stack_a, num);
	ra(stack_a, 0);
	return (1);
}

static int	process_argument(char *arg, t_stack *stack_a)
{
	char	**numbers;
	int		i;
	int		success;

	numbers = ft_split(arg, ' ');
	if (!numbers)
		return (0);
	success = 1;
	i = 0;
	while (numbers[i] && success)
	{
		if (!process_number(numbers[i], stack_a))
			success = 0;
		i++;
	}
	free_split(numbers);
	return (success);
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

static void	clean_exit(t_stack *stack_a, t_stack *stack_b, int error)
{
	if (error)
		write(2, "Error\n", 6);
	if (stack_a)
		free_stack(stack_a);
	if (stack_b)
		free_stack(stack_b);
	exit(error);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	if (argc < 2)
		return (1);
	if (!init_stacks(&stack_a, &stack_b))
		return (1);
	i = argc - 1;
	while (i > 0)
	{
		if (!process_argument(argv[i], stack_a))
			clean_exit(stack_a, stack_b, 1);
		i--;
	}
	if (!is_already_sorted(stack_a) && stack_a->size > 1)
		sort_based_on_size(stack_a, stack_b);
	clean_exit(stack_a, stack_b, 0);
	return (0);
}
