/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkurkar <mkurkar@student.42amman.com>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 16:55:43 by mkurkar           #+#    #+#             */
/*   Updated: 2025/01/24 18:18:59 by mkurkar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Checks the format of a 
 * string for 
 * leading zeros, ignoring an optional 
 * leading sign.
 *
 * This function examines 
 * the input string 
 * `str` and skips over any 
 * leading sign ('-' or '+').
 * It then continues to skip 
 * over any leading
 *  zeros until it encounters 
 * a non-zero character or
 * the end of the string.
 *
 * @param str The input string 
 * to be checked.
 * @return The index of the 
 * first non-zero character
 *  after any leading sign
 *  and zeros.
 *
 * @example
 * char *example1 = "+000123";
 * int index1 = check_zero_format(example1);
 * // index1 will be 4, pointing to '1' in the 
 * // string "+000123".
 *
 * char *example2 = "-0000";
 * int index2 = check_zero_format(example2);
 * // index2 will be 5, pointing to the null 
 * // terminator '\0' in the string "-0000".
 *
 * char *example3 = "00045";
 * int index3 = check_zero_format(example3);
 * // index3 will be 3, pointing to '4' in 
 * // the string "00045".
 */
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

/**
 * @brief Checks if the given string r
 * epresents a valid number.
 *
 * This function verifies whether the input 
 * string is a valid number.
 * It first checks for null or empty strings, 
 * then verifies the format
 * for leading zeros, and finally ensures all 
 * characters are digits.
 *
 * @param str The input string to be checked.
 * @return int Returns 1 if the string is a valid 
 * number, 0 otherwise.
 *
 * @example
 * // Example usage:
 * char *valid_number = "12345";
 * char *invalid_number = "12a45";
 * char *leading_zero = "0123";
 * 
 * int result1 = is_valid_number(valid_number); 
 * // result1 will be 1
 * int result2 = is_valid_number(invalid_number); 
 * // result2 will be 0
 * int result3 = is_valid_number(leading_zero); 
 * // result3 will be 1 or 0 depending on 
 * //check_zero_format implementation
 */
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

/**
 * @brief Processes a string representation of
 *  a number, checks its validity,
 *  and adds it to the stack if it is 
 * valid and not a duplicate.
 *
 * This function performs the following checks:
 * 1. Verifies if the string is a valid number.
 * 2. Ensures the number is within the integer range.
 * 3. Checks for duplicate numbers in the stack.
 * If all checks pass, the number is converted 
 * from string to integer and 
 * pushed onto the stack.
 *
 * @param str The string representation of 
 * the number to be processed.
 * @param stack A pointer to the stack where 
 * the number will be added.
 * @return int Returns 1 if the number is 
 * valid and added to the stack, 
 * otherwise returns 0.
 *
 * @example
 * t_stack *stack = create_stack();
 * 
 * // Example 1: Valid number
 * char *num_str1 = "42";
 * int result1 = process_number(num_str1, stack);
 * // result1 is 1, and 42 is added to the stack.
 *
 * // Example 2: Invalid number (not a number)
 * char *num_str2 = "abc";
 * int result2 = process_number(num_str2, stack);
 * // result2 is 0, and nothing is added to the stack.
 *
 * // Example 3: Invalid number (out of integer range)
 * char *num_str3 = "2147483648";
 * int result3 = process_number(num_str3, stack);
 * // result3 is 0, and nothing is added to the stack.
 *
 * // Example 4: Duplicate number
 * char *num_str4 = "42";
 * int result4 = process_number(num_str4, stack);
 * // result4 is 0, and nothing is added to the stack.
 */
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

/**
 * @brief Handles the split numbers and 
 * processes them into the stack.
 *
 * This function takes an array of string s 
 * representing numbers and processes
 * each number into the given stack. 
 * It iterates through the array from the end
 * to the beginning, ensuring that each number 
 * is processed correctly.
 *
 * @param numbers An array of strings wher
 * e each
 *  string is a number to be processed.
 * @param stack A pointer to the stack where the
 *  numbers will be stored.
 * @return int Returns 1 if all numbers are 
 * processed successfully, otherwise returns 0.
 *
 * @example
 * char *numbers[] = {"42", "17", "-3", NULL};
 * t_stack stack;
 * int result = handle_split_numbers(numbers, &stack);
 * if (result) {
 *     // All numbers processed successfully
 * } else {
 *     // Error processing numbers
 * }
 */
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

/**
 * @brief Parses the command-line arguments 
 * and processes the numbers.
 *
 * This function iterates over the provided 
 * command-line arguments in reverse order.
 * If an argument contains a space, it splits 
 * the argument into individual numbers
 * and processes each number. If an argument 
 * does not contain a space, it processes
 * the number directly. The processed numbers 
 * are stored in the provided stack.
 *
 * @param argc The number of command-line arguments.
 * @param argv The array of command-line arguments.
 * @param stack A pointer to the stack where
 *  the processed numbers will be stored.
 * @return Returns 1 if all arguments are
 *  successfully processed, otherwise returns 0.
 *
 * @example
 * int main(int argc, char **argv)
 * {
 *     t_stack stack;
 *     if (!parse_arguments(argc, argv, &stack))
 *     {
 *		fprintf(stderr, "Error: Failed to parse arguments\n");
 *		return 1;
 *     }
 *     // Continue with the rest of the program
 *     return 0;
 * }
 *
 * @note This function assumes that the 
 * stack and other helper functions
 * (ft_strchr, ft_split, handle_split_
 * numbers, process_number, free_split) are
 * properly defined and implemented elsewhere in the codebase.
 */
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
