/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:23:23 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/11/23 07:24:50 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function copies n bytes from memory area src to memory area dst.
** If dst and src overlap, behavior is undefined.  Applications in which dst and
** src might overlap should use memmove(3) instead.
**
** The function returns the original value of dst.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (n == 0 || dst == src)
		return (dst);
	i = -1;
	while (++i < n)
		*((char *) dst + i) = *((char *) src + i);
	return (dst);
}
