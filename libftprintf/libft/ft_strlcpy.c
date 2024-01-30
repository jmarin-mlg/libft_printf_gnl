/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 18:20:07 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/04 18:24:05 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strlcpy() and ft_strlcat() functions copy and concatenate strings with
** the same input parameters and output result as snprintf(3). They are designed
** to be safer, more consistent, and less error prone replacements for the easily
** misused functions ft_strncpy(3) and ft_strncat(3).
**
** ft_strlcpy() and ft_strlcat() take the full size of the destination buffer and
** guarantee NUL-termination if there is room. Note that room for the NUL should
** be included in dstsize.
**
** ft_strlcpy() copies up to dstsize - 1 characters from the string src to dst,
** NUL-terminating the result if dstsize is not 0.
**
** If the src and dst strings overlap, the behavior is undefined.
**
** Besides quibbles over the return type (size_t versus int) and signal handler
** safety (snprintf(3) is not entirely safe on some systems), the following two
** are equivalent:
**
**		n = ft_strlcpy(dst, src, len);
**		n = snprintf(dst, len, "%s", src);
**
** Like snprintf(3), the ft_strlcpy() and ft_strlcat() functions return the total
** length of the string they tried to create. For ft_strlcpy() that means the
** length of src.
**
** If the return value is >= dstsize, the output string has been truncated. It
** is the caller's responsibility to handle this.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	size_src;

	size_src = ft_strlen(src);
	if (!dstsize)
		return (size_src);
	i = 0;
	while (src[i] && i < (dstsize - 1))
	{
		dst[i] = src[i];
		++i;
	}
	dst[i] = '\0';
	return (size_src);
}
