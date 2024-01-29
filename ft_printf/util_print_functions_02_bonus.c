/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_functions_02_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:00:23 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/08/01 06:48:08 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
** Sets the 'print_minus' flag in the 't_opt' structure and prints the
** character '-'.
**
** opt: Pointer to the 't_opt' structure containing formatting options.
**
** Returns: The total number of characters printed (1 for the '-' character).
*/
int	print_minus(t_opt *opt)
{
	opt->print_minus = true;
	return (print_char('-'));
}

/*
** Sets the 'print_plus' flag in the 't_opt' structure and prints the
** character '+'.
**
** opt: Pointer to the 't_opt' structure containing formatting options.
**
** Returns: The total number of characters printed (1 for the '+' character).
*/
int	print_plus(t_opt *opt)
{
	opt->print_plus = true;
	return (print_char('+'));
}

/*
** Print the "0x" or "0X" prefix for the hexadecimal representation.
**
** is_maj: Set to true to use uppercase letters for "X", false for lowercase "x".
**
** Returns the total number of characters printed (2 for "0x" or "0X").
*/
int	print_sharp(bool is_maj)
{
	int	printed_chars;

	printed_chars = 0;
	if (is_maj)
		printed_chars += print_str("0X");
	else
		printed_chars += print_str("0x");
	return (printed_chars);
}

/*
** Prints characters while managing different types of padding for hexadecimal
** printing.
**
** opt: Pointer to the 't_opt' structure containing formatting options.
** type: The type of padding to print
** (1 for spaces, 2 for zeros, 3 for spaces again).
**
** Returns: The total number of characters printed (including padding).
*/
static int	print_while_type_4(t_opt *opt)
{
	int	printed_chars;

	printed_chars = 0;
	while (!opt->has_minus && opt->spaces >= 1)
	{
		if (opt->has_zero && !opt->has_precision)
		{
			if (opt->has_plus && opt->has_zero && !opt->is_negative
				&& !opt->print_plus)
				printed_chars += print_plus(opt);
			printed_chars += print_char('0');
		}
		else
		{
			printed_chars += print_char(' ');
			if (opt->has_plus && !opt->is_negative && opt->has_precision
				&& printed_chars == opt->field_min_width - opt->precision - 1
				&& !opt->print_plus)
				printed_chars += print_plus(opt);
		}
		--opt->spaces;
	}
	return (printed_chars);
}

/*
** Print characters while managing different types of padding for hexadecimal
** printing.
**
** opt: The t_opt structure containing formatting options.
** type: The type of padding to print
** (1 for spaces, 2 for zeros, 3 for spaces again).
**
** Returns the total number of characters printed (including padding).
*/
int	print_while_types(t_opt *opt, int type)
{
	int	printed_chars;

	printed_chars = 0;
	if (type == 1)
	{
		while (!opt->has_minus && opt->spaces-- >= 1)
		{
			if (opt->has_zero && !opt->has_precision)
				printed_chars += print_char('0');
			else
				printed_chars += print_char(' ');
		}
	}
	else if (type == 2)
		while (opt->zeros-- >= 1)
			printed_chars += print_char('0');
	else if (type == 3)
		while (opt->has_minus && opt->spaces-- >= 1)
			printed_chars += print_char(' ');
	else if (type == 4)
		printed_chars += print_while_type_4(opt);
	return (printed_chars);
}
