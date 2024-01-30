/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/29 06:47:48 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/04/29 08:40:06 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The malloc(), calloc(), valloc(), realloc(), and reallocf() functions
** allocate memory. The allocated memory is aligned such that it can be used for
** any data type, including AltiVec- and SSE-related types.
**
** The malloc() function allocates size bytes of memory and returns a pointer to
** the allocated memory.
**
** If successful, calloc(), malloc(), realloc(), reallocf(), valloc(), and
** aligned_alloc() functions return a pointer to allocated memory. If there is
** an error, they return a NULL pointer and set errno to ENOMEM.
*/
void	*ft_calloc(size_t count, size_t size)
{
	size_t	size_res;
	void	*res;

	size_res = count * size;
	res = (void *) malloc(size_res);
	if (!res)
		return (NULL);
	ft_bzero(res, size_res);
	return (res);
}
