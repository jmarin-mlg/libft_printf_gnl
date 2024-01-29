/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_number_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:29:03 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/08/01 06:46:58 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
** Counts the number of digits in a given number.
**
** num: The number to count the digits of.
**
** Returns: The count of digits in the given number.
*/
static int	ft_count_digits(long num)
{
	int	count;

	if (num == 0)
		return (1);
	count = 0;
	if (num < 0)
	{
		++count;
		num = -num;
	}
	while (num > 0)
	{
		++count;
		num /= 10;
	}
	return (count);
}

/*
** Calculates the precision, zeros, and spaces for the formatted output.
**
** opt: Pointer to the 't_opt' structure containing formatting options.
** nl: The number to format.
** len: The length of the number in digits.
*/
static void	ft_calculate_precision(t_opt *opt, long nl, int len)
{
	if (opt->has_precision && len > opt->precision && nl != 0)
		opt->precision = len;
	if (opt->precision > opt->field_min_width && opt->precision >= len)
	{
		opt->field_min_width = opt->precision;
		opt->zeros = opt->precision - len;
	}
	else if (
		opt->field_min_width >= opt->precision && opt->field_min_width > len
	)
	{
		if (opt->precision > len)
			opt->zeros = opt->precision - len;
		opt->spaces = opt->field_min_width - opt->zeros - len;
	}
}

/*
** Calculates the padding for the formatted output.
**
** opt: Pointer to the 't_opt' structure containing formatting options.
** nl: The number to format.
*/
static void	ft_calculate_padding(t_opt *opt, long nl)
{
	int	len;

	if (nl < 0)
	{
		opt->is_negative = true;
		nl = -nl;
	}
	len = ft_count_digits(nl);
	ft_calculate_precision(opt, nl, len);
	if (opt->spaces >= 1
		&& (
			opt->is_negative
			|| (opt->has_space && opt->has_minus && nl >= 0)
			|| (opt->has_space && opt->has_zero && nl >= 0)
		)
	)
		--opt->spaces;
	if (nl == 0 && opt->field_min_width >= 1 && opt->precision == 0
		&& (!opt->has_space || (!opt->has_zero && !opt->has_minus
				&& opt->has_space && len == 1))
	)
		opt->spaces = opt->field_min_width;
	else if (nl == 0 && opt->field_min_width >= 1 && opt->precision == 0
		&& opt->has_space)
		opt->spaces = opt->field_min_width - 1;
}

/*
** Handles the second part of the 'ft_print_number' function, including the
** handling of signs, padding, and printing the number.
**
** nl: The number to format.
** opt: The 't_opt' structure containing formatting options.
** printed_chars: Pointer to the variable holding the total number of printed
** characters.
*/
static void	ft_print_number_part_two(long nl, t_opt opt, int *printed_chars)
{
	if (
		opt.is_negative && opt.field_min_width > opt.precision
		&& !opt.print_minus
	)
		*printed_chars += print_char('-');
	if (opt.has_plus && !opt.has_zero && !opt.is_negative && !opt.print_plus)
		*printed_chars += print_char('+');
	*printed_chars += print_while_types(&opt, 2);
	if (nl < 0)
		nl = -nl;
	if (!(opt.has_precision && opt.precision == 0 && nl == 0))
		*printed_chars += print_number_base(nl, "0123456789");
	*printed_chars += print_while_types(&opt, 3);
}

/*
** Formats and prints a number.
**
** nl: The number to print.
** opt: The 't_opt' structure containing formatting options.
**
** Returns: The total number of characters printed.
*/
int	ft_print_number(long nl, t_opt opt)
{
	int		printed_chars;

	ft_calculate_padding(&opt, nl);
	printed_chars = 0;
	if (opt.has_space
		&& (
			(opt.has_minus && nl >= 0)
			|| (opt.field_min_width == opt.precision && nl >= 0)
			|| (opt.field_min_width >= 0 && !opt.is_negative && opt.spaces == 0
				&& nl >= 0)
			|| (opt.has_zero && nl >= 0)
		)
	)
		printed_chars += print_char(' ');
	if (opt.is_negative && ((opt.has_zero && !opt.has_precision)
			|| (opt.has_precision && opt.spaces == 0)))
		printed_chars += print_minus(&opt);
	if (opt.has_plus && !opt.is_negative && opt.spaces >= 1)
		--opt.spaces;
	if (opt.has_plus && opt.has_zero && opt.spaces == 0 && !opt.is_negative
		&& !opt.print_plus)
		printed_chars += print_plus(&opt);
	printed_chars += print_while_types(&opt, 4);
	ft_print_number_part_two(nl, opt, &printed_chars);
	return (printed_chars);
}
