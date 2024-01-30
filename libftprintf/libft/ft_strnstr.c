/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 07:05:56 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/27 05:58:11 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function locates the first occurrence of the null-terminated string
** needle in the string haystack, where not more than len characters are
** searched. Characters that appear after a `\0' character are not searched.
** Since the function is a FreeBSD specific API, it should only be used when
** portability is not a concern.
**
** If needle is an empty string, haystack is returned; if needle occurs nowhere
** in haystack, NULL is returned; otherwise a pointer to the first character of
** the first occurrence of needle is returned.
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	ih;
	size_t	in;
	size_t	needle_len;

	ih = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0 || haystack == needle)
		return ((char *) haystack);
	while (haystack[ih] && ih < len)
	{
		in = 0;
		while (
			haystack[ih + in] != '\0' && needle[in] != '\0'
			&& haystack[ih + in] == needle[in] && (ih + in) < len
		)
			++in;
		if (in == needle_len)
			return ((char *) haystack + ih);
		++ih;
	}
	return (NULL);
}
