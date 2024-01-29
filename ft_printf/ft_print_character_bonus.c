/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_character_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 17:28:39 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/08/01 06:46:23 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
** Print a single character with the specified formatting options.
**
** c: The character to print.
** opt: The formatting options.
**
** Returns the total number of characters printed (including padding).
*/
int	ft_print_character(char c, t_opt opt)
{
	int	printed_chars;

	printed_chars = 0;
	while (!opt.has_minus && printed_chars + 1 < opt.field_min_width)
		printed_chars += print_char(' ');
	if (print_char(c) == -1)
		return (-1);
	++printed_chars;
	while (opt.has_minus && printed_chars + 1 <= opt.field_min_width)
		printed_chars += print_char(' ');
	return (printed_chars);
}
