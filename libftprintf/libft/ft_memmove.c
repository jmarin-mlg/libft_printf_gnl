/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:59:35 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/23 07:28:33 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function copies len bytes from string src to string dst. The two strings
** may overlap; the copy is always done in a non-destructive manner.
**
** The function returns the original value of dst.
*/
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if (dst > src)
		while (len-- > 0)
			*((char *) dst + len) = *((char *) src + len);
	else
		return (ft_memcpy(dst, src, len));
	return (dst);
}
