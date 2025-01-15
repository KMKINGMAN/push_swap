/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:55:43 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/15 17:34:28 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_zero_format(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0' && str[i + 1])
		i++;
	return (i);
}

int	is_valid_number(char *str)
{
	int	start;
	int	i;

	if (!str || !*str)
		return (0);
	start = check_zero_format(str);
	i = start;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

int	process_number(char *str, t_stack *stack)
{
	int	num;

	if (!is_number(str) || !is_valid_integer(str))
		return (0);
	num = ft_atoi(str);
	if (check_duplicates(stack, num))
		return (0);
	push(stack, num);
	return (1);
}

static int	handle_split_numbers(char **numbers, t_stack *stack)
{
	int	i;

	i = 0;
	while (numbers[i])
		i++;
	while (--i >= 0)
	{
		if (!process_number(numbers[i], stack))
			return (0);
	}
	return (1);
}

int	parse_arguments(int argc, char **argv, t_stack *stack)
{
	int		i;
	char	**split;

	i = argc;
	while (--i > 0)
	{
		if (ft_strchr(argv[i], ' '))
		{
			split = ft_split(argv[i], ' ');
			if (!split || !handle_split_numbers(split, stack))
			{
				if (split)
					free_split(split);
				return (0);
			}
			free_split(split);
		}
		else if (!process_number(argv[i], stack))
			return (0);
	}
	return (1);
}
