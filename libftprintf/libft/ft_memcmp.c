/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:35:24 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/01 08:32:33 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function compares byte string s1 against byte string s2.  Both strings
** are assumed to be n bytes long.
**
** The function returns zero if the two strings are identical, otherwise returns
** the difference between the first two differing bytes (treated as unsigned
** char values, so that `\200' is greater than `\0', for example). Zero-length
** strings are always identical. This behavior is not required by C and portable
** code should only depend on the sign of the returned value.
*/
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*pointer1;
	unsigned char	*pointer2;

	pointer1 = (unsigned char *) s1;
	pointer2 = (unsigned char *) s2;
	if (n == 0)
		return (0);
	i = 0;
	while (*pointer1 == *pointer2 && ++i < n)
	{
		++pointer1;
		++pointer2;
	}
	return ((int)(*pointer1 - *pointer2));
}
