/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_data_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:29:48 by jmarin-o          #+#    #+#             */
/*   Updated: 2024/01/30 17:54:19 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Print the data contained in the t_data structure according to the specified
** conversion specifier and formatting options.
**
** data:       The t_data structure containing the data to be printed.
** conversion: The t_conversion structure specifying the conversion specifier
**             and formatting options.
**
** Returns the total number of characters printed (including padding).
** If the conversion specifier is invalid, returns -1 to indicate an error.
*/
int	ft_print_data(t_data data, t_conversion conversion)
{
	int	printed_chars;

	printed_chars = 0;
	if (conversion.conversion == 'c')
		printed_chars += ft_print_character(data.character, conversion.options);
	else if (conversion.conversion == 's')
		printed_chars += ft_print_string(data.string, conversion.options);
	else if (conversion.conversion == 'p')
		printed_chars += ft_print_pointer(data.pointer, conversion.options);
	else if (conversion.conversion == 'd' || conversion.conversion == 'i')
		printed_chars += ft_print_number(data.number, conversion.options);
	else if (conversion.conversion == 'u')
		printed_chars += ft_print_number(data.u_number, conversion.options);
	else if (conversion.conversion == 'x')
		printed_chars += ft_print_hexa(data.number, 0, conversion.options);
	else if (conversion.conversion == 'X')
		printed_chars += ft_print_hexa(data.number, 1, conversion.options);
	else if (conversion.conversion == '%')
		printed_chars += ft_print_character('%', conversion.options);
	else
		printed_chars = -1;
	return (printed_chars);
}
