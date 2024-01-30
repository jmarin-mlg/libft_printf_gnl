/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:29:33 by jmarin-o          #+#    #+#             */
/*   Updated: 2024/01/30 17:54:19 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Print a string with a specified size to the standard output.
** If the size is -1, print the entire string.
**
** str: The string to print.
** size: The size of the string to print. If -1, print the entire string.
**
** Returns the total number of characters printed.
*/
static int	print_str_size(char *str, int size)
{
	int	i;

	if (size == -1)
		return (print_str(str));
	i = 0;
	while (str[i] && i < size)
		print_char(str[i++]);
	return (i);
}

/*
** Print a string to the standard output with formatting options.
**
** str: The string to print.
** opt: The formatting options for printing.
**
** Returns the total number of characters printed (including padding).
*/
int	ft_print_string(char *str, t_opt opt)
{
	int	printed_chars;
	int	len;

	printed_chars = 0;
	if (!str)
		len = S_EMPTY_L;
	else
		len = ft_strlen(str);
	if (opt.has_precision && opt.precision >= 0 && opt.precision < len)
		len = opt.precision;
	while (!opt.has_minus && printed_chars + len < opt.field_min_width)
		printed_chars += print_char(' ');
	if (!str)
		printed_chars += print_str_size(S_EMPTY, opt.precision);
	else
		printed_chars += print_str_size(str, opt.precision);
	while (opt.has_minus && printed_chars + 1 <= opt.field_min_width)
		printed_chars += print_char(' ');
	return (printed_chars);
}
