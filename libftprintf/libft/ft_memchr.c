/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmarin-o <jmarin-o@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 06:19:37 by jmarin-o          #+#    #+#             */
/*   Updated: 2023/05/01 08:31:03 by jmarin-o         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The function locates the first occurrence of c (converted to an unsigned
** char) in string s.
**
** The function returns a pointer to the byte located, or NULL if no such byte
** exists within n bytes.
*/
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*((unsigned char *) s + i) == (unsigned char) c)
			return ((void *) s + i);
		++i;
	}
	return (NULL);
}
