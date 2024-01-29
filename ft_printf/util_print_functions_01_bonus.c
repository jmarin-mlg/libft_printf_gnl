/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_print_functions_01_bonus.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 17:00:23 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/08/01 06:47:58 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

/*
** Print a single character to the standard output.
**
** c: The character to print.
**
** Returns the number of characters printed (always 1).
** If an error occurs during writing, returns -1.
*/
int	print_char(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

/*
** Print a null-terminated string to the standard output.
**
** str: The string to print.
**
** Returns the total number of characters printed.
** If an error occurs during writing, returns -1.
*/
int	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		print_char(str[i++]);
	return (i);
}

/*
** Recursively print a number in the specified base to the standard output.
**
** nbr:  The number to print.
** base: The base string representing the number system
** (e.g., "0123456789ABCDEF").
**
** Returns the total number of characters printed.
** If an error occurs during writing, returns -1.
*/
int	print_number_base(int nbr, char *base)
{
	unsigned int	base_len;
	unsigned int	nbrl;
	int				total;

	total = 0;
	nbrl = nbr;
	base_len = ft_strlen(base);
	if (nbrl >= base_len)
	{
		total += print_number_base(nbrl / base_len, base);
		total += print_number_base(nbrl % base_len, base);
	}
	else
	{
		total += print_char(base[nbrl]);
	}
	return (total);
}
