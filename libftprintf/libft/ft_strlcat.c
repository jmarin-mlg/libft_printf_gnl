/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 07:40:30 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/23 07:30:00 by jmarin-o         ###   ########.fr       */
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
** ft_strlcat() appends string src to the end of dst. It will append at most
** dstsize - ft_strlen(dst) - 1 characters. It will then NUL-terminate, unless
** dstsize is 0 or the original dst string was longer than dstsize (in practice
** this should not happen as it means that either dstsize is incorrect or that
** dst is not a proper string).
**
** If the src and dst strings overlap, the behavior is undefined.
**
** Besides quibbles over the return type (size_t versus int) and signal handler
** safety (snprintf(3) is not entirely safe on some systems), the following two
** are equivalent:
**
** 		n = ft_strlcpy(dst, src, len);
** 		n = snprintf(dst, len, "%s", src);
**
** Like snprintf(3), the ft_strlcpy() and ft_strlcat() functions return the total
** length of the string they tried to create. For ft_strlcat() that means the
** initial length of dst plus the length of src.
**
** If the return value is >= dstsize, the output string has been truncated. It
** is the caller's responsibility to handle this.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	i;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	if (dstsize <= dst_len)
		return (dstsize + src_len);
	i = 0;
	while (src[i] && (dst_len + i + 1) < dstsize)
	{
		dst[dst_len + i] = src[i];
		++i;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
