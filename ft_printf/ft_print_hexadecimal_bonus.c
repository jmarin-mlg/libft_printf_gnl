/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexadecimal_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:28:23 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/08/01 06:46:45 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
** Obtain the unsigned value of a given integer.
**
** nbr: The integer value.
**
** Returns the unsigned value of the integer.
*/
static unsigned int	get_unsigned_value(int nbr)
{
	unsigned int	nbrl;

	if (nbr < 0)
		nbrl = (unsigned int)-nbr;
	else
		nbrl = (unsigned int)nbr;
	return (nbrl);
}

/*
** Calculate the length of a hexadecimal representation of a number in a given
** base.
**
** nbr: The integer value to be converted to hexadecimal.
** base_len: The length of the base (e.g., 16 for hexadecimal).
**
** Returns the length of the hexadecimal representation of the number.
*/
static int	calculate_hex_length(int nbr, unsigned int base_len)
{
	int				length;
	unsigned int	nbrl;
	int				total_bits;
	int				significant_bits;

	length = 1;
	nbrl = get_unsigned_value(nbr);
	total_bits = 8 * sizeof(int);
	significant_bits = total_bits;
	if (nbr < 0)
	{
		--significant_bits;
		nbrl |= ~((1u << total_bits) - 1);
		while (
			significant_bits > 1 && (nbrl & (1u << (significant_bits - 1))) == 0
		)
			--significant_bits;
	}
	while (nbrl >= base_len)
	{
		nbrl /= base_len;
		++length;
	}
	return (length);
}

/*
** Calculate the padding for hexadecimal printing, considering the formatting
** options.
**
** opt: The t_opt structure containing formatting options.
** nl: The integer value for which padding is calculated.
*/
static void	ft_calculate_padding(t_opt *opt, long nl)
{
	int	len;

	len = calculate_hex_length(nl, 16);
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
	if (nl == 0 && opt->field_min_width >= 1 && opt->precision == 0)
		opt->spaces = opt->field_min_width;
	if (opt->has_sharp && nl != 0)
		opt->spaces -= 2;
}

/*
** Print the hexadecimal representation of a number.
**
** is_maj: Set to true to use uppercase letters for hexadecimal digits, false
** for lowercase.
** nbr: The integer value to be printed in hexadecimal.
** opt: The t_opt structure containing formatting options.
**
** Returns the total number of characters printed (including padding).
*/
static int	print_x(int is_maj, int nbr, t_opt opt)
{
	int	printed_chars;
	int	len;

	printed_chars = 0;
	len = calculate_hex_length(nbr, 16);
	if (nbr == 0 && opt.field_min_width && opt.field_min_width < len)
		printed_chars += print_char(' ');
	else if (
		nbr == 0 && opt.has_precision && !opt.precision
		&& opt.field_min_width >= len
	)
		printed_chars += print_char(' ');
	else if (!(nbr == 0 && opt.has_precision && !opt.precision))
	{
		if (is_maj)
			printed_chars += print_number_base(nbr, "0123456789ABCDEF");
		else
			printed_chars += print_number_base(nbr, "0123456789abcdef");
	}
	return (printed_chars);
}

/*
** Print the hexadecimal representation of an integer with formatting options.
**
** nbr: The integer value to be printed in hexadecimal.
** is_maj: Set to true to use uppercase letters for hexadecimal digits, false
** for lowercase.
** opt: The t_opt structure containing formatting options.
**
** Returns the total number of characters printed (including padding).
*/
int	ft_print_hexa(int nbr, int is_maj, t_opt opt)
{
	int	printed_chars;

	ft_calculate_padding(&opt, nbr);
	printed_chars = 0;
	if (opt.has_zero && !opt.has_precision && opt.has_sharp && nbr != 0)
		printed_chars += print_sharp(is_maj);
	printed_chars += print_while_types(&opt, 1);
	if ((!opt.has_zero || opt.has_precision) && opt.has_sharp && nbr != 0)
		printed_chars += print_sharp(is_maj);
	printed_chars += print_while_types(&opt, 2);
	if (!(opt.has_precision && opt.precision == 0 && nbr == 0))
		printed_chars += print_x(is_maj, nbr, opt);
	printed_chars += print_while_types(&opt, 3);
	return (printed_chars);
}
