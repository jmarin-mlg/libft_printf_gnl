/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:27:31 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/08/01 06:47:20 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
** Check if a character is a valid conversion specifier.
**
** c: The character to check.
**
** Returns 1 if the character is a valid conversion specifier, 0 otherwise.
*/
static int	ft_is_conversion_specifier(char c)
{
	return (
		c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%'
	);
}

/*
** Handle the specified conversion specifier and extract the data from the
** variable argument list.
**
** conversion: A pointer to the t_conversion structure holding the conversion
**             specifier and options.
** args:       A pointer to the variable argument list.
**
** Returns the total number of characters printed (including padding).
*/
static int	handle_specifier(t_conversion *conversion, va_list *args)
{
	t_data	data;

	init_data(&data);
	if (conversion->conversion == 'c')
		data.character = va_arg(*args, int);
	else if (conversion->conversion == 's')
		data.string = va_arg(*args, char *);
	else if (conversion->conversion == 'p')
		data.pointer = va_arg(*args, void *);
	else if (conversion->conversion == 'd' || conversion->conversion == 'i')
		data.number = va_arg(*args, int);
	else if (conversion->conversion == 'u')
		data.u_number = va_arg(*args, unsigned int);
	else if (conversion->conversion == 'x' || conversion->conversion == 'X')
		data.number = va_arg(*args, int);
	return (ft_print_data(data, *conversion));
}

/*
** Parse the flags that modify the formatting options in the t_conversion
** structure.
**
** conversion: A pointer to the t_conversion structure to modify.
** flag:       The flag character to parse.
*/
static void	parse_flags(t_conversion *conversion, char flag)
{
	if (flag == '0')
		conversion->options.has_zero = true;
	else if (flag == '#')
		conversion->options.has_sharp = true;
	else if (flag == ' ')
		conversion->options.has_space = true;
	else if (flag == '+')
		conversion->options.has_plus = true;
	else if (flag == '-')
		conversion->options.has_minus = true;
	else if (flag == '.')
		conversion->options.has_precision = true;
}

/*
** Process the format string and extract the conversion specifier and
** options
** to fill the t_conversion structure.
**
** format:     The format string to process (points to the start of the
** specifier).
** conversion: A pointer to the t_conversion structure to fill.
*/
static void	process_format(const char *format, t_conversion *conversion)
{
	init_conversion(conversion);
	while (*format && ft_strchr("0# +-.", *format))
	{
		parse_flags(conversion, *format);
		++format;
	}
	if (!conversion->options.has_precision && ft_isdigit(*format))
	{
		conversion->options.field_min_width = ft_atoi(format);
		while (ft_isdigit(*format))
			++format;
	}
	if (conversion->options.has_precision || *format == '.')
	{
		if (*format == '.')
		{
			conversion->options.has_precision = true;
			++format;
		}
		conversion->options.precision = ft_atoi(format);
		while (ft_isdigit(*format))
			++format;
	}
	if (ft_is_conversion_specifier(*format))
		conversion->conversion = *format;
}

/*
** Print formatted output according to the format string and variable arguments.
**
** format: The format string containing the conversion specifiers and text to
** print.
** ...:    Additional variable arguments corresponding to the format specifiers.
**
** Returns the total number of characters printed.
*/
int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_conversion	conversion;
	int				result;
	int				printed_chars;

	printed_chars = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			process_format(++format, &conversion);
			result = handle_specifier(&conversion, &args);
			while (result != -1 && *format != conversion.conversion)
				++format;
		}
		else
			result = print_char(*format);
		if (result == -1)
			return (-1);
		printed_chars += result;
		++format;
	}
	va_end(args);
	return (printed_chars);
}
