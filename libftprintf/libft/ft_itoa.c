/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 16:26:12 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/23 07:11:46 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** numlen: Calculate the length of the integer representation, considering
** both positive and negative numbers.
**
** Parameters:
**   num: The integer for which the length is calculated.
**
** Returns:
**   The length of the integer representation.
*/
static int	numlen(int num)
{
	int	len;

	len = 0;
	if (num <= 0)
		len = 1;
	while (num != 0)
	{
		++len;
		num /= 10;
	}
	return (len);
}

/*
** numstr: Convert an unsigned integer to a string and store it in the
** provided character array starting from the given index.
**
** Parameters:
**   str: The character array to store the string representation.
**   num: The unsigned integer to convert.
**   len: The starting index in the character array to store the string.
**
** Returns:
**   The updated character array with the string representation.
*/
static char	*numstr(char *str, unsigned int num, size_t len)
{
	while (num > 0)
	{
		str[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (str);
}

/*
** Parameters:
**   n: The integer to convert.
**
** Returns the string representing the number, or NULL if memory allocation
** fails.
*/
char	*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = numlen(n);
	res = (char *) ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	res[len--] = '\0';
	if (n == 0)
		res[0] = '0';
	if (n < 0)
	{
		n *= -1;
		res[0] = '-';
	}
	return (numstr(res, n, len));
}
