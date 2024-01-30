/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:29:20 by jmarin-o          #+#    #+#             */
/*   Updated: 2024/01/30 17:54:19 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Recursively print a long unsigned integer as hexadecimal to the standard
** output.
**
** addr: The long unsigned integer to print.
**
** Returns the total number of characters printed.
*/
static int	print_long_as_hex(long unsigned addr)
{
	char	c;
	int		total;

	total = 0;
	if (addr >= 16)
	{
		total += print_long_as_hex(addr / 16);
		total += print_long_as_hex(addr % 16);
	}
	else
	{
		c = (addr % 16) + '0';
		if ((addr % 16) > 9)
			c = ((addr % 16) + 87);
		print_char(c);
		total++;
	}
	return (total);
}

/*
** Recursively calculate the size of a long unsigned integer in hexadecimal
** notation.
**
** addr: The long unsigned integer to calculate the size for.
**
** Returns the number of characters needed to represent the integer in
** hexadecimal.
*/
static int	get_hex_size(long unsigned addr)
{
	int	total;

	total = 0;
	if (addr >= 16)
	{
		total += get_hex_size(addr / 16);
		total += get_hex_size(addr % 16);
	}
	else
		total++;
	return (total);
}

/*
** Print a pointer address in hexadecimal with the "0x" prefix to the standard
** output.
**
** ptr: The pointer address to print.
** opt: The formatting options for printing.
**
** Returns the total number of characters printed (including padding).
*/
int	ft_print_pointer(void *ptr, t_opt opt)
{
	int		printed_chars;
	int		len;
	long	addr;

	if (!ptr)
		len = P_EMPTY_L;
	else
	{
		addr = (long unsigned) ptr;
		len = get_hex_size(addr) + 2;
	}
	printed_chars = 0;
	while (!opt.has_minus && printed_chars + len < opt.field_min_width)
		printed_chars += print_char(' ');
	if (!ptr)
		printed_chars += print_str(P_EMPTY);
	else
	{
		printed_chars += print_str("0x");
		printed_chars += print_long_as_hex(addr);
	}
	while (opt.has_minus && printed_chars + 1 <= opt.field_min_width)
		printed_chars += print_char(' ');
	return (printed_chars);
}
