/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 17:34:05 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 18:21:36 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Frees a dynamically allocated
 *  array of strings.
 *
 * This function takes a null-terminated
 *  array of strings (char **split) and 
 * frees each string in the array, then
 *  frees the array itself.
 *
 * @param split A null-terminated array of strings to be freed.
 *
 * @example
 * // Example usage:
 * char **split = malloc(3 * sizeof(char *));
 * split[0] = strdup("Hello");
 * split[1] = strdup("World");
 * split[2] = NULL; // Null-terminated
 * 
 * // Free the allocated memory
 * free_split(split);
 */
void	free_split(char **split)
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

/**
 * @brief Checks if the given string represents
 *  a valid integer within the range of int.
 *
 * This function takes a string as input and
 *  determines if it can be converted to a valid
 * integer within the range of the `int` data
 *  type. It handles optional leading '+' or '-'
 * signs and checks for overflow or underflow
 *  conditions.
 *
 * @param str The input string to be checked.
 * @return int Returns 1 if the string represents
 *  a valid integer, 0 otherwise.
 *
 * @example
 * // Example usage:
 * char *valid_str1 = "123";
 * char *valid_str2 = "-456";
 * char *invalid_str1 = "123abc";
 * char *invalid_str2 = "999999999999999999999";
 *
 * int result1 = is_valid_integer(valid_str1);
 *  // result1 will be 1
 * int result2 = is_valid_integer(valid_str2);
 *  // result2 will be 1
 * int result3 = is_valid_integer(invalid_str1);
 *  // result3 will be 0
 * int result4 = is_valid_integer(invalid_str2);
 *  // result4 will be 0
 */
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
		if (str[i] == '-')
			sign = -1;
		else
			sign = 1;
		i++;
	}
	while (str[i])
	{
		num = (num * 10) + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num > \
				-(long)INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Checks for duplicate values in a stack.
 *
 * This function iterates through the stack
 *  to determine if a given number
 * already exists within the stack. 
 * If a duplicate is found, the function
 * returns 1, otherwise it returns 0.
 *
 * @param stack A pointer to the stack to be checked.
 * @param num The number to check for duplicates.
 * @return int Returns 1 if a duplicate is found,
 *  otherwise returns 0.
 *
 * @example
 * // Assuming t_stack and t_node are properly
 *  defined and initialized
 * t_stack *stack = initialize_stack();
 * push(stack, 10);
 * push(stack, 20);
 * push(stack, 30);
 *
 * int result = check_duplicates(stack, 20);
 * // result will be 1 because 20 is already in the stack
 *
 * result = check_duplicates(stack, 40);
 * // result will be 0 because 40 is not in the stack
 */
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

/**
 * @brief Reverses the order of elements in
 *  a null-terminated array of strings.
 *
 * This function takes a null-terminated 
 * array of strings and reverses the order
 * of its elements in place. The reversal 
 * is done by swapping the elements from
 * the beginning and the end of the array 
 * moving towards the center.
 *
 * @param arr A null-terminated array of strings to be reversed.
 *
 * @example
 * // Given the following array of strings:
 * // arr = ["one", "two", "three", "four", NULL]
 * // After calling reverse_array(arr), the array will be:
 * // arr = ["four", "three", "two", "one", NULL]
 *
 * @note The input array must be null-terminated,
 *  meaning the last element of
 * the array should be a NULL pointer.
 */
void	reverse_array(char **arr)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (arr[j])
		j++;
	j--;
	while (i < j)
	{
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
		i++;
		j--;
	}
}
