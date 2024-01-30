/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 07:09:50 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/04 18:24:14 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strcmp() and ft_strncmp() functions lexicographically compare the
** null-terminated strings s1 and s2.
**
** The ft_strncmp() function compares not more than n characters. Because
** ft_strncmp() is designed for comparing strings rather than binary data,
** characters that appear after a `\0' character are not compared.
**
** The ft_strcmp() and ft_strncmp() functions return an integer greater than,
** equal to, or less than 0, according as the string s1 is greater than, equal
** to, or less than the string s2.  The comparison is done using unsigned
** characters, so that `\200' is greater than `\0'.
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < (n - 1))
		++i;
	return ((unsigned char) s1[i] - (unsigned char) s2[i]);
}
